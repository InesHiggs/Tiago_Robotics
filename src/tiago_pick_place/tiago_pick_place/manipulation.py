import time
from threading import Thread

import rclpy

from geometry_msgs.msg import PoseStamped
from pymoveit2 import MoveIt2
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.node import Node
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint

import math
from scipy.spatial.transform import Rotation
import numpy as np
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
END_EFFECTOR_NAME = "gripper_grasping_frame"
GROUP_NAME = "arm_torso"
TUCKED_JOINT_POSITIONS = [0.15, 0.20, -1.34, -0.20, 1.94, -1.57, 1.37, 0.0]

# Distance between the gripper and cube
# before the final grasping movement.
PREGRASP_DISTANCE = 0.16

def compute_grasp_orientation(cube_pose: PoseStamped):
    """Top-down orientation whose finger axis matches the cube's yaw."""
    q = cube_pose.pose.orientation
    R_marker = Rotation.from_quat([q.x, q.y, q.z, q.w]).as_matrix()

    # The marker's local x axis, flattened onto the horizontal plane.
    ref = R_marker[:, 0].copy()
    ref[2] = 0.0
    if np.linalg.norm(ref) < 1e-3:          # marker seen almost edge-on
        ref = R_marker[:, 1].copy()
        ref[2] = 0.0
    ref /= np.linalg.norm(ref)

    approach = np.array([0.0, 0.0, -1.0])   # straight down
    third = np.cross(approach, ref)

    R = np.column_stack([approach, ref, third])
    return Rotation.from_matrix(R).as_quat()

def compute_pregrasp_pose(cube_pose: PoseStamped) -> PoseStamped:
    pregrasp_pose = PoseStamped()
    pregrasp_pose.header = cube_pose.header

    pregrasp_pose.pose.position.x = cube_pose.pose.position.x
    pregrasp_pose.pose.position.y = cube_pose.pose.position.y
    pregrasp_pose.pose.position.z = (
        cube_pose.pose.position.z + PREGRASP_DISTANCE
    )

    qx, qy, qz, qw = compute_grasp_orientation(cube_pose)
    pregrasp_pose.pose.orientation.x = float(qx)
    pregrasp_pose.pose.orientation.y = float(qy)
    pregrasp_pose.pose.orientation.z = float(qz)
    pregrasp_pose.pose.orientation.w = float(qw)

    return pregrasp_pose

def compute_grasp_pose(cube_pose: PoseStamped) -> PoseStamped:
    pregrasp_pose = PoseStamped()
    pregrasp_pose.header = cube_pose.header

    pregrasp_pose.pose.position.x = cube_pose.pose.position.x
    pregrasp_pose.pose.position.y = cube_pose.pose.position.y
    pregrasp_pose.pose.position.z = (
        cube_pose.pose.position.z + 0.04
    )

    qx, qy, qz, qw = compute_grasp_orientation(cube_pose)
    pregrasp_pose.pose.orientation.x = float(qx)
    pregrasp_pose.pose.orientation.y = float(qy)
    pregrasp_pose.pose.orientation.z = float(qz)
    pregrasp_pose.pose.orientation.w = float(qw)

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

        self.gripper_pub = self.create_publisher(
            JointTrajectory,
            '/gripper_controller/joint_trajectory',
            10,
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

    def add_table(self, x, y, z, size=(1.2, 0.6, 0.8), frame_id='map'):
        self.moveit2.add_collision_box(
            id='pick_table',
            size=list(size),
            position=[x, y, z],
            quat_xyzw=[0.0, 0.0, 0.0, 1.0],
            frame_id=frame_id,
        )
        time.sleep(1.0)

    def set_gripper(self, position, seconds=2):
        traj = JointTrajectory()
        traj.joint_names = [
            'gripper_left_finger_joint',
            'gripper_right_finger_joint',
        ]
        point = JointTrajectoryPoint()
        point.positions = [position, position]
        point.time_from_start.sec = seconds
        traj.points = [point]
        self.gripper_pub.publish(traj)

    def move_to_pose(self, pose: PoseStamped):
        
        self.get_logger().info(
            'Moving arm to pre-grasp pose...'
        )

        p = pose.pose.position
        q = pose.pose.orientation

        self.get_logger().warn(
            f'MOVEIT TARGET: frame={pose.header.frame_id} '
            f'x={p.x:.3f}, y={p.y:.3f}, z={p.z:.3f} | '
            f'q=({q.x:.3f}, {q.y:.3f}, {q.z:.3f}, {q.w:.3f})'
        )

        self.moveit2.move_to_pose(
            position=[
                pose.pose.position.x,
                pose.pose.position.y,
                pose.pose.position.z,
            ],

            quat_xyzw=[
                pose.pose.orientation.x,
                pose.pose.orientation.y,
                pose.pose.orientation.z,
                pose.pose.orientation.w,
            ],

            frame_id=pose.header.frame_id,
        )

        ok = self.moveit2.wait_until_executed()
        if ok:
            self.get_logger().info('Movement finished.')
        else:
            self.get_logger().error('Movement FAILED.')
        return ok

    def tuck_arm(self) -> bool:

        
        self.get_logger().info('Tucking arm...')
        self.moveit2.move_to_configuration(TUCKED_JOINT_POSITIONS)
        ok = self.moveit2.wait_until_executed()
        if not ok:
            self.get_logger().error('Tuck FAILED')
        return ok