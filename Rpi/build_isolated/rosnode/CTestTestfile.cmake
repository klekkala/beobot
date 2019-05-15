# CMake generated Testfile for 
# Source directory: /home/pi/catkin_ws/src/src/ros_comm/rosnode
# Build directory: /home/pi/catkin_ws/src/build_isolated/rosnode
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_rosnode_rostest_test_rosnode.test "/home/pi/catkin_ws/src/build_isolated/rosnode/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/pi/catkin_ws/src/build_isolated/rosnode/test_results/rosnode/rostest-test_rosnode.xml" "--return-code" "/opt/ros/kinetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/pi/catkin_ws/src/src/ros_comm/rosnode --package=rosnode --results-filename test_rosnode.xml --results-base-dir \"/home/pi/catkin_ws/src/build_isolated/rosnode/test_results\" /home/pi/catkin_ws/src/src/ros_comm/rosnode/test/rosnode.test ")
subdirs("gtest")
