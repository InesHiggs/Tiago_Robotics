// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from tiago_task2_interfaces:srv/GetMarkerPose.idl
// generated code does not contain a copyright notice
#include "tiago_task2_interfaces/srv/detail/get_marker_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `pose_in_camera_frame`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
tiago_task2_interfaces__srv__GetMarkerPose_Request__init(tiago_task2_interfaces__srv__GetMarkerPose_Request * msg)
{
  if (!msg) {
    return false;
  }
  // marker_id
  // pose_in_camera_frame
  if (!geometry_msgs__msg__PoseStamped__init(&msg->pose_in_camera_frame)) {
    tiago_task2_interfaces__srv__GetMarkerPose_Request__fini(msg);
    return false;
  }
  return true;
}

void
tiago_task2_interfaces__srv__GetMarkerPose_Request__fini(tiago_task2_interfaces__srv__GetMarkerPose_Request * msg)
{
  if (!msg) {
    return;
  }
  // marker_id
  // pose_in_camera_frame
  geometry_msgs__msg__PoseStamped__fini(&msg->pose_in_camera_frame);
}

bool
tiago_task2_interfaces__srv__GetMarkerPose_Request__are_equal(const tiago_task2_interfaces__srv__GetMarkerPose_Request * lhs, const tiago_task2_interfaces__srv__GetMarkerPose_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // marker_id
  if (lhs->marker_id != rhs->marker_id) {
    return false;
  }
  // pose_in_camera_frame
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->pose_in_camera_frame), &(rhs->pose_in_camera_frame)))
  {
    return false;
  }
  return true;
}

bool
tiago_task2_interfaces__srv__GetMarkerPose_Request__copy(
  const tiago_task2_interfaces__srv__GetMarkerPose_Request * input,
  tiago_task2_interfaces__srv__GetMarkerPose_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // marker_id
  output->marker_id = input->marker_id;
  // pose_in_camera_frame
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->pose_in_camera_frame), &(output->pose_in_camera_frame)))
  {
    return false;
  }
  return true;
}

tiago_task2_interfaces__srv__GetMarkerPose_Request *
tiago_task2_interfaces__srv__GetMarkerPose_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tiago_task2_interfaces__srv__GetMarkerPose_Request * msg = (tiago_task2_interfaces__srv__GetMarkerPose_Request *)allocator.allocate(sizeof(tiago_task2_interfaces__srv__GetMarkerPose_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tiago_task2_interfaces__srv__GetMarkerPose_Request));
  bool success = tiago_task2_interfaces__srv__GetMarkerPose_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tiago_task2_interfaces__srv__GetMarkerPose_Request__destroy(tiago_task2_interfaces__srv__GetMarkerPose_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tiago_task2_interfaces__srv__GetMarkerPose_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__init(tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tiago_task2_interfaces__srv__GetMarkerPose_Request * data = NULL;

  if (size) {
    data = (tiago_task2_interfaces__srv__GetMarkerPose_Request *)allocator.zero_allocate(size, sizeof(tiago_task2_interfaces__srv__GetMarkerPose_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tiago_task2_interfaces__srv__GetMarkerPose_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tiago_task2_interfaces__srv__GetMarkerPose_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__fini(tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tiago_task2_interfaces__srv__GetMarkerPose_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence *
tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * array = (tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence *)allocator.allocate(sizeof(tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__destroy(tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__are_equal(const tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * lhs, const tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tiago_task2_interfaces__srv__GetMarkerPose_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__copy(
  const tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * input,
  tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tiago_task2_interfaces__srv__GetMarkerPose_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tiago_task2_interfaces__srv__GetMarkerPose_Request * data =
      (tiago_task2_interfaces__srv__GetMarkerPose_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tiago_task2_interfaces__srv__GetMarkerPose_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tiago_task2_interfaces__srv__GetMarkerPose_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tiago_task2_interfaces__srv__GetMarkerPose_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose_in_map_frame`
// already included above
// #include "geometry_msgs/msg/detail/pose_stamped__functions.h"

bool
tiago_task2_interfaces__srv__GetMarkerPose_Response__init(tiago_task2_interfaces__srv__GetMarkerPose_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    tiago_task2_interfaces__srv__GetMarkerPose_Response__fini(msg);
    return false;
  }
  // pose_in_map_frame
  if (!geometry_msgs__msg__PoseStamped__init(&msg->pose_in_map_frame)) {
    tiago_task2_interfaces__srv__GetMarkerPose_Response__fini(msg);
    return false;
  }
  return true;
}

void
tiago_task2_interfaces__srv__GetMarkerPose_Response__fini(tiago_task2_interfaces__srv__GetMarkerPose_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // pose_in_map_frame
  geometry_msgs__msg__PoseStamped__fini(&msg->pose_in_map_frame);
}

bool
tiago_task2_interfaces__srv__GetMarkerPose_Response__are_equal(const tiago_task2_interfaces__srv__GetMarkerPose_Response * lhs, const tiago_task2_interfaces__srv__GetMarkerPose_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // pose_in_map_frame
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->pose_in_map_frame), &(rhs->pose_in_map_frame)))
  {
    return false;
  }
  return true;
}

bool
tiago_task2_interfaces__srv__GetMarkerPose_Response__copy(
  const tiago_task2_interfaces__srv__GetMarkerPose_Response * input,
  tiago_task2_interfaces__srv__GetMarkerPose_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // pose_in_map_frame
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->pose_in_map_frame), &(output->pose_in_map_frame)))
  {
    return false;
  }
  return true;
}

tiago_task2_interfaces__srv__GetMarkerPose_Response *
tiago_task2_interfaces__srv__GetMarkerPose_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tiago_task2_interfaces__srv__GetMarkerPose_Response * msg = (tiago_task2_interfaces__srv__GetMarkerPose_Response *)allocator.allocate(sizeof(tiago_task2_interfaces__srv__GetMarkerPose_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(tiago_task2_interfaces__srv__GetMarkerPose_Response));
  bool success = tiago_task2_interfaces__srv__GetMarkerPose_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
tiago_task2_interfaces__srv__GetMarkerPose_Response__destroy(tiago_task2_interfaces__srv__GetMarkerPose_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    tiago_task2_interfaces__srv__GetMarkerPose_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__init(tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tiago_task2_interfaces__srv__GetMarkerPose_Response * data = NULL;

  if (size) {
    data = (tiago_task2_interfaces__srv__GetMarkerPose_Response *)allocator.zero_allocate(size, sizeof(tiago_task2_interfaces__srv__GetMarkerPose_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = tiago_task2_interfaces__srv__GetMarkerPose_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        tiago_task2_interfaces__srv__GetMarkerPose_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__fini(tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      tiago_task2_interfaces__srv__GetMarkerPose_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence *
tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * array = (tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence *)allocator.allocate(sizeof(tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__destroy(tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__are_equal(const tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * lhs, const tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!tiago_task2_interfaces__srv__GetMarkerPose_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__copy(
  const tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * input,
  tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(tiago_task2_interfaces__srv__GetMarkerPose_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    tiago_task2_interfaces__srv__GetMarkerPose_Response * data =
      (tiago_task2_interfaces__srv__GetMarkerPose_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!tiago_task2_interfaces__srv__GetMarkerPose_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          tiago_task2_interfaces__srv__GetMarkerPose_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!tiago_task2_interfaces__srv__GetMarkerPose_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
