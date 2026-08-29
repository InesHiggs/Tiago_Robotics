import time
from threading import Thread

import rclpy

from geometry_msgs.msg import PoseStamped
from pymoveit2 import MoveIt2
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.node import Node


# ----- TIAGo MoveIt configuration -----

JOINT_NAMES = [
    "torso_lift_joint",
    "arm_1_joint",
    "arm_2_joint",
    "arm_3_joint",
    "arm_4_joint",
    "arm_5_joint",
    "arm_6_joint",
    "arm_7_joint",
]

BASE_LINK_NAME = "base_footprint"
END_EFFECTOR_NAME = "arm_tool_link"
GROUP_NAME = "arm_torso"


# Distance between the gripper and cube
# before the final grasping movement.
PREGRASP_DISTANCE = 0.15

def compute_pregrasp_pose(cube_pose: PoseStamped) -> PoseStamped:
    pregrasp_pose = PoseStamped()

    # Use the same coordinate frame as the cube.
    pregrasp_pose.header = cube_pose.header

    # Stay 15 cm behind the cube.
    pregrasp_pose.pose.position.x = (
        cube_pose.pose.position.x - PREGRASP_DISTANCE
    )

    # Same lateral position.
    pregrasp_pose.pose.position.y = (
        cube_pose.pose.position.y
    )

    #Same height
    pregrasp_pose.pose.position.z = (
        cube_pose.pose.position.z
    )

    pregrasp_pose.pose.orientation.x = 0.691
    pregrasp_pose.pose.orientation.y = 0.022
    pregrasp_pose.pose.orientation.z = 0.723
    pregrasp_pose.pose.orientation.w = 0.019

    return pregrasp_pose


class ManipulationController(Node):
    def __init__(self):

        super().__init__(
            'manipulation_controller'
        )

        callback_group = (
            ReentrantCallbackGroup()
        )

        self.moveit2 = MoveIt2(
            node=self,
            joint_names=JOINT_NAMES,
            base_link_name=BASE_LINK_NAME,
            end_effector_name=END_EFFECTOR_NAME,
            group_name=GROUP_NAME,
            callback_group=callback_group,
        )

        self.moveit2.max_velocity = 0.3
        self.moveit2.max_acceleration = 0.3

        self._executor = (
            rclpy.executors.MultiThreadedExecutor(
                num_threads=2
            )
        )

        self._executor.add_node(self)

        self._executor_thread = Thread(
            target=self._executor.spin,
            daemon=True,
        )

        self._executor_thread.start()

    def move_to_pregrasp(self, pregrasp_pose: PoseStamped):
        
        self.get_logger().info(
            'Moving arm to pre-grasp pose...'
        )

        self.moveit2.move_to_pose(
            position=[
                pregrasp_pose.pose.position.x,
                pregrasp_pose.pose.position.y,
                pregrasp_pose.pose.position.z,
            ],

            quat_xyzw=[
                pregrasp_pose.pose.orientation.x,
                pregrasp_pose.pose.orientation.y,
                pregrasp_pose.pose.orientation.z,
                pregrasp_pose.pose.orientation.w,
            ],

            frame_id=pregrasp_pose.header.frame_id,
        )

        self.moveit2.wait_until_executed()

        self.get_logger().info(
            'Pre-grasp movement finished.'
        )