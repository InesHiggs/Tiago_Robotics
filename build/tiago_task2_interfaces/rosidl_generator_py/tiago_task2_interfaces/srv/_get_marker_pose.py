# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tiago_task2_interfaces:srv/GetMarkerPose.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GetMarkerPose_Request(type):
    """Metaclass of message 'GetMarkerPose_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tiago_task2_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tiago_task2_interfaces.srv.GetMarkerPose_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_marker_pose__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_marker_pose__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_marker_pose__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_marker_pose__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_marker_pose__request

            from geometry_msgs.msg import PoseStamped
            if PoseStamped.__class__._TYPE_SUPPORT is None:
                PoseStamped.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetMarkerPose_Request(metaclass=Metaclass_GetMarkerPose_Request):
    """Message class 'GetMarkerPose_Request'."""

    __slots__ = [
        '_marker_id',
        '_pose_in_camera_frame',
    ]

    _fields_and_field_types = {
        'marker_id': 'int32',
        'pose_in_camera_frame': 'geometry_msgs/PoseStamped',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseStamped'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.marker_id = kwargs.get('marker_id', int())
        from geometry_msgs.msg import PoseStamped
        self.pose_in_camera_frame = kwargs.get('pose_in_camera_frame', PoseStamped())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.marker_id != other.marker_id:
            return False
        if self.pose_in_camera_frame != other.pose_in_camera_frame:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def marker_id(self):
        """Message field 'marker_id'."""
        return self._marker_id

    @marker_id.setter
    def marker_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'marker_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'marker_id' field must be an integer in [-2147483648, 2147483647]"
        self._marker_id = value

    @builtins.property
    def pose_in_camera_frame(self):
        """Message field 'pose_in_camera_frame'."""
        return self._pose_in_camera_frame

    @pose_in_camera_frame.setter
    def pose_in_camera_frame(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseStamped
            assert \
                isinstance(value, PoseStamped), \
                "The 'pose_in_camera_frame' field must be a sub message of type 'PoseStamped'"
        self._pose_in_camera_frame = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_GetMarkerPose_Response(type):
    """Metaclass of message 'GetMarkerPose_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tiago_task2_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tiago_task2_interfaces.srv.GetMarkerPose_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__get_marker_pose__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__get_marker_pose__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__get_marker_pose__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__get_marker_pose__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__get_marker_pose__response

            from geometry_msgs.msg import PoseStamped
            if PoseStamped.__class__._TYPE_SUPPORT is None:
                PoseStamped.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GetMarkerPose_Response(metaclass=Metaclass_GetMarkerPose_Response):
    """Message class 'GetMarkerPose_Response'."""

    __slots__ = [
        '_success',
        '_message',
        '_pose_in_map_frame',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
        'pose_in_map_frame': 'geometry_msgs/PoseStamped',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseStamped'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())
        from geometry_msgs.msg import PoseStamped
        self.pose_in_map_frame = kwargs.get('pose_in_map_frame', PoseStamped())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        if self.pose_in_map_frame != other.pose_in_map_frame:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @builtins.property
    def pose_in_map_frame(self):
        """Message field 'pose_in_map_frame'."""
        return self._pose_in_map_frame

    @pose_in_map_frame.setter
    def pose_in_map_frame(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseStamped
            assert \
                isinstance(value, PoseStamped), \
                "The 'pose_in_map_frame' field must be a sub message of type 'PoseStamped'"
        self._pose_in_map_frame = value


class Metaclass_GetMarkerPose(type):
    """Metaclass of service 'GetMarkerPose'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tiago_task2_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tiago_task2_interfaces.srv.GetMarkerPose')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__get_marker_pose

            from tiago_task2_interfaces.srv import _get_marker_pose
            if _get_marker_pose.Metaclass_GetMarkerPose_Request._TYPE_SUPPORT is None:
                _get_marker_pose.Metaclass_GetMarkerPose_Request.__import_type_support__()
            if _get_marker_pose.Metaclass_GetMarkerPose_Response._TYPE_SUPPORT is None:
                _get_marker_pose.Metaclass_GetMarkerPose_Response.__import_type_support__()


class GetMarkerPose(metaclass=Metaclass_GetMarkerPose):
    from tiago_task2_interfaces.srv._get_marker_pose import GetMarkerPose_Request as Request
    from tiago_task2_interfaces.srv._get_marker_pose import GetMarkerPose_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
