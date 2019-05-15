# CMake generated Testfile for 
# Source directory: /home/pi/catkin_ws/src/src/ros_comm/rosmsg
# Build directory: /home/pi/catkin_ws/src/build_isolated/rosmsg
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_rosmsg_nosetests_test "/home/pi/catkin_ws/src/build_isolated/rosmsg/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/pi/catkin_ws/src/build_isolated/rosmsg/test_results/rosmsg/nosetests-test.xml" "--return-code" "/usr/bin/cmake -E make_directory /home/pi/catkin_ws/src/build_isolated/rosmsg/test_results/rosmsg" "/usr/bin/nosetests-2.7 -P --process-timeout=60 --where=/home/pi/catkin_ws/src/src/ros_comm/rosmsg/test --with-xunit --xunit-file=/home/pi/catkin_ws/src/build_isolated/rosmsg/test_results/rosmsg/nosetests-test.xml")
subdirs("gtest")
