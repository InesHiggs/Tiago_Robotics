import rclpy

from action_msgs.msg import GoalStatus
from geometry_msgs.msg import PoseStamped, Twist

from tiago_autonomous_navigation.task_2_coordinator import (
    Task2Coordinator,
)
import time

from tiago_pick_place.manipulation import (
    ManipulationController,
    compute_pregrasp_pose,
    compute_grasp_pose,
)
# TEMPORARY — replace later with poses loaded from YAML
PICK_X = -0.38
PICK_Y = -3.65

PLACE_X = -6.57
PLACE_Y = -4.72

def go_to_location(nav, x, y, name):

    pose = nav._make_pose_stamped(x, y)

    nav.get_logger().info(
        f'Going to {name}: x={x:.2f}, y={y:.2f}'
    )

    if not nav.go_to_pose(pose):
        nav.get_logger().error(
            f'Could not send navigation goal to {name}.'
        )
        return False
    
    nav._wait_for_nav(ignore_detection=True)

    if nav.status == GoalStatus.STATUS_SUCCEEDED:
        nav.get_logger().info(
            f'Arrived at {name}!'
        )
        return True
    
    nav.get_logger().warn(
        f'Navigation to {name} ended with status {nav.status}.'
    )

    return False

def go_to_pick(nav):
    return go_to_location(
        nav,
        PICK_X,
        PICK_Y,
        'PICK',
    )


def go_to_place(nav):
    return go_to_location(
        nav,
        PLACE_X,
        PLACE_Y,
        'PLACE',
    )


def search_for_cube(nav, cube_id=63, timeout=50.0):
    """
    Returns:
        PoseStamped of the cube in base_footprint if detected.
        None if timeout is reached.
    """

    detected_pose = {'pose': None}

    cube_topic = f'/cube_{cube_id}_pose'

    def cube_callback(msg: PoseStamped):
        detected_pose['pose'] = msg
    
    cube_subscription = nav.create_subscription(
        PoseStamped,
        cube_topic,
        cube_callback,
        10,
    )

    #Lower the head to find the Arucos
    nav.lower_head(tilt=-0.75)

    cmd_vel_pub = nav.create_publisher(
        Twist,
        '/cmd_vel',
        10,
    )

    nav.get_logger().info(
        f'Searching for cube {cube_id} with a small circular motion...'
    )

    start_time = nav.get_clock().now()

    while(
        rclpy.ok()
        and detected_pose['pose'] is None
        and (nav.get_clock().now() - start_time).nanoseconds / 1e9 < timeout
    ):
        cmd = Twist()

        cmd.angular.z = 0.30

        cmd_vel_pub.publish(cmd)

        rclpy.spin_once(
            nav,
            timeout_sec=0.1,
        )
    
    stop = Twist()

    for _ in range(5):
        cmd_vel_pub.publish(stop)
        rclpy.spin_once(
            nav,
            timeout_sec=0.05,
        )
    
    time.sleep(2.0)

    detected_pose['pose'] = None
    for _ in range(40):
        rclpy.spin_once(nav, timeout_sec=0.1)
        if detected_pose['pose'] is not None:
            break
    
    cube_pose = detected_pose['pose']

    if cube_pose is None:
        nav.get_logger().warn(
            f'Cube {cube_id} was not detected.'
        )

        nav.destroy_subscription(cube_subscription)

        return None
    
    p = cube_pose.pose.position

    nav.get_logger().info(
        f'Cube {cube_id} detected! '
        f'x={p.x:.3f}, '
        f'y={p.y:.3f}, '
        f'z={p.z:.3f} '
        f'in {cube_pose.header.frame_id}'
    )

    nav.destroy_subscription(cube_subscription)

    return cube_pose

def main(args=None):
    rclpy.init(args=args)

    nav = Task2Coordinator()

    nav.waitUntilNav2Active()

    # Robot starts at a random position, so Task 3
    # still has to localize itself.
    if not nav._run_localization():
        nav.get_logger().error(
            'Task 3 could not localize TIAGo.'
        )

        nav.destroy_node()
        rclpy.shutdown()
        return

    nav.get_logger().info(
        'Task 3 localization complete.'
    )

    if not go_to_pick(nav):
        nav.get_logger().error(
            'Could not reach PICK.'
        )
        nav.destroy_node()
        rclpy.shutdown()
        return
    
    cube_63_pose = search_for_cube(
        nav,
        cube_id=63,
    )
    if cube_63_pose is None:
        nav.get_logger().error(
           'Cube 63 could not be found.'
        )
        return

    manipulator = ManipulationController()

    table_top = cube_63_pose.pose.position.z - 0.07
    table_height = 0.3

    manipulator.moveit2.add_collision_box(
        id='pick_table',
        size=[1.2, 0.6, table_height],
        position=[
            cube_63_pose.pose.position.x,
            cube_63_pose.pose.position.y,
            table_top - table_height / 2.0,
        ],
        quat_xyzw=[0.0, 0.0, 0.0, 1.0],
        frame_id=cube_63_pose.header.frame_id,
    )

    manipulator.moveit2.add_collision_box(
        id='cube_63',
        size=[0.07, 0.07, 0.07],
        position=[
            cube_63_pose.pose.position.x,
            cube_63_pose.pose.position.y,
            cube_63_pose.pose.position.z - 0.035,
        ],
        quat_xyzw=[0.0, 0.0, 0.0, 1.0],
        frame_id=cube_63_pose.header.frame_id,
    )
    time.sleep(1.0)

    pregrasp_pose = compute_pregrasp_pose(cube_63_pose)

    if not manipulator.move_to_pose(pregrasp_pose):
        manipulator.log_pose_report('PREGRASP-FAILED', pregrasp_pose, cube_63_pose)
        nav.get_logger().error(
            'PREGRASP FAILED — aborting grasp.'
        )
        return
    manipulator.log_pose_report('PREGRASP', pregrasp_pose, cube_63_pose)

    #Open the gripper
    manipulator.set_gripper(0.045)
    time.sleep(10)
    manipulator.log_pose_report('PREGRASP', pregrasp_pose, cube_63_pose)

    nav.get_logger().info(
        'Starting controlled final grasp approach.'
    )

    manipulator.moveit2.allow_collisions(
        'cube_63',
        True,
    )

    time.sleep(0.5)

    grasp_pose = compute_grasp_pose(cube_63_pose)

    if not manipulator.move_to_pose(
        grasp_pose,
        cartesian=True,
    ):
        nav.get_logger().error(
            'FINAL CARTESIAN GRASP DESCENT FAILED.'
        )
        manipulator.log_pose_report('GRASP', grasp_pose, cube_63_pose)
        return
    return

    # -------------------------------------------------------
    # 6. CLOSE GRIPPER
    # -------------------------------------------------------

    nav.get_logger().info(
        'Grasp depth reached. Closing gripper.'
    )

    manipulator.set_gripper(0.025)
    time.sleep(2.5)


    # -------------------------------------------------------
    # 7. ATTACH CUBE TO GRIPPER IN MOVEIT
    # -------------------------------------------------------

    manipulator.moveit2.attach_collision_object(
        id='cube_63',
        link_name='gripper_grasping_frame',
        touch_links=[
            'gripper_left_finger_link',
            'gripper_right_finger_link',
            'gripper_link',
            'gripper_grasping_frame',
        ],
    )

    time.sleep(0.5)


    # -------------------------------------------------------
    # 8. LIFT STRAIGHT UP BEFORE TUCKING
    # -------------------------------------------------------

    nav.get_logger().info(
        'Cube attached. Lifting vertically.'
    )

    lift_pose = compute_lift_pose(grasp_pose)

    if not manipulator.move_to_pose(
        lift_pose,
        cartesian=True,
    ):
        nav.get_logger().error(
            'LIFT FAILED — cube may still be held.'
        )

        manipulator.moveit2.max_velocity = old_velocity
        manipulator.moveit2.max_acceleration = old_acceleration

        return


    # Restore normal speed.
    manipulator.moveit2.max_velocity = old_velocity
    manipulator.moveit2.max_acceleration = old_acceleration


    # Cube is now clear of the table.
    # Restore normal collision checking.
    manipulator.moveit2.allow_collisions(
        'cube_63',
        False,
    )

    time.sleep(0.5)


    # -------------------------------------------------------
    # 9. TUCK ONLY AFTER CLEARING TABLE
    # -------------------------------------------------------

    if not manipulator.tuck_arm():
        nav.get_logger().error(
            'TUCK FAILED after grasp.'
        )
        return
    
    if not go_to_place(nav):
        nav.get_logger().error(
            'Could not reach PICK.'
        )
        nav.destroy_node()
        rclpy.shutdown()
        return
    



    rclpy.shutdown()

if __name__ == '__main__':
    main()