import rclpy

from rclpy.node import Node
from geometry_msgs.msg import PoseStamped

CUBE_1_ID = 63
CUBE_2_ID = 582

class CubeTracker(Node):
    def __init__(self):
        super().__init__('cube_tracker')

        self.create_subscription(
            PoseStamped,
            '/aruco_single_63/pose',
            self.cube_63_callback,
            10,
        )

        self.create_subscription(
            PoseStamped,
            '/aruco_single_582/pose',
            self.cube_582_callback,
            10,
        )

        self.get_logger().info(
            'CubeTracker started. Wainting for cuber 63 and 582'
        )

    def cube_63_callback(self, msg: PoseStamped):
        self.get_logger().info(
            f'Cube 63 detected! '
            f'x={msg.pose.position.x:.3f}, '
            f'y={msg.pose.position.y:.3f}, '
            f'z={msg.pose.position.z:.3f}'
        )

    def cube_582_callback(self, msg: PoseStamped):
        self.get_logger().info(
            f'Cube 582 detected! '
            f'x={msg.pose.position.x:.3f}, '
            f'y={msg.pose.position.y:.3f}, '
            f'z={msg.pose.position.z:.3f}'
        )

def main(args=None):
    rclpy.init(args=args)

    node = CubeTracker()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()