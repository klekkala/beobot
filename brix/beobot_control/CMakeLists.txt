cmake_minimum_required(VERSION 2.8.3)
project(beobot_control)

find_package(catkin REQUIRED COMPONENTS message_generation std_msgs)

add_message_files(FILES Motor.msg)

generate_messages(DEPENDENCIES std_msgs)

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

# do not wildcard install files since the root folder of the package will contain a debian folder for releasing
catkin_install_python(PROGRAMS
  beobot_motor
  beobot_motor.py
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
install(FILES
  README
  launch/beobot_motor.launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
