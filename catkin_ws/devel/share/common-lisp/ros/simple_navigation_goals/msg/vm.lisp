; Auto-generated. Do not edit!


(cl:in-package simple_navigation_goals-msg)


;//! \htmlinclude vm.msg.html

(cl:defclass <vm> (roslisp-msg-protocol:ros-message)
  ((vx
    :reader vx
    :initarg :vx
    :type cl:float
    :initform 0.0)
   (vy
    :reader vy
    :initarg :vy
    :type cl:float
    :initform 0.0)
   (w
    :reader w
    :initarg :w
    :type cl:float
    :initform 0.0))
)

(cl:defclass vm (<vm>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <vm>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'vm)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simple_navigation_goals-msg:<vm> is deprecated: use simple_navigation_goals-msg:vm instead.")))

(cl:ensure-generic-function 'vx-val :lambda-list '(m))
(cl:defmethod vx-val ((m <vm>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:vx-val is deprecated.  Use simple_navigation_goals-msg:vx instead.")
  (vx m))

(cl:ensure-generic-function 'vy-val :lambda-list '(m))
(cl:defmethod vy-val ((m <vm>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:vy-val is deprecated.  Use simple_navigation_goals-msg:vy instead.")
  (vy m))

(cl:ensure-generic-function 'w-val :lambda-list '(m))
(cl:defmethod w-val ((m <vm>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:w-val is deprecated.  Use simple_navigation_goals-msg:w instead.")
  (w m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <vm>) ostream)
  "Serializes a message object of type '<vm>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'vx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'vy))))
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <vm>) istream)
  "Deserializes a message object of type '<vm>"
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
    (cl:setf (cl:slot-value msg 'vy) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'w) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<vm>)))
  "Returns string type for a message object of type '<vm>"
  "simple_navigation_goals/vm")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'vm)))
  "Returns string type for a message object of type 'vm"
  "simple_navigation_goals/vm")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<vm>)))
  "Returns md5sum for a message object of type '<vm>"
  "f3691ef5f5de1a108d3f9cc106129c39")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'vm)))
  "Returns md5sum for a message object of type 'vm"
  "f3691ef5f5de1a108d3f9cc106129c39")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<vm>)))
  "Returns full string definition for message of type '<vm>"
  (cl:format cl:nil "float32 vx~%float32 vy~%float32 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'vm)))
  "Returns full string definition for message of type 'vm"
  (cl:format cl:nil "float32 vx~%float32 vy~%float32 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <vm>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <vm>))
  "Converts a ROS message object to a list"
  (cl:list 'vm
    (cl:cons ':vx (vx msg))
    (cl:cons ':vy (vy msg))
    (cl:cons ':w (w msg))
))
