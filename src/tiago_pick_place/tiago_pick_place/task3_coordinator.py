import rclpy

from action_msgs.msg import GoalStatus
from geometry_msgs.msg import PoseStamped, Twist
import time

from tiago_autonomous_navigation.task_2_coordinator import (
    Task2Coordinator,
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

def search_for_cube(nav, cube_id=63, timeout=25.0):
    """
    Returns:
        PoseStamped of the cube in base_footprint if detected.
        None if timeout is reached.
    """

    detected_pose = {'pose': None}

    cube_topic = f'/cube_{cube_id}_pose'

    def cube_call_back(msg: PoseStamped):
        detected_pose['pose'] = msg
    
    subscription = nav.create_subscritption(
        PoseStamped,
        cube_topic,
        cube_callback,
        10,
    )

    cmd_vel_pub = nav.create_publisher(
        Twist,
        '/cmd_vel',
        10,
    )

    nav.get_logger().info(
        f'Searching for cube {cube_id} with a small circular motion...'
    )

    start_time = time.time()

    while(
        rclpy.ok()
        and detected_pose['pose'] is None
        and time.time() - start_time < timeout
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
    
    cube_pose = detected_pose['pose']

    if cube_pose is None:
        nav.get_logger().warn(
            f'Cube {cube_id} was not detected.'
        )

        nav.destroy_subscription(subscription)

        return None
    
    p = cube_pose.pose.position

    nav.get_logger().info(
        f'Cube {cube_id} detected! '
        f'x={p.x:.3f}, '
        f'y={p.y:.3f}, '
        f'z={p.z:.3f} '
        f'in {cube_pose.header.frame_id}'
    )

    nav.destroy_subscription(subscription)

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

    # TEMPORARY TEST:
    # Just drive to PICK.
    go_to_pick(nav)

    nav.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()