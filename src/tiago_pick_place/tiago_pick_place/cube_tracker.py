import rclpy

from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from tf2_ros import Buffer, TransformListener, TransformException
import tf2_geometry_msgs
import rclpy.duration

CUBE_1_ID = 63
CUBE_2_ID = 582

TARGET_FRAME = 'base_footprint'

class CubeTracker(Node):
    def __init__(self):
        super().__init__('cube_tracker')

        self.tf_buffer = Buffer()

        self.tf_listener = TransformListener(
            self.tf_buffer,
            self,
        )
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
        self.get_logger().info( #Camera POV
            f'Cube 63 detected! '
            f'x={msg.pose.position.x:.3f}, '
            f'y={msg.pose.position.y:.3f}, '
            f'z={msg.pose.position.z:.3f}'
        )
        self.transform_to_base(msg, CUBE_1_ID) #Robot POV

    def cube_582_callback(self, msg: PoseStamped):
        self.get_logger().info(#Camera POV
            f'Cube 582 detected! '
            f'x={msg.pose.position.x:.3f}, '
            f'y={msg.pose.position.y:.3f}, '
            f'z={msg.pose.position.z:.3f}'
        )
        self.transform_to_base(msg, CUBE_2_ID) #Robot POV
    
    def transform_to_base(self, msg: PoseStamped, cube_id: int):
        source_frame = msg.header.frame_id

        try:
            transform = self.tf_buffer.lookup_transform(
                TARGET_FRAME,
                source_frame,
                msg.header.stamp,
                timeout=rclpy.duration.Duration(seconds=1.0)
            )

            pose_base = tf2_geometry_msgs.do_transform_pose_stamped(
                msg,
                transform,
            )

            pose_base.header.frame_id = TARGET_FRAME

            p = pose_base.pose.position

            self.get_logger().info(
                f'Cube {cube_id} in {TARGET_FRAME}: '
                f'x={p.x:.3f}, '
                f'y={p.y:.3f}, '
                f'z={p.z:.3f}'
            )
            return pose_base
        
        except TransformException as exc:
            self.get_logger().warn(
                f'Could not transform cube {cube_id}: {exc}'
            )

            return None



def main(args=None):
    rclpy.init(args=args)

    node = CubeTracker()

    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()