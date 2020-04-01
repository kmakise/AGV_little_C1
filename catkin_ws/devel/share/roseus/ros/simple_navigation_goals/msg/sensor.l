;; Auto-generated. Do not edit!


(when (boundp 'simple_navigation_goals::sensor)
  (if (not (find-package "SIMPLE_NAVIGATION_GOALS"))
    (make-package "SIMPLE_NAVIGATION_GOALS"))
  (shadow 'sensor (find-package "SIMPLE_NAVIGATION_GOALS")))
(unless (find-package "SIMPLE_NAVIGATION_GOALS::SENSOR")
  (make-package "SIMPLE_NAVIGATION_GOALS::SENSOR"))

(in-package "ROS")
;;//! \htmlinclude sensor.msg.html


(defclass simple_navigation_goals::sensor
  :super ros::object
  :slots (_IR0 _IR1 _USA _USB _USL _USR ))

(defmethod simple_navigation_goals::sensor
  (:init
   (&key
    ((:IR0 __IR0) 0)
    ((:IR1 __IR1) 0)
    ((:USA __USA) 0)
    ((:USB __USB) 0)
    ((:USL __USL) 0)
    ((:USR __USR) 0)
    )
   (send-super :init)
   (setq _IR0 (round __IR0))
   (setq _IR1 (round __IR1))
   (setq _USA (round __USA))
   (setq _USB (round __USB))
   (setq _USL (round __USL))
   (setq _USR (round __USR))
   self)
  (:IR0
   (&optional __IR0)
   (if __IR0 (setq _IR0 __IR0)) _IR0)
  (:IR1
   (&optional __IR1)
   (if __IR1 (setq _IR1 __IR1)) _IR1)
  (:USA
   (&optional __USA)
   (if __USA (setq _USA __USA)) _USA)
  (:USB
   (&optional __USB)
   (if __USB (setq _USB __USB)) _USB)
  (:USL
   (&optional __USL)
   (if __USL (setq _USL __USL)) _USL)
  (:USR
   (&optional __USR)
   (if __USR (setq _USR __USR)) _USR)
  (:serialization-length
   ()
   (+
    ;; int32 _IR0
    4
    ;; int32 _IR1
    4
    ;; int32 _USA
    4
    ;; int32 _USB
    4
    ;; int32 _USL
    4
    ;; int32 _USR
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _IR0
       (write-long _IR0 s)
     ;; int32 _IR1
       (write-long _IR1 s)
     ;; int32 _USA
       (write-long _USA s)
     ;; int32 _USB
       (write-long _USB s)
     ;; int32 _USL
       (write-long _USL s)
     ;; int32 _USR
       (write-long _USR s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _IR0
     (setq _IR0 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _IR1
     (setq _IR1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _USA
     (setq _USA (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _USB
     (setq _USB (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _USL
     (setq _USL (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _USR
     (setq _USR (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get simple_navigation_goals::sensor :md5sum-) "7b2fc253ad368634d89fd7b84900def5")
(setf (get simple_navigation_goals::sensor :datatype-) "simple_navigation_goals/sensor")
(setf (get simple_navigation_goals::sensor :definition-)
      "int32 IR0
int32 IR1
int32 USA
int32 USB
int32 USL
int32 USR

")



(provide :simple_navigation_goals/sensor "7b2fc253ad368634d89fd7b84900def5")


