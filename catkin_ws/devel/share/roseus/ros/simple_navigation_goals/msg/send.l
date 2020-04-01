;; Auto-generated. Do not edit!


(when (boundp 'simple_navigation_goals::send)
  (if (not (find-package "SIMPLE_NAVIGATION_GOALS"))
    (make-package "SIMPLE_NAVIGATION_GOALS"))
  (shadow 'send (find-package "SIMPLE_NAVIGATION_GOALS")))
(unless (find-package "SIMPLE_NAVIGATION_GOALS::SEND")
  (make-package "SIMPLE_NAVIGATION_GOALS::SEND"))

(in-package "ROS")
;;//! \htmlinclude send.msg.html


(defclass simple_navigation_goals::send
  :super ros::object
  :slots (_time _age _RXlinear _RYlinear _Rangular _xpose _ypose _zAngle ))

(defmethod simple_navigation_goals::send
  (:init
   (&key
    ((:time __time) 0)
    ((:age __age) 0)
    ((:RXlinear __RXlinear) 0.0)
    ((:RYlinear __RYlinear) 0.0)
    ((:Rangular __Rangular) 0.0)
    ((:xpose __xpose) 0.0)
    ((:ypose __ypose) 0.0)
    ((:zAngle __zAngle) 0.0)
    )
   (send-super :init)
   (setq _time (round __time))
   (setq _age (round __age))
   (setq _RXlinear (float __RXlinear))
   (setq _RYlinear (float __RYlinear))
   (setq _Rangular (float __Rangular))
   (setq _xpose (float __xpose))
   (setq _ypose (float __ypose))
   (setq _zAngle (float __zAngle))
   self)
  (:time
   (&optional __time)
   (if __time (setq _time __time)) _time)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:RXlinear
   (&optional __RXlinear)
   (if __RXlinear (setq _RXlinear __RXlinear)) _RXlinear)
  (:RYlinear
   (&optional __RYlinear)
   (if __RYlinear (setq _RYlinear __RYlinear)) _RYlinear)
  (:Rangular
   (&optional __Rangular)
   (if __Rangular (setq _Rangular __Rangular)) _Rangular)
  (:xpose
   (&optional __xpose)
   (if __xpose (setq _xpose __xpose)) _xpose)
  (:ypose
   (&optional __ypose)
   (if __ypose (setq _ypose __ypose)) _ypose)
  (:zAngle
   (&optional __zAngle)
   (if __zAngle (setq _zAngle __zAngle)) _zAngle)
  (:serialization-length
   ()
   (+
    ;; uint32 _time
    4
    ;; uint8 _age
    1
    ;; float64 _RXlinear
    8
    ;; float64 _RYlinear
    8
    ;; float64 _Rangular
    8
    ;; float64 _xpose
    8
    ;; float64 _ypose
    8
    ;; float32 _zAngle
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _time
       (write-long _time s)
     ;; uint8 _age
       (write-byte _age s)
     ;; float64 _RXlinear
       (sys::poke _RXlinear (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _RYlinear
       (sys::poke _RYlinear (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _Rangular
       (sys::poke _Rangular (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _xpose
       (sys::poke _xpose (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ypose
       (sys::poke _ypose (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float32 _zAngle
       (sys::poke _zAngle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _time
     (setq _time (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8 _age
     (setq _age (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _RXlinear
     (setq _RXlinear (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _RYlinear
     (setq _RYlinear (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _Rangular
     (setq _Rangular (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _xpose
     (setq _xpose (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ypose
     (setq _ypose (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float32 _zAngle
     (setq _zAngle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get simple_navigation_goals::send :md5sum-) "a5f0e33b00a5cbe9ea65848687eaa24e")
(setf (get simple_navigation_goals::send :datatype-) "simple_navigation_goals/send")
(setf (get simple_navigation_goals::send :definition-)
      "uint32 time
uint8 age

float64 RXlinear
float64 RYlinear
float64 Rangular
float64 xpose
float64 ypose

float32 zAngle

")



(provide :simple_navigation_goals/send "a5f0e33b00a5cbe9ea65848687eaa24e")


