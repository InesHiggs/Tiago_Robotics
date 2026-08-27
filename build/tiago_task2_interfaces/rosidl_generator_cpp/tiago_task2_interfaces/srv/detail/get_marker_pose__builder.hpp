// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tiago_task2_interfaces:srv/GetMarkerPose.idl
// generated code does not contain a copyright notice

#ifndef TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__BUILDER_HPP_
#define TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tiago_task2_interfaces/srv/detail/get_marker_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tiago_task2_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetMarkerPose_Request_pose_in_camera_frame
{
public:
  explicit Init_GetMarkerPose_Request_pose_in_camera_frame(::tiago_task2_interfaces::srv::GetMarkerPose_Request & msg)
  : msg_(msg)
  {}
  ::tiago_task2_interfaces::srv::GetMarkerPose_Request pose_in_camera_frame(::tiago_task2_interfaces::srv::GetMarkerPose_Request::_pose_in_camera_frame_type arg)
  {
    msg_.pose_in_camera_frame = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tiago_task2_interfaces::srv::GetMarkerPose_Request msg_;
};

class Init_GetMarkerPose_Request_marker_id
{
public:
  Init_GetMarkerPose_Request_marker_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetMarkerPose_Request_pose_in_camera_frame marker_id(::tiago_task2_interfaces::srv::GetMarkerPose_Request::_marker_id_type arg)
  {
    msg_.marker_id = std::move(arg);
    return Init_GetMarkerPose_Request_pose_in_camera_frame(msg_);
  }

private:
  ::tiago_task2_interfaces::srv::GetMarkerPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tiago_task2_interfaces::srv::GetMarkerPose_Request>()
{
  return tiago_task2_interfaces::srv::builder::Init_GetMarkerPose_Request_marker_id();
}

}  // namespace tiago_task2_interfaces


namespace tiago_task2_interfaces
{

namespace srv
{

namespace builder
{

class Init_GetMarkerPose_Response_pose_in_map_frame
{
public:
  explicit Init_GetMarkerPose_Response_pose_in_map_frame(::tiago_task2_interfaces::srv::GetMarkerPose_Response & msg)
  : msg_(msg)
  {}
  ::tiago_task2_interfaces::srv::GetMarkerPose_Response pose_in_map_frame(::tiago_task2_interfaces::srv::GetMarkerPose_Response::_pose_in_map_frame_type arg)
  {
    msg_.pose_in_map_frame = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tiago_task2_interfaces::srv::GetMarkerPose_Response msg_;
};

class Init_GetMarkerPose_Response_message
{
public:
  explicit Init_GetMarkerPose_Response_message(::tiago_task2_interfaces::srv::GetMarkerPose_Response & msg)
  : msg_(msg)
  {}
  Init_GetMarkerPose_Response_pose_in_map_frame message(::tiago_task2_interfaces::srv::GetMarkerPose_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_GetMarkerPose_Response_pose_in_map_frame(msg_);
  }

private:
  ::tiago_task2_interfaces::srv::GetMarkerPose_Response msg_;
};

class Init_GetMarkerPose_Response_success
{
public:
  Init_GetMarkerPose_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetMarkerPose_Response_message success(::tiago_task2_interfaces::srv::GetMarkerPose_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_GetMarkerPose_Response_message(msg_);
  }

private:
  ::tiago_task2_interfaces::srv::GetMarkerPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::tiago_task2_interfaces::srv::GetMarkerPose_Response>()
{
  return tiago_task2_interfaces::srv::builder::Init_GetMarkerPose_Response_success();
}

}  // namespace tiago_task2_interfaces

#endif  // TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__BUILDER_HPP_
