import rclpy

from action_msgs.msg import GoalStatus

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