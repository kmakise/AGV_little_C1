;; Auto-generated. Do not edit!


(when (boundp 'simple_navigation_goals::speed)
  (if (not (find-package "SIMPLE_NAVIGATION_GOALS"))
    (make-package "SIMPLE_NAVIGATION_GOALS"))
  (shadow 'speed (find-package "SIMPLE_NAVIGATION_GOALS")))
(unless (find-package "SIMPLE_NAVIGATION_GOALS::SPEED")
  (make-package "SIMPLE_NAVIGATION_GOALS::SPEED"))

(in-package "ROS")
;;//! \htmlinclude speed.msg.html


(defclass simple_navigation_goals::speed
  :super ros::object
  :slots (_stop ))

(defmethod simple_navigation_goals::speed
  (:init
   (&key
    ((:stop __stop) 0)
    )
   (send-super :init)
   (setq _stop (round __stop))
   self)
  (:stop
   (&optional __stop)
   (if __stop (setq _stop __stop)) _stop)
  (:serialization-length
   ()
   (+
    ;; int32 _stop
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _stop
       (write-long _stop s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _stop
     (setq _stop (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get simple_navigation_goals::speed :md5sum-) "e2327cd410f9df67fdb178d3542f8022")
(setf (get simple_navigation_goals::speed :datatype-) "simple_navigation_goals/speed")
(setf (get simple_navigation_goals::speed :definition-)
      "int32 stop

")



(provide :simple_navigation_goals/speed "e2327cd410f9df67fdb178d3542f8022")


