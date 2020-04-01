; Auto-generated. Do not edit!


(cl:in-package simple_navigation_goals-msg)


;//! \htmlinclude msg209.msg.html

(cl:defclass <msg209> (roslisp-msg-protocol:ros-message)
  ((time
    :reader time
    :initarg :time
    :type cl:integer
    :initform 0)
   (age
    :reader age
    :initarg :age
    :type cl:fixnum
    :initform 0)
   (RXlinear
    :reader RXlinear
    :initarg :RXlinear
    :type cl:float
    :initform 0.0)
   (RYlinear
    :reader RYlinear
    :initarg :RYlinear
    :type cl:float
    :initform 0.0)
   (Rangular
    :reader Rangular
    :initarg :Rangular
    :type cl:float
    :initform 0.0)
   (xpose
    :reader xpose
    :initarg :xpose
    :type cl:float
    :initform 0.0)
   (ypose
    :reader ypose
    :initarg :ypose
    :type cl:float
    :initform 0.0)
   (zAngle
    :reader zAngle
    :initarg :zAngle
    :type cl:float
    :initform 0.0))
)

(cl:defclass msg209 (<msg209>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <msg209>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'msg209)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name simple_navigation_goals-msg:<msg209> is deprecated: use simple_navigation_goals-msg:msg209 instead.")))

(cl:ensure-generic-function 'time-val :lambda-list '(m))
(cl:defmethod time-val ((m <msg209>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:time-val is deprecated.  Use simple_navigation_goals-msg:time instead.")
  (time m))

(cl:ensure-generic-function 'age-val :lambda-list '(m))
(cl:defmethod age-val ((m <msg209>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:age-val is deprecated.  Use simple_navigation_goals-msg:age instead.")
  (age m))

(cl:ensure-generic-function 'RXlinear-val :lambda-list '(m))
(cl:defmethod RXlinear-val ((m <msg209>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:RXlinear-val is deprecated.  Use simple_navigation_goals-msg:RXlinear instead.")
  (RXlinear m))

(cl:ensure-generic-function 'RYlinear-val :lambda-list '(m))
(cl:defmethod RYlinear-val ((m <msg209>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:RYlinear-val is deprecated.  Use simple_navigation_goals-msg:RYlinear instead.")
  (RYlinear m))

(cl:ensure-generic-function 'Rangular-val :lambda-list '(m))
(cl:defmethod Rangular-val ((m <msg209>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:Rangular-val is deprecated.  Use simple_navigation_goals-msg:Rangular instead.")
  (Rangular m))

(cl:ensure-generic-function 'xpose-val :lambda-list '(m))
(cl:defmethod xpose-val ((m <msg209>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:xpose-val is deprecated.  Use simple_navigation_goals-msg:xpose instead.")
  (xpose m))

(cl:ensure-generic-function 'ypose-val :lambda-list '(m))
(cl:defmethod ypose-val ((m <msg209>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:ypose-val is deprecated.  Use simple_navigation_goals-msg:ypose instead.")
  (ypose m))

(cl:ensure-generic-function 'zAngle-val :lambda-list '(m))
(cl:defmethod zAngle-val ((m <msg209>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader simple_navigation_goals-msg:zAngle-val is deprecated.  Use simple_navigation_goals-msg:zAngle instead.")
  (zAngle m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <msg209>) ostream)
  "Serializes a message object of type '<msg209>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'time)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'age)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'RXlinear))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'RYlinear))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Rangular))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'xpose))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ypose))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'zAngle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <msg209>) istream)
  "Deserializes a message object of type '<msg209>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'time)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'age)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'RXlinear) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'RYlinear) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Rangular) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'xpose) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ypose) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'zAngle) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<msg209>)))
  "Returns string type for a message object of type '<msg209>"
  "simple_navigation_goals/msg209")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'msg209)))
  "Returns string type for a message object of type 'msg209"
  "simple_navigation_goals/msg209")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<msg209>)))
  "Returns md5sum for a message object of type '<msg209>"
  "a5f0e33b00a5cbe9ea65848687eaa24e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'msg209)))
  "Returns md5sum for a message object of type 'msg209"
  "a5f0e33b00a5cbe9ea65848687eaa24e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<msg209>)))
  "Returns full string definition for message of type '<msg209>"
  (cl:format cl:nil "uint32 time~%uint8 age~%~%float64 RXlinear~%float64 RYlinear~%float64 Rangular~%float64 xpose~%float64 ypose~%~%float32 zAngle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'msg209)))
  "Returns full string definition for message of type 'msg209"
  (cl:format cl:nil "uint32 time~%uint8 age~%~%float64 RXlinear~%float64 RYlinear~%float64 Rangular~%float64 xpose~%float64 ypose~%~%float32 zAngle~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <msg209>))
  (cl:+ 0
     4
     1
     8
     8
     8
     8
     8
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <msg209>))
  "Converts a ROS message object to a list"
  (cl:list 'msg209
    (cl:cons ':time (time msg))
    (cl:cons ':age (age msg))
    (cl:cons ':RXlinear (RXlinear msg))
    (cl:cons ':RYlinear (RYlinear msg))
    (cl:cons ':Rangular (Rangular msg))
    (cl:cons ':xpose (xpose msg))
    (cl:cons ':ypose (ypose msg))
    (cl:cons ':zAngle (zAngle msg))
))
