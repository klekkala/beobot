# CMake generated Testfile for 
# Source directory: /home/pi/catkin_ws/src/src/ros_comm/rosmaster
# Build directory: /home/pi/catkin_ws/src/build_isolated/rosmaster
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_rosmaster_nosetests_test "/home/pi/catkin_ws/src/build_isolated/rosmaster/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/pi/catkin_ws/src/build_isolated/rosmaster/test_results/rosmaster/nosetests-test.xml" "--return-code" "/usr/bin/cmake -E make_directory /home/pi/catkin_ws/src/build_isolated/rosmaster/test_results/rosmaster" "/usr/bin/nosetests-2.7 -P --process-timeout=60 --where=/home/pi/catkin_ws/src/src/ros_comm/rosmaster/test --with-xunit --xunit-file=/home/pi/catkin_ws/src/build_isolated/rosmaster/test_results/rosmaster/nosetests-test.xml")
subdirs("gtest")
