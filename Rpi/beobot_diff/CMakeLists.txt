cmake_minimum_required(VERSION 2.8.3)
project(beobot_diff)

find_package(catkin REQUIRED COMPONENTS message_generation std_msgs)


generate_messages(DEPENDENCIES std_msgs)

catkin_package(CATKIN_DEPENDS message_runtime std_msgs)

# do not wildcard install files since the root folder of the package will contain a debian folder for releasing
catkin_install_python(PROGRAMS
	scripts/diff_tf.py
	scripts/twist_to_motors.py
	scripts/wheel_loopback.py
 	scripts/pid_velocity.py
	scripts/virtual_joystick.py
	scripts/wheel_scaler.py
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
#install(FILES
#README
#launch/beobot_motor.launch
#DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
#)
