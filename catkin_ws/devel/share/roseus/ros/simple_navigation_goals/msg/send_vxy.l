;; Auto-generated. Do not edit!


(when (boundp 'simple_navigation_goals::send_vxy)
  (if (not (find-package "SIMPLE_NAVIGATION_GOALS"))
    (make-package "SIMPLE_NAVIGATION_GOALS"))
  (shadow 'send_vxy (find-package "SIMPLE_NAVIGATION_GOALS")))
(unless (find-package "SIMPLE_NAVIGATION_GOALS::SEND_VXY")
  (make-package "SIMPLE_NAVIGATION_GOALS::SEND_VXY"))

(in-package "ROS")
;;//! \htmlinclude send_vxy.msg.html


(defclass simple_navigation_goals::send_vxy
  :super ros::object
  :slots (_vx _w ))

(defmethod simple_navigation_goals::send_vxy
  (:init
   (&key
    ((:vx __vx) 0.0)
    ((:w __w) 0.0)
    )
   (send-super :init)
   (setq _vx (float __vx))
   (setq _w (float __w))
   self)
  (:vx
   (&optional __vx)
   (if __vx (setq _vx __vx)) _vx)
  (:w
   (&optional __w)
   (if __w (setq _w __w)) _w)
  (:serialization-length
   ()
   (+
    ;; float32 _vx
    4
    ;; float32 _w
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _vx
       (sys::poke _vx (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _w
       (sys::poke _w (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _vx
     (setq _vx (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _w
     (setq _w (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get simple_navigation_goals::send_vxy :md5sum-) "fc29210c5d9bd7561216ea9dc938b8c6")
(setf (get simple_navigation_goals::send_vxy :datatype-) "simple_navigation_goals/send_vxy")
(setf (get simple_navigation_goals::send_vxy :definition-)
      "float32 vx
float32 w

")



(provide :simple_navigation_goals/send_vxy "fc29210c5d9bd7561216ea9dc938b8c6")


