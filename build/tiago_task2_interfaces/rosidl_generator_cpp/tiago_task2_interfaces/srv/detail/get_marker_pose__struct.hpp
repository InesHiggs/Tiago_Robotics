// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tiago_task2_interfaces:srv/GetMarkerPose.idl
// generated code does not contain a copyright notice

#ifndef TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__STRUCT_HPP_
#define TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose_in_camera_frame'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tiago_task2_interfaces__srv__GetMarkerPose_Request __attribute__((deprecated))
#else
# define DEPRECATED__tiago_task2_interfaces__srv__GetMarkerPose_Request __declspec(deprecated)
#endif

namespace tiago_task2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetMarkerPose_Request_
{
  using Type = GetMarkerPose_Request_<ContainerAllocator>;

  explicit GetMarkerPose_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_in_camera_frame(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->marker_id = 0l;
    }
  }

  explicit GetMarkerPose_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_in_camera_frame(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->marker_id = 0l;
    }
  }

  // field types and members
  using _marker_id_type =
    int32_t;
  _marker_id_type marker_id;
  using _pose_in_camera_frame_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _pose_in_camera_frame_type pose_in_camera_frame;

  // setters for named parameter idiom
  Type & set__marker_id(
    const int32_t & _arg)
  {
    this->marker_id = _arg;
    return *this;
  }
  Type & set__pose_in_camera_frame(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose_in_camera_frame = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tiago_task2_interfaces::srv::GetMarkerPose_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const tiago_task2_interfaces::srv::GetMarkerPose_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tiago_task2_interfaces::srv::GetMarkerPose_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tiago_task2_interfaces::srv::GetMarkerPose_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tiago_task2_interfaces__srv__GetMarkerPose_Request
    std::shared_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tiago_task2_interfaces__srv__GetMarkerPose_Request
    std::shared_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetMarkerPose_Request_ & other) const
  {
    if (this->marker_id != other.marker_id) {
      return false;
    }
    if (this->pose_in_camera_frame != other.pose_in_camera_frame) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetMarkerPose_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetMarkerPose_Request_

// alias to use template instance with default allocator
using GetMarkerPose_Request =
  tiago_task2_interfaces::srv::GetMarkerPose_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tiago_task2_interfaces


// Include directives for member types
// Member 'pose_in_map_frame'
// already included above
// #include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__tiago_task2_interfaces__srv__GetMarkerPose_Response __attribute__((deprecated))
#else
# define DEPRECATED__tiago_task2_interfaces__srv__GetMarkerPose_Response __declspec(deprecated)
#endif

namespace tiago_task2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetMarkerPose_Response_
{
  using Type = GetMarkerPose_Response_<ContainerAllocator>;

  explicit GetMarkerPose_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose_in_map_frame(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit GetMarkerPose_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc),
    pose_in_map_frame(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _pose_in_map_frame_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _pose_in_map_frame_type pose_in_map_frame;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__pose_in_map_frame(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->pose_in_map_frame = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tiago_task2_interfaces::srv::GetMarkerPose_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const tiago_task2_interfaces::srv::GetMarkerPose_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tiago_task2_interfaces::srv::GetMarkerPose_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tiago_task2_interfaces::srv::GetMarkerPose_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tiago_task2_interfaces__srv__GetMarkerPose_Response
    std::shared_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tiago_task2_interfaces__srv__GetMarkerPose_Response
    std::shared_ptr<tiago_task2_interfaces::srv::GetMarkerPose_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetMarkerPose_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->pose_in_map_frame != other.pose_in_map_frame) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetMarkerPose_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetMarkerPose_Response_

// alias to use template instance with default allocator
using GetMarkerPose_Response =
  tiago_task2_interfaces::srv::GetMarkerPose_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace tiago_task2_interfaces

namespace tiago_task2_interfaces
{

namespace srv
{

struct GetMarkerPose
{
  using Request = tiago_task2_interfaces::srv::GetMarkerPose_Request;
  using Response = tiago_task2_interfaces::srv::GetMarkerPose_Response;
};

}  // namespace srv

}  // namespace tiago_task2_interfaces

#endif  // TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__STRUCT_HPP_
