# CMake generated Testfile for 
# Source directory: /home/pi/catkin_ws/src/src/rospack/test
# Build directory: /home/pi/catkin_ws/src/build_isolated/rospack/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_rospack_gtest_rospack-utest "/home/pi/catkin_ws/src/build_isolated/rospack/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/pi/catkin_ws/src/build_isolated/rospack/test_results/rospack/gtest-rospack-utest.xml" "--working-dir" "/home/pi/catkin_ws/src/build_isolated/rospack/test" "--return-code" "/home/pi/catkin_ws/src/devel_isolated/rospack/lib/rospack/rospack-utest --gtest_output=xml:/home/pi/catkin_ws/src/build_isolated/rospack/test_results/rospack/gtest-rospack-utest.xml")
add_test(_ctest_rospack_nosetests_test.test "/home/pi/catkin_ws/src/build_isolated/rospack/catkin_generated/env_cached.sh" "/usr/bin/python" "/opt/ros/kinetic/share/catkin/cmake/test/run_tests.py" "/home/pi/catkin_ws/src/build_isolated/rospack/test_results/rospack/nosetests-test.test.xml" "--working-dir" "/home/pi/catkin_ws/src/build_isolated/rospack/test/test" "--return-code" "/usr/bin/cmake -E make_directory /home/pi/catkin_ws/src/build_isolated/rospack/test_results/rospack" "/usr/bin/nosetests-2.7 -P --process-timeout=60 --where=/home/pi/catkin_ws/src/build_isolated/rospack/test/test --with-xunit --xunit-file=/home/pi/catkin_ws/src/build_isolated/rospack/test_results/rospack/nosetests-test.test.xml")
