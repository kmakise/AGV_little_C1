; Auto-generated. Do not edit!


(cl:in-package simple_navigation_goals-msg)


;//! \htmlinclude speed.msg.html

(cl:defclass <speed> (roslisp-msg-protocol:ros-message)
  ((stop
    :reader stop
    :initarg :stop
    :type cl:integer
    :initform 0))
)

(cl:defclass speed (<speed>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <speed>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'speed)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simple_navigation_goals-msg:<speed> is deprecated: use simple_navigation_goals-msg:speed instead.")))

(cl:ensure-generic-function 'stop-val :lambda-list '(m))
(cl:defmethod stop-val ((m <speed>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:stop-val is deprecated.  Use simple_navigation_goals-msg:stop instead.")
  (stop m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <speed>) ostream)
  "Serializes a message object of type '<speed>"
  (cl:let* ((signed (cl:slot-value msg 'stop)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <speed>) istream)
  "Deserializes a message object of type '<speed>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stop) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<speed>)))
  "Returns string type for a message object of type '<speed>"
  "simple_navigation_goals/speed")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'speed)))
  "Returns string type for a message object of type 'speed"
  "simple_navigation_goals/speed")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<speed>)))
  "Returns md5sum for a message object of type '<speed>"
  "e2327cd410f9df67fdb178d3542f8022")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'speed)))
  "Returns md5sum for a message object of type 'speed"
  "e2327cd410f9df67fdb178d3542f8022")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<speed>)))
  "Returns full string definition for message of type '<speed>"
  (cl:format cl:nil "int32 stop~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'speed)))
  "Returns full string definition for message of type 'speed"
  (cl:format cl:nil "int32 stop~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <speed>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <speed>))
  "Converts a ROS message object to a list"
  (cl:list 'speed
    (cl:cons ':stop (stop msg))
))
