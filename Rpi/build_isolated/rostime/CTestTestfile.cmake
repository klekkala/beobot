# CMake generated Testfile for 
# Source directory: /home/pi/catkin_ws/src/src/roscpp_core/rostime
# Build directory: /home/pi/catkin_ws/src/build_isolated/rostime
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_rostime_gtest_rostime-test_duration "/home/pi/catkin_ws/src/build_isolated/rostime/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/pi/catkin_ws/src/build_isolated/rostime/test_results/rostime/gtest-rostime-test_duration.xml" "--return-code" "/home/pi/catkin_ws/src/devel_isolated/rostime/lib/rostime/rostime-test_duration --gtest_output=xml:/home/pi/catkin_ws/src/build_isolated/rostime/test_results/rostime/gtest-rostime-test_duration.xml")
add_test(_ctest_rostime_gtest_rostime-test_time "/home/pi/catkin_ws/src/build_isolated/rostime/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/pi/catkin_ws/src/build_isolated/rostime/test_results/rostime/gtest-rostime-test_time.xml" "--return-code" "/home/pi/catkin_ws/src/devel_isolated/rostime/lib/rostime/rostime-test_time --gtest_output=xml:/home/pi/catkin_ws/src/build_isolated/rostime/test_results/rostime/gtest-rostime-test_time.xml")
subdirs("gtest")
