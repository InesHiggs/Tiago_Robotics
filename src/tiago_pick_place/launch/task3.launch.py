import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

from launch_ros.actions import Node


CAMERA_IMAGE_TOPIC = '/head_front_camera/rgb/image_raw'
CAMERA_INFO_TOPIC = '/head_front_camera/rgb/camera_info'

CAMERA_FRAME = 'head_front_camera_rgb_optical_frame'


def generate_launch_description():

    # ----------------------------------------------------------
    # 1. Start the TIAGo simulation in our exam world
    # ----------------------------------------------------------

    tiago_world = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory('tiago_exam'),
                'launch',
                'tiago_exam.launch.py',
            )
        ),
        launch_arguments={
            'world_name': 'group10',
            'use_sim_time': 'True',
        }.items(),
    )

    # ----------------------------------------------------------
    # 2. ArUco detector for cube 63
    # ----------------------------------------------------------

    aruco_63 = Node(
        package='aruco_ros',
        executable='single',
        name='aruco_single_63',

        output='screen',

        parameters=[{
            'image_is_rectified': True,
            'marker_id': 63,

            # Cube marker is 7 cm × 7 cm
            'marker_size': 0.07,

            'camera_frame': CAMERA_FRAME,
            'marker_frame': 'aruco_marker_63',

            # Leave pose expressed in camera frame for now.
            # cube_tracker will later perform the TF transform.
            'reference_frame': '',

            'corner_refinement': 'LINES',
            'use_sim_time': True,
        }],

        remappings=[
            ('/image', CAMERA_IMAGE_TOPIC),
            ('/camera_info', CAMERA_INFO_TOPIC),
        ],
    )

    # ----------------------------------------------------------
    # 3. ArUco detector for cube 582
    # ----------------------------------------------------------

    aruco_582 = Node(
        package='aruco_ros',
        executable='single',
        name='aruco_single_582',

        output='screen',

        parameters=[{
            'image_is_rectified': True,
            'marker_id': 582,
            'marker_size': 0.07,

            'camera_frame': CAMERA_FRAME,
            'marker_frame': 'aruco_marker_582',

            'reference_frame': '',
            'corner_refinement': 'LINES',
            'use_sim_time': True,
        }],

        remappings=[
            ('/image', CAMERA_IMAGE_TOPIC),
            ('/camera_info', CAMERA_INFO_TOPIC),
        ],
    )

    cube_tracker = Node(
        package='tiago_pick_place',
        executable='cube_tracker',
        name='cube_tracker',
        output='screen',
        parameters=[{'use_sim_time': True}],
    )

    return LaunchDescription([
        tiago_world,
        aruco_63,
        aruco_582,
        cube_tracker,
    ])