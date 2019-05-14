#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""Example Python node to listen on a specific topic."""

# Import required Python code.
import rospy
import time

# Import custom message data.
from node_example.msg import NodeExampleData

dacl = Adafruit_MCP4725.MCP4725(address=0x61, busnum=1)
dacr = Adafruit_MCP4725.MCP4725(address=0x60, busnum=1)

def callback(data):
    """Handle subscriber data."""
    # Simply print out values in our custom message.
    dacl.setvoltage(data.a, True)
    dacr.setvoltage(data.b, True)
    rospy.loginfo("%s: I heard %s, a + b = %d", rospy.get_name(), data.message,
                  data.a + data.b)


def listener():
    """Configure subscriber."""
    # Create a subscriber with appropriate topic, custom message and name of
    # callback function.
    rospy.Subscriber('example', NodeExampleData, callback)


# Main function.
if __name__ == '__main__':
    # Initialize the node and name it.
    rospy.init_node('pylistener')
    # Go to the main loop.
    listener()
    # Wait for messages on topic, go to callback function when new messages
    # arrive.
    rospy.spin()
