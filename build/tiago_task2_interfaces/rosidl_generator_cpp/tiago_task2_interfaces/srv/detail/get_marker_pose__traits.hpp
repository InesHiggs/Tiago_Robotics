// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tiago_task2_interfaces:srv/GetMarkerPose.idl
// generated code does not contain a copyright notice

#ifndef TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__TRAITS_HPP_
#define TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tiago_task2_interfaces/srv/detail/get_marker_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose_in_camera_frame'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace tiago_task2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetMarkerPose_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: marker_id
  {
    out << "marker_id: ";
    rosidl_generator_traits::value_to_yaml(msg.marker_id, out);
    out << ", ";
  }

  // member: pose_in_camera_frame
  {
    out << "pose_in_camera_frame: ";
    to_flow_style_yaml(msg.pose_in_camera_frame, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetMarkerPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: marker_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "marker_id: ";
    rosidl_generator_traits::value_to_yaml(msg.marker_id, out);
    out << "\n";
  }

  // member: pose_in_camera_frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_in_camera_frame:\n";
    to_block_style_yaml(msg.pose_in_camera_frame, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetMarkerPose_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tiago_task2_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tiago_task2_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tiago_task2_interfaces::srv::GetMarkerPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  tiago_task2_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tiago_task2_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const tiago_task2_interfaces::srv::GetMarkerPose_Request & msg)
{
  return tiago_task2_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tiago_task2_interfaces::srv::GetMarkerPose_Request>()
{
  return "tiago_task2_interfaces::srv::GetMarkerPose_Request";
}

template<>
inline const char * name<tiago_task2_interfaces::srv::GetMarkerPose_Request>()
{
  return "tiago_task2_interfaces/srv/GetMarkerPose_Request";
}

template<>
struct has_fixed_size<tiago_task2_interfaces::srv::GetMarkerPose_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct has_bounded_size<tiago_task2_interfaces::srv::GetMarkerPose_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseStamped>::value> {};

template<>
struct is_message<tiago_task2_interfaces::srv::GetMarkerPose_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'pose_in_map_frame'
// already included above
// #include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"

namespace tiago_task2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GetMarkerPose_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: pose_in_map_frame
  {
    out << "pose_in_map_frame: ";
    to_flow_style_yaml(msg.pose_in_map_frame, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GetMarkerPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: pose_in_map_frame
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_in_map_frame:\n";
    to_block_style_yaml(msg.pose_in_map_frame, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GetMarkerPose_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace tiago_task2_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tiago_task2_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tiago_task2_interfaces::srv::GetMarkerPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  tiago_task2_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tiago_task2_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const tiago_task2_interfaces::srv::GetMarkerPose_Response & msg)
{
  return tiago_task2_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<tiago_task2_interfaces::srv::GetMarkerPose_Response>()
{
  return "tiago_task2_interfaces::srv::GetMarkerPose_Response";
}

template<>
inline const char * name<tiago_task2_interfaces::srv::GetMarkerPose_Response>()
{
  return "tiago_task2_interfaces/srv/GetMarkerPose_Response";
}

template<>
struct has_fixed_size<tiago_task2_interfaces::srv::GetMarkerPose_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tiago_task2_interfaces::srv::GetMarkerPose_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tiago_task2_interfaces::srv::GetMarkerPose_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<tiago_task2_interfaces::srv::GetMarkerPose>()
{
  return "tiago_task2_interfaces::srv::GetMarkerPose";
}

template<>
inline const char * name<tiago_task2_interfaces::srv::GetMarkerPose>()
{
  return "tiago_task2_interfaces/srv/GetMarkerPose";
}

template<>
struct has_fixed_size<tiago_task2_interfaces::srv::GetMarkerPose>
  : std::integral_constant<
    bool,
    has_fixed_size<tiago_task2_interfaces::srv::GetMarkerPose_Request>::value &&
    has_fixed_size<tiago_task2_interfaces::srv::GetMarkerPose_Response>::value
  >
{
};

template<>
struct has_bounded_size<tiago_task2_interfaces::srv::GetMarkerPose>
  : std::integral_constant<
    bool,
    has_bounded_size<tiago_task2_interfaces::srv::GetMarkerPose_Request>::value &&
    has_bounded_size<tiago_task2_interfaces::srv::GetMarkerPose_Response>::value
  >
{
};

template<>
struct is_service<tiago_task2_interfaces::srv::GetMarkerPose>
  : std::true_type
{
};

template<>
struct is_service_request<tiago_task2_interfaces::srv::GetMarkerPose_Request>
  : std::true_type
{
};

template<>
struct is_service_response<tiago_task2_interfaces::srv::GetMarkerPose_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__TRAITS_HPP_
