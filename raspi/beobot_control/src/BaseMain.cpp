#include <beobot_control/listener.h>



namespace beobot_control
{


/*
// Listen to the chatter/encoder readings
ExampleListener::ExampleListener(ros::NodeHandle nh)
{
  // Create a subscriber.
  // Name the topic, message queue, callback function with class name, and object containing callback function.
  
  /*
  // tick difference from the encoders
  _tickdiff = nh.subscribe("example", 10, &ExampleListener::messageCallback, this);

  // left velocity from the encoder
  _leftvel = nh.subscribe("example", 10, &ExampleListener::messageCallback, this);

  // right velocity from the encoders
  _rightvel = nh.subscribe("example", 10, &ExampleListener::messageCallback, this);

  _agent_vel = nh.subscribe("example", 10, &ExampleListener::messageCallback, this);
  // from agent's policy/planner
  _agent = nh.subscribe("example", 10, &ExampleListener::messageCallback, this);
  
  // from movebase
  _auto_vel = nh.subscribe("example", 10, &ExampleListener::messageCallback, this);

  
  sub_ = nh.subscribe("example", 10, &ExampleListener::messageCallback, this);

}



// Once you listen to the chatter/encoder readings do the callback
void ExampleListener::messageCallback(const beobot_control::NodeExampleData::ConstPtr &msg)
{
  // Note that these are only set to INFO so they will print to a terminal for example purposes.
  // Typically, they should be DEBUG.
  ROS_INFO("message is %s, a + b = %d", msg->message.c_str(), msg->a + msg->b);
}

*/

ExampleListener::ExampleListener(ros::NodeHandle nh)
{
  // Create a subscriber.
  // Name the topic, message queue, callback function with class name, and object containing callback function.
  sub_ = nh.subscribe("example", 10, &ExampleListener::messageCallback, this);
}

void ExampleListener::messageCallback(const beobot_control::NodeExampleData::ConstPtr &msg)
{
  // Note that these are only set to INFO so they will print to a terminal for example purposes.
  // Typically, they should be DEBUG.
  ROS_INFO("message is %s, a + b = %d", msg->message.c_str(), msg->a + msg->b);
}


//tick_diff
void ExampleListener::spinOnce(const beobot_control::NodeExampleData::ConstPtr &msg)
{

  // msg is not being used yet
  //translate dx and dr commands to left and right velocities

  value[THROTTLE] = pwmMap(period[THROTTLE], THROTTLE, 800, 2200);
  value[STEER] = pwmMap(period[STEER], STEER, 800, 2200);
  value[SCALETHROTTLE] = pwmMap(period[SCALETHROTTLE], SCALETHROTTLE, 800, 2200);
  value[SCALESTEER] = pwmMap(period[SCALESTEER], SCALESTEER, 800, 2200);
  value[BRAKE] = pwmMap(period[BRAKE], BRAKE, 800, 2200);
  value[SWITCH] = pwmMap(period[SWITCH], SWITCH, 800, 2200);

  
  if(!value[SWITCH])
    Driver.drive(0.0, 0.0);  //calls findspeeds
    
  else
    Driver.drive(value[HORIZONTAL], value[HORIZONTAL]);  //calls findspeeds
    
  Driver.update();   //which will call adjustPWM
}



//Callback for the pwm signal from RC
float ExampleTalker::pwmMap(volatile uint32_t prev, int gpio, float min, float max)
{
    int temp = (int)prev;
    value[gpio] = (((float)temp) - min)/(max-min);
    return value[gpio];
}


//Callback for the pwm signal from RC
void ExampleTalker::pwmCallback(int gpio, int level, uint32_t tick)
{
    if ( 1 == level )
        high_tick[gpio] = tick;

    else
    {
    if ( high_tick[gpio] )
       period[gpio] = tick - high_tick[gpio];
    }
}


}

