// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from tiago_task2_interfaces:srv/GetMarkerPose.idl
// generated code does not contain a copyright notice

#ifndef TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__FUNCTIONS_H_
#define TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "tiago_task2_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "tiago_task2_interfaces/srv/detail/get_marker_pose__struct.h"

/// Initialize srv/GetMarkerPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tiago_task2_interfaces__srv__GetMarkerPose_Request
 * )) before or use
 * tiago_task2_interfaces__srv__GetMarkerPose_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
bool
tiago_task2_interfaces__srv__GetMarkerPose_Request__init(tiago_task2_interfaces__srv__GetMarkerPose_Request * msg);

/// Finalize srv/GetMarkerPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
void
tiago_task2_interfaces__srv__GetMarkerPose_Request__fini(tiago_task2_interfaces__srv__GetMarkerPose_Request * msg);

/// Create srv/GetMarkerPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tiago_task2_interfaces__srv__GetMarkerPose_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
tiago_task2_interfaces__srv__GetMarkerPose_Request *
tiago_task2_interfaces__srv__GetMarkerPose_Request__create();

/// Destroy srv/GetMarkerPose message.
/**
 * It calls
 * tiago_task2_interfaces__srv__GetMarkerPose_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
void
tiago_task2_interfaces__srv__GetMarkerPose_Request__destroy(tiago_task2_interfaces__srv__GetMarkerPose_Request * msg);

/// Check for srv/GetMarkerPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
bool
tiago_task2_interfaces__srv__GetMarkerPose_Request__are_equal(const tiago_task2_interfaces__srv__GetMarkerPose_Request * lhs, const tiago_task2_interfaces__srv__GetMarkerPose_Request * rhs);

/// Copy a srv/GetMarkerPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
bool
tiago_task2_interfaces__srv__GetMarkerPose_Request__copy(
  const tiago_task2_interfaces__srv__GetMarkerPose_Request * input,
  tiago_task2_interfaces__srv__GetMarkerPose_Request * output);

/// Initialize array of srv/GetMarkerPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * tiago_task2_interfaces__srv__GetMarkerPose_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
bool
tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__init(tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * array, size_t size);

/// Finalize array of srv/GetMarkerPose messages.
/**
 * It calls
 * tiago_task2_interfaces__srv__GetMarkerPose_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
void
tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__fini(tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * array);

/// Create array of srv/GetMarkerPose messages.
/**
 * It allocates the memory for the array and calls
 * tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence *
tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__create(size_t size);

/// Destroy array of srv/GetMarkerPose messages.
/**
 * It calls
 * tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
void
tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__destroy(tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * array);

/// Check for srv/GetMarkerPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
bool
tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__are_equal(const tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * lhs, const tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * rhs);

/// Copy an array of srv/GetMarkerPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
bool
tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence__copy(
  const tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * input,
  tiago_task2_interfaces__srv__GetMarkerPose_Request__Sequence * output);

/// Initialize srv/GetMarkerPose message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * tiago_task2_interfaces__srv__GetMarkerPose_Response
 * )) before or use
 * tiago_task2_interfaces__srv__GetMarkerPose_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
bool
tiago_task2_interfaces__srv__GetMarkerPose_Response__init(tiago_task2_interfaces__srv__GetMarkerPose_Response * msg);

/// Finalize srv/GetMarkerPose message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
void
tiago_task2_interfaces__srv__GetMarkerPose_Response__fini(tiago_task2_interfaces__srv__GetMarkerPose_Response * msg);

/// Create srv/GetMarkerPose message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * tiago_task2_interfaces__srv__GetMarkerPose_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
tiago_task2_interfaces__srv__GetMarkerPose_Response *
tiago_task2_interfaces__srv__GetMarkerPose_Response__create();

/// Destroy srv/GetMarkerPose message.
/**
 * It calls
 * tiago_task2_interfaces__srv__GetMarkerPose_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
void
tiago_task2_interfaces__srv__GetMarkerPose_Response__destroy(tiago_task2_interfaces__srv__GetMarkerPose_Response * msg);

/// Check for srv/GetMarkerPose message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
bool
tiago_task2_interfaces__srv__GetMarkerPose_Response__are_equal(const tiago_task2_interfaces__srv__GetMarkerPose_Response * lhs, const tiago_task2_interfaces__srv__GetMarkerPose_Response * rhs);

/// Copy a srv/GetMarkerPose message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
bool
tiago_task2_interfaces__srv__GetMarkerPose_Response__copy(
  const tiago_task2_interfaces__srv__GetMarkerPose_Response * input,
  tiago_task2_interfaces__srv__GetMarkerPose_Response * output);

/// Initialize array of srv/GetMarkerPose messages.
/**
 * It allocates the memory for the number of elements and calls
 * tiago_task2_interfaces__srv__GetMarkerPose_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
bool
tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__init(tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * array, size_t size);

/// Finalize array of srv/GetMarkerPose messages.
/**
 * It calls
 * tiago_task2_interfaces__srv__GetMarkerPose_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
void
tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__fini(tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * array);

/// Create array of srv/GetMarkerPose messages.
/**
 * It allocates the memory for the array and calls
 * tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence *
tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__create(size_t size);

/// Destroy array of srv/GetMarkerPose messages.
/**
 * It calls
 * tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
void
tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__destroy(tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * array);

/// Check for srv/GetMarkerPose message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
bool
tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__are_equal(const tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * lhs, const tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * rhs);

/// Copy an array of srv/GetMarkerPose messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_tiago_task2_interfaces
bool
tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence__copy(
  const tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * input,
  tiago_task2_interfaces__srv__GetMarkerPose_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TIAGO_TASK2_INTERFACES__SRV__DETAIL__GET_MARKER_POSE__FUNCTIONS_H_
