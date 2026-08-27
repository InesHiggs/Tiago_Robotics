// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tiago_task2_interfaces:srv/GetMarkerPose.idl
// generated code does not contain a copyright notice

#ifndef TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__STRUCT_H_
#define TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'pose_in_camera_frame'
#include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/GetMarkerPose in the package tiago_task2_interfaces.
typedef struct tiago_task2_interfaces__srv__GetMarkerPose_Request
{
  int32_t marker_id;
  geometry_msgs__msg__PoseStamped pose_in_camera_frame;
} tiago_task2_interfaces__srv__GetMarkerPose_Request;

// Struct for a sequence of tiago_task2_interfaces__srv__GetMarkerPose_Request.
typedef struct tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence
{
  tiago_task2_interfaces__srv__GetMarkerPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"
// Member 'pose_in_map_frame'
// already included above
// #include "geometry_msgs/msg/detail/pose_stamped__struct.h"

/// Struct defined in srv/GetMarkerPose in the package tiago_task2_interfaces.
typedef struct tiago_task2_interfaces__srv__GetMarkerPose_Response
{
  bool success;
  rosidl_runtime_c__String message;
  geometry_msgs__msg__PoseStamped pose_in_map_frame;
} tiago_task2_interfaces__srv__GetMarkerPose_Response;

// Struct for a sequence of tiago_task2_interfaces__srv__GetMarkerPose_Response.
typedef struct tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence
{
  tiago_task2_interfaces__srv__GetMarkerPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__STRUCT_H_
