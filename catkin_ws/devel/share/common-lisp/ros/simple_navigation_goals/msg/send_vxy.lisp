; Auto-generated. Do not edit!


(cl:in-package simple_navigation_goals-msg)


;//! \htmlinclude send_vxy.msg.html

(cl:defclass <send_vxy> (roslisp-msg-protocol:ros-message)
  ((vx
    :reader vx
    :initarg :vx
    :type cl:float
    :initform 0.0)
   (w
    :reader w
    :initarg :w
    :type cl:float
    :initform 0.0))
)

(cl:defclass send_vxy (<send_vxy>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <send_vxy>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'send_vxy)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simple_navigation_goals-msg:<send_vxy> is deprecated: use simple_navigation_goals-msg:send_vxy instead.")))

(cl:ensure-generic-function 'vx-val :lambda-list '(m))
(cl:defmethod vx-val ((m <send_vxy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:vx-val is deprecated.  Use simple_navigation_goals-msg:vx instead.")
  (vx m))

(cl:ensure-generic-function 'w-val :lambda-list '(m))
(cl:defmethod w-val ((m <send_vxy>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:w-val is deprecated.  Use simple_navigation_goals-msg:w instead.")
  (w m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <send_vxy>) ostream)
  "Serializes a message object of type '<send_vxy>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'vx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'w))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <send_vxy>) istream)
  "Deserializes a message object of type '<send_vxy>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'vx) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'w) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<send_vxy>)))
  "Returns string type for a message object of type '<send_vxy>"
  "simple_navigation_goals/send_vxy")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'send_vxy)))
  "Returns string type for a message object of type 'send_vxy"
  "simple_navigation_goals/send_vxy")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<send_vxy>)))
  "Returns md5sum for a message object of type '<send_vxy>"
  "fc29210c5d9bd7561216ea9dc938b8c6")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'send_vxy)))
  "Returns md5sum for a message object of type 'send_vxy"
  "fc29210c5d9bd7561216ea9dc938b8c6")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<send_vxy>)))
  "Returns full string definition for message of type '<send_vxy>"
  (cl:format cl:nil "float32 vx~%float32 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'send_vxy)))
  "Returns full string definition for message of type 'send_vxy"
  (cl:format cl:nil "float32 vx~%float32 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <send_vxy>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <send_vxy>))
  "Converts a ROS message object to a list"
  (cl:list 'send_vxy
    (cl:cons ':vx (vx msg))
    (cl:cons ':w (w msg))
))
