#!/usr/bin/env python

import rospy
import rospkg
from std_msgs.msg import Header
from trajectory_msgs.msg import JointTrajectoryPoint, JointTrajectory
from gazebo_msgs.srv import SpawnModel
from geometry_msgs.msg import Pose, Point, Quaternion

rospy.init_node('cmd_publisher')
rospack = rospkg.RosPack()

def move_around():
    pub = rospy.Publisher('/arm_controller/command', JointTrajectory, queue_size=10)
    msg = JointTrajectory()
    msg.header = Header()
    msg.joint_names = ['arm_joint_1', 'arm_joint_2', 'arm_joint_3', 'hand_joint']
    # msg.joint_names = ['shoulder_pan_joint', 'shoulder_lift_joint', 'elbow_joint', 'wrist_1_joint', 'wrist_2_joint', 'wrist_3_joint']
    msg.points = [JointTrajectoryPoint()]
    msg.points[0].positions = [3.14, 0, 3.14, 3.14]
    # msg.points[0].positions = [0, -1, 0, 0, 0, 0]
    msg.points[0].time_from_start = rospy.Duration.from_sec(10)
    r = rospy.Rate(100)
    while not rospy.is_shutdown():
        pub.publish(msg)
        r.sleep()

def spawn_box(position):
    model_path = rospack.get_path('BeobotV3_robot_server') + '/models/box100/box100.sdf'
    spawn_proxy = rospy.ServiceProxy('/gazebo/spawn_sdf_model', SpawnModel, persistent=False)
    spawn_result = spawn_proxy(model_name='box100',
                                model_xml=open(model_path,'r').read(),
                                initial_pose=Pose(
                                    position=Point(
                                        position[0],
                                        position[1],
                                        position[2]
                                    ),
                                    orientation=Quaternion(0,0,0,1)
                                ),
                                reference_frame='world')

if __name__ == '__main__':
    spawn_box([0.2,0.2,0.2])
