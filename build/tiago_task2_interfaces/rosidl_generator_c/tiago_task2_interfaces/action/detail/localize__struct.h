// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tiago_task2_interfaces:action/Localize.idl
// generated code does not contain a copyright notice

#ifndef TIAGO_TASK2_INTERFACES__ACTION__DETAIL__LOCALIZE__STRUCT_H_
#define TIAGO_TASK2_INTERFACES__ACTION__DETAIL__LOCALIZE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Localize in the package tiago_task2_interfaces.
typedef struct tiago_task2_interfaces__action__Localize_Goal
{
  uint8_t structure_needs_at_least_one_member;
} tiago_task2_interfaces__action__Localize_Goal;

// Struct for a sequence of tiago_task2_interfaces__action__Localize_Goal.
typedef struct tiago_task2_interfaces__action__Localize_Goal__Sequence
{
  tiago_task2_interfaces__action__Localize_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tiago_task2_interfaces__action__Localize_Goal__Sequence;


// Constants defined in the message

/// Struct defined in action/Localize in the package tiago_task2_interfaces.
typedef struct tiago_task2_interfaces__action__Localize_Result
{
  bool success;
} tiago_task2_interfaces__action__Localize_Result;

// Struct for a sequence of tiago_task2_interfaces__action__Localize_Result.
typedef struct tiago_task2_interfaces__action__Localize_Result__Sequence
{
  tiago_task2_interfaces__action__Localize_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tiago_task2_interfaces__action__Localize_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/Localize in the package tiago_task2_interfaces.
typedef struct tiago_task2_interfaces__action__Localize_Feedback
{
  double current_covariance;
} tiago_task2_interfaces__action__Localize_Feedback;

// Struct for a sequence of tiago_task2_interfaces__action__Localize_Feedback.
typedef struct tiago_task2_interfaces__action__Localize_Feedback__Sequence
{
  tiago_task2_interfaces__action__Localize_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tiago_task2_interfaces__action__Localize_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "tiago_task2_interfaces/action/detail/localize__struct.h"

/// Struct defined in action/Localize in the package tiago_task2_interfaces.
typedef struct tiago_task2_interfaces__action__Localize_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  tiago_task2_interfaces__action__Localize_Goal goal;
} tiago_task2_interfaces__action__Localize_SendGoal_Request;

// Struct for a sequence of tiago_task2_interfaces__action__Localize_SendGoal_Request.
typedef struct tiago_task2_interfaces__action__Localize_SendGoal_Request__Sequence
{
  tiago_task2_interfaces__action__Localize_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tiago_task2_interfaces__action__Localize_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Localize in the package tiago_task2_interfaces.
typedef struct tiago_task2_interfaces__action__Localize_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} tiago_task2_interfaces__action__Localize_SendGoal_Response;

// Struct for a sequence of tiago_task2_interfaces__action__Localize_SendGoal_Response.
typedef struct tiago_task2_interfaces__action__Localize_SendGoal_Response__Sequence
{
  tiago_task2_interfaces__action__Localize_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tiago_task2_interfaces__action__Localize_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Localize in the package tiago_task2_interfaces.
typedef struct tiago_task2_interfaces__action__Localize_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} tiago_task2_interfaces__action__Localize_GetResult_Request;

// Struct for a sequence of tiago_task2_interfaces__action__Localize_GetResult_Request.
typedef struct tiago_task2_interfaces__action__Localize_GetResult_Request__Sequence
{
  tiago_task2_interfaces__action__Localize_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tiago_task2_interfaces__action__Localize_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "tiago_task2_interfaces/action/detail/localize__struct.h"

/// Struct defined in action/Localize in the package tiago_task2_interfaces.
typedef struct tiago_task2_interfaces__action__Localize_GetResult_Response
{
  int8_t status;
  tiago_task2_interfaces__action__Localize_Result result;
} tiago_task2_interfaces__action__Localize_GetResult_Response;

// Struct for a sequence of tiago_task2_interfaces__action__Localize_GetResult_Response.
typedef struct tiago_task2_interfaces__action__Localize_GetResult_Response__Sequence
{
  tiago_task2_interfaces__action__Localize_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tiago_task2_interfaces__action__Localize_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "tiago_task2_interfaces/action/detail/localize__struct.h"

/// Struct defined in action/Localize in the package tiago_task2_interfaces.
typedef struct tiago_task2_interfaces__action__Localize_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  tiago_task2_interfaces__action__Localize_Feedback feedback;
} tiago_task2_interfaces__action__Localize_FeedbackMessage;

// Struct for a sequence of tiago_task2_interfaces__action__Localize_FeedbackMessage.
typedef struct tiago_task2_interfaces__action__Localize_FeedbackMessage__Sequence
{
  tiago_task2_interfaces__action__Localize_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tiago_task2_interfaces__action__Localize_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TIAGO_TASK2_INTERFACES__ACTION__DETAIL__LOCALIZE__STRUCT_H_
