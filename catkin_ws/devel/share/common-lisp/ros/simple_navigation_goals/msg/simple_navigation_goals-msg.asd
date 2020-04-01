
(cl:in-package :asdf)

(defsystem "simple_navigation_goals-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "msg209" :depends-on ("_package_msg209"))
    (:file "_package_msg209" :depends-on ("_package"))
    (:file "send" :depends-on ("_package_send"))
    (:file "_package_send" :depends-on ("_package"))
    (:file "send_vxy" :depends-on ("_package_send_vxy"))
    (:file "_package_send_vxy" :depends-on ("_package"))
    (:file "sensor" :depends-on ("_package_sensor"))
    (:file "_package_sensor" :depends-on ("_package"))
    (:file "speed" :depends-on ("_package_speed"))
    (:file "_package_speed" :depends-on ("_package"))
    (:file "vm" :depends-on ("_package_vm"))
    (:file "_package_vm" :depends-on ("_package"))
  ))