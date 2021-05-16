#ifndef BEOBOT_CONTROL_LISTENER_H
#define BEOBOT_CONTROL_LISTENER_H

// ROS includes.
#include <ros/ros.h>
#include <ros/time.h>

// Custom message includes. Auto-generated from msg/ directory.
#include <beobot_control/NodeExampleData.h>

namespace beobot_control
{
class ExampleListener
{
 public:
  //! Constructor.
  explicit ExampleListener(ros::NodeHandle nh);

  //! Callback function for subscriber.
  void messageCallback(const beobot_control::NodeExampleData::ConstPtr &msg);

  // map function for pwm
  float pwmMap(volatile uint32_t period, int gpio, float min, float max);

  //! PWM callback for publishing message.
  void pwmCallback(int gpio, int level, uint32_t tick);

  static uint32_t high_tick[6];

  static volatile uint32_t period[6];
  
 private:
  //! Subscriber to custom message.
  ros::Subscriber sub_;

  float value[6];
};
}

#endif  // NODE_EXAMPLE_LISTENER_H
