# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "simple_navigation_goals: 6 messages, 0 services")

set(MSG_I_FLAGS "-Isimple_navigation_goals:/home/kmakise/catkin_ws/src/simple_navigation_goals/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(simple_navigation_goals_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send.msg" NAME_WE)
add_custom_target(_simple_navigation_goals_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "simple_navigation_goals" "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send.msg" ""
)

get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/sensor.msg" NAME_WE)
add_custom_target(_simple_navigation_goals_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "simple_navigation_goals" "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/sensor.msg" ""
)

get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send_vxy.msg" NAME_WE)
add_custom_target(_simple_navigation_goals_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "simple_navigation_goals" "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send_vxy.msg" ""
)

get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/vm.msg" NAME_WE)
add_custom_target(_simple_navigation_goals_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "simple_navigation_goals" "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/vm.msg" ""
)

get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/msg209.msg" NAME_WE)
add_custom_target(_simple_navigation_goals_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "simple_navigation_goals" "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/msg209.msg" ""
)

get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/speed.msg" NAME_WE)
add_custom_target(_simple_navigation_goals_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "simple_navigation_goals" "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/speed.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_cpp(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/sensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_cpp(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send_vxy.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_cpp(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/vm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_cpp(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/msg209.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_cpp(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/speed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simple_navigation_goals
)

### Generating Services

### Generating Module File
_generate_module_cpp(simple_navigation_goals
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simple_navigation_goals
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(simple_navigation_goals_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(simple_navigation_goals_generate_messages simple_navigation_goals_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_cpp _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/sensor.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_cpp _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send_vxy.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_cpp _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/vm.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_cpp _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/msg209.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_cpp _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/speed.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_cpp _simple_navigation_goals_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(simple_navigation_goals_gencpp)
add_dependencies(simple_navigation_goals_gencpp simple_navigation_goals_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS simple_navigation_goals_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_eus(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/sensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_eus(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send_vxy.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_eus(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/vm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_eus(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/msg209.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_eus(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/speed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/simple_navigation_goals
)

### Generating Services

### Generating Module File
_generate_module_eus(simple_navigation_goals
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/simple_navigation_goals
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(simple_navigation_goals_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(simple_navigation_goals_generate_messages simple_navigation_goals_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_eus _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/sensor.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_eus _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send_vxy.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_eus _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/vm.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_eus _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/msg209.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_eus _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/speed.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_eus _simple_navigation_goals_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(simple_navigation_goals_geneus)
add_dependencies(simple_navigation_goals_geneus simple_navigation_goals_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS simple_navigation_goals_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_lisp(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/sensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_lisp(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send_vxy.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_lisp(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/vm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_lisp(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/msg209.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_lisp(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/speed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simple_navigation_goals
)

### Generating Services

### Generating Module File
_generate_module_lisp(simple_navigation_goals
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simple_navigation_goals
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(simple_navigation_goals_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(simple_navigation_goals_generate_messages simple_navigation_goals_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_lisp _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/sensor.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_lisp _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send_vxy.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_lisp _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/vm.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_lisp _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/msg209.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_lisp _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/speed.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_lisp _simple_navigation_goals_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(simple_navigation_goals_genlisp)
add_dependencies(simple_navigation_goals_genlisp simple_navigation_goals_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS simple_navigation_goals_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_nodejs(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/sensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_nodejs(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send_vxy.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_nodejs(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/vm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_nodejs(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/msg209.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_nodejs(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/speed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/simple_navigation_goals
)

### Generating Services

### Generating Module File
_generate_module_nodejs(simple_navigation_goals
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/simple_navigation_goals
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(simple_navigation_goals_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(simple_navigation_goals_generate_messages simple_navigation_goals_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_nodejs _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/sensor.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_nodejs _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send_vxy.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_nodejs _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/vm.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_nodejs _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/msg209.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_nodejs _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/speed.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_nodejs _simple_navigation_goals_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(simple_navigation_goals_gennodejs)
add_dependencies(simple_navigation_goals_gennodejs simple_navigation_goals_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS simple_navigation_goals_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_py(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/sensor.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_py(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send_vxy.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_py(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/vm.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_py(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/msg209.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simple_navigation_goals
)
_generate_msg_py(simple_navigation_goals
  "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/speed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simple_navigation_goals
)

### Generating Services

### Generating Module File
_generate_module_py(simple_navigation_goals
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simple_navigation_goals
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(simple_navigation_goals_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(simple_navigation_goals_generate_messages simple_navigation_goals_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_py _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/sensor.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_py _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/send_vxy.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_py _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/vm.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_py _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/msg209.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_py _simple_navigation_goals_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kmakise/catkin_ws/src/simple_navigation_goals/msg/speed.msg" NAME_WE)
add_dependencies(simple_navigation_goals_generate_messages_py _simple_navigation_goals_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(simple_navigation_goals_genpy)
add_dependencies(simple_navigation_goals_genpy simple_navigation_goals_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS simple_navigation_goals_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simple_navigation_goals)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/simple_navigation_goals
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(simple_navigation_goals_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/simple_navigation_goals)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/simple_navigation_goals
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(simple_navigation_goals_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simple_navigation_goals)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/simple_navigation_goals
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(simple_navigation_goals_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/simple_navigation_goals)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/simple_navigation_goals
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(simple_navigation_goals_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simple_navigation_goals)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simple_navigation_goals\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/simple_navigation_goals
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(simple_navigation_goals_generate_messages_py std_msgs_generate_messages_py)
endif()
