;; Auto-generated. Do not edit!


(when (boundp 'simple_navigation_goals::vm)
  (if (not (find-package "SIMPLE_NAVIGATION_GOALS"))
    (make-package "SIMPLE_NAVIGATION_GOALS"))
  (shadow 'vm (find-package "SIMPLE_NAVIGATION_GOALS")))
(unless (find-package "SIMPLE_NAVIGATION_GOALS::VM")
  (make-package "SIMPLE_NAVIGATION_GOALS::VM"))

(in-package "ROS")
;;//! \htmlinclude vm.msg.html


(defclass simple_navigation_goals::vm
  :super ros::object
  :slots (_vx _vy _w ))

(defmethod simple_navigation_goals::vm
  (:init
   (&key
    ((:vx __vx) 0.0)
    ((:vy __vy) 0.0)
    ((:w __w) 0.0)
    )
   (send-super :init)
   (setq _vx (float __vx))
   (setq _vy (float __vy))
   (setq _w (float __w))
   self)
  (:vx
   (&optional __vx)
   (if __vx (setq _vx __vx)) _vx)
  (:vy
   (&optional __vy)
   (if __vy (setq _vy __vy)) _vy)
  (:w
   (&optional __w)
   (if __w (setq _w __w)) _w)
  (:serialization-length
   ()
   (+
    ;; float32 _vx
    4
    ;; float32 _vy
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
     ;; float32 _vy
       (sys::poke _vy (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _w
       (sys::poke _w (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _vx
     (setq _vx (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _vy
     (setq _vy (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _w
     (setq _w (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get simple_navigation_goals::vm :md5sum-) "f3691ef5f5de1a108d3f9cc106129c39")
(setf (get simple_navigation_goals::vm :datatype-) "simple_navigation_goals/vm")
(setf (get simple_navigation_goals::vm :definition-)
      "float32 vx
float32 vy
float32 w

")



(provide :simple_navigation_goals/vm "f3691ef5f5de1a108d3f9cc106129c39")


