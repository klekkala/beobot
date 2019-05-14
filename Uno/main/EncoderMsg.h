#ifndef _ROS_rosserial_arduino_Enc_h
#define _ROS_rosserial_arduino_Enc_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosserial_arduino
{

  class Enc : public ros::Msg
  {
    public:
      typedef uint16_t _encl_dist_type;
      _encl_dist_type encl_dist;
      typedef uint16_t _encr_dist_type;
      _encr_dist_type encr_dist;
      typedef uint16_t _encl_vel_type;
      _encl_vel_type encl_vel;
      typedef uint16_t _encr_vel_type;
      _encr_vel_type encr_vel;

    Enc():
      encl_dist(0),
      encr_dist(0),
      encl_vel(0),
      encr_vel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->encl_dist >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->encl_dist >> (8 * 1)) & 0xFF;
      offset += sizeof(this->encl_dist);
      *(outbuffer + offset + 0) = (this->encr_dist >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->encr_dist >> (8 * 1)) & 0xFF;
      offset += sizeof(this->encr_dist);
      *(outbuffer + offset + 0) = (this->encl_vel >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->encl_vel >> (8 * 1)) & 0xFF;
      offset += sizeof(this->encl_vel);
      *(outbuffer + offset + 0) = (this->encr_vel >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->encr_vel >> (8 * 1)) & 0xFF;
      offset += sizeof(this->encr_vel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->encl_dist =  ((uint16_t) (*(inbuffer + offset)));
      this->encl_dist |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->encl_dist);
      this->encr_dist =  ((uint16_t) (*(inbuffer + offset)));
      this->encr_dist |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->encr_dist);
      this->encl_vel =  ((uint16_t) (*(inbuffer + offset)));
      this->encl_vel |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->encl_vel);
      this->encr_vel =  ((uint16_t) (*(inbuffer + offset)));
      this->encr_vel |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->encr_vel);
     return offset;
    }

    const char * getType(){ return "rosserial_arduino/Enc"; };
    const char * getMD5(){ return "6d7853a614e2e821319068311f2af25b"; };

  };

}
#endif
