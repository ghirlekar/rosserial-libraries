#ifndef _ROS_lyap_control_controller_msg_h
#define _ROS_lyap_control_controller_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace lyap_control
{

  class controller_msg : public ros::Msg
  {
    public:
      float u[1];

    controller_msg():
      u()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 1; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->u[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 1; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->u[i]));
      }
     return offset;
    }

    const char * getType(){ return "lyap_control/controller_msg"; };
    const char * getMD5(){ return "3efcca795ec635cb2556c19e63619fa8"; };

  };

}
#endif