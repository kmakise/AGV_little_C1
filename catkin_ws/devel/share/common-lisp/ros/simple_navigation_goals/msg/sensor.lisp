; Auto-generated. Do not edit!


(cl:in-package simple_navigation_goals-msg)


;//! \htmlinclude sensor.msg.html

(cl:defclass <sensor> (roslisp-msg-protocol:ros-message)
  ((IR0
    :reader IR0
    :initarg :IR0
    :type cl:integer
    :initform 0)
   (IR1
    :reader IR1
    :initarg :IR1
    :type cl:integer
    :initform 0)
   (USA
    :reader USA
    :initarg :USA
    :type cl:integer
    :initform 0)
   (USB
    :reader USB
    :initarg :USB
    :type cl:integer
    :initform 0)
   (USL
    :reader USL
    :initarg :USL
    :type cl:integer
    :initform 0)
   (USR
    :reader USR
    :initarg :USR
    :type cl:integer
    :initform 0))
)

(cl:defclass sensor (<sensor>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <sensor>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'sensor)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simple_navigation_goals-msg:<sensor> is deprecated: use simple_navigation_goals-msg:sensor instead.")))

(cl:ensure-generic-function 'IR0-val :lambda-list '(m))
(cl:defmethod IR0-val ((m <sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:IR0-val is deprecated.  Use simple_navigation_goals-msg:IR0 instead.")
  (IR0 m))

(cl:ensure-generic-function 'IR1-val :lambda-list '(m))
(cl:defmethod IR1-val ((m <sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:IR1-val is deprecated.  Use simple_navigation_goals-msg:IR1 instead.")
  (IR1 m))

(cl:ensure-generic-function 'USA-val :lambda-list '(m))
(cl:defmethod USA-val ((m <sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:USA-val is deprecated.  Use simple_navigation_goals-msg:USA instead.")
  (USA m))

(cl:ensure-generic-function 'USB-val :lambda-list '(m))
(cl:defmethod USB-val ((m <sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:USB-val is deprecated.  Use simple_navigation_goals-msg:USB instead.")
  (USB m))

(cl:ensure-generic-function 'USL-val :lambda-list '(m))
(cl:defmethod USL-val ((m <sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:USL-val is deprecated.  Use simple_navigation_goals-msg:USL instead.")
  (USL m))

(cl:ensure-generic-function 'USR-val :lambda-list '(m))
(cl:defmethod USR-val ((m <sensor>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:USR-val is deprecated.  Use simple_navigation_goals-msg:USR instead.")
  (USR m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <sensor>) ostream)
  "Serializes a message object of type '<sensor>"
  (cl:let* ((signed (cl:slot-value msg 'IR0)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'IR1)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'USA)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'USB)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'USL)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'USR)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <sensor>) istream)
  "Deserializes a message object of type '<sensor>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'IR0) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'IR1) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'USA) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'USB) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'USL) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'USR) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<sensor>)))
  "Returns string type for a message object of type '<sensor>"
  "simple_navigation_goals/sensor")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'sensor)))
  "Returns string type for a message object of type 'sensor"
  "simple_navigation_goals/sensor")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<sensor>)))
  "Returns md5sum for a message object of type '<sensor>"
  "7b2fc253ad368634d89fd7b84900def5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'sensor)))
  "Returns md5sum for a message object of type 'sensor"
  "7b2fc253ad368634d89fd7b84900def5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<sensor>)))
  "Returns full string definition for message of type '<sensor>"
  (cl:format cl:nil "int32 IR0~%int32 IR1~%int32 USA~%int32 USB~%int32 USL~%int32 USR~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'sensor)))
  "Returns full string definition for message of type 'sensor"
  (cl:format cl:nil "int32 IR0~%int32 IR1~%int32 USA~%int32 USB~%int32 USL~%int32 USR~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <sensor>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <sensor>))
  "Converts a ROS message object to a list"
  (cl:list 'sensor
    (cl:cons ':IR0 (IR0 msg))
    (cl:cons ':IR1 (IR1 msg))
    (cl:cons ':USA (USA msg))
    (cl:cons ':USB (USB msg))
    (cl:cons ':USL (USL msg))
    (cl:cons ':USR (USR msg))
))
