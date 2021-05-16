
#include <beobot_control/listener.h>
#include <beobot_control/Constants.h>
#include <beobot_control/Motor.h>
#include <beobot_control/DifferentialDrive.h>

/*
extern "C" {
  #include <beobot_control/DEV_Config.h>
}
*/
//COMMENTED!

#include <std_msgs/String.h>
#include <std_msgs/UInt8.h>


#include <stdlib.h>     //exit()
#include <signal.h>     //signal()
#include <time.h>
//#include <pigpio.h>
#include <string.h>

#include <stdio.h>
#include <inttypes.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>




int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "listener");

  // Initialize DAC
  //UDOUBLE i;
  //DEV_ModuleInit();

  // Exception handling:ctrl + c
  //signal(SIGINT, Handler);
  
  // Declare Left and Right Motors
  beobot_control::Motor LeftMotor(LH_REVERSE, LH_BRAKE, LH_PWM);
  beobot_control::Motor RightMotor(RH_REVERSE, RH_BRAKE, RH_PWM);
  beobot_control::DifferentialDrive Drive(&LeftMotor, &RightMotor, beobot_control::wheelCirc, beobot_control::wheelDist);

  printf("Program start\r\n");
  
  /*
  // Set states for the relay switches
  gpioWrite(LH_BRAKE, 1);
  gpioWrite(LH_REVERSE, 1);
  gpioWrite(RH_BRAKE, 1);
  gpioWrite(RH_REVERSE, 1);


  //RC declarations
  gpioSetMode(THROTTLE, INPUT);
  gpioSetMode(STEER, INPUT);
  gpioSetMode(THROTTLESCALE, INPUT);
  gpioSetMode(STEERSCALE, INPUT);
  gpioSetMode(BRAKE, INPUT);
  gpioSetMode(SWITCH, INPUT);

  //Link callback function
  gpioSetAlertFunc(VERTICAL, pwmCallback);
  gpioSetAlertFunc(HORIZONTAL, pwmCallback);
  gpioSetAlertFunc(SWITCH, pwmCallback);
  gpioSetAlertFunc(HORIZONTAL, pwmCallback);
  gpioSetAlertFunc(SWITCH, pwmCallback);
  */
  //COMMENTED!

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   */
  //ros::NodeHandle n;

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages
   * on a given topic.  This invokes a call to the ROS
   * std_msgs::UInt8 lticks_m;
   * std_msgs::UInt8 rticks_m;
   * ros::Publisher lencoder("lenc", &lticks_m);
   * ros::Publisher rencoder("renc", &rticks_m);
   */
  //ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);


  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();




  return 0;
}

