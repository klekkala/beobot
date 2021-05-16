cmake_minimum_required(VERSION 3.0.2)
project(beobot_control)

find_package(catkin REQUIRED COMPONENTS dynamic_reconfigure message_generation roscpp rosgraph_msgs rospy std_msgs)

SET(GCC_COVERAGE_LINK_FLAGS    "-lgcov")

add_message_files(
  FILES
  NodeExampleData.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

generate_dynamic_reconfigure_options(
  cfg/beobotControl.cfg
)

catkin_package(
  CATKIN_DEPENDS dynamic_reconfigure message_runtime roscpp rosgraph_msgs rospy std_msgs
)

add_compile_options(-lbcm2835 -lm -lpigpio -lpthread)


include_directories(include ${catkin_INCLUDE_DIRS})


add_executable(base src/BaseMain.cpp src/nodes/base_node.cpp)
target_link_libraries(base ${catkin_LIBRARIES})
add_dependencies(base beobot_control_gencfg beobot_control_generate_messages_cpp)



install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)


install(TARGETS base talker
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

