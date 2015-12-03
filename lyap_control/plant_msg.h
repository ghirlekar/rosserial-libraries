#ifndef _ROS_lyap_control_plant_msg_h
#define _ROS_lyap_control_plant_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace lyap_control
{

  class plant_msg : public ros::Msg
  {
    public:
      float x[1];
      float t;
      float setpoint[1];

    plant_msg():
      x(),
      t(0),
      setpoint()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint8_t i = 0; i < 1; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->x[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->t);
      for( uint8_t i = 0; i < 1; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->setpoint[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint8_t i = 0; i < 1; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x[i]));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->t));
      for( uint8_t i = 0; i < 1; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->setpoint[i]));
      }
     return offset;
    }

    const char * getType(){ return "lyap_control/plant_msg"; };
    const char * getMD5(){ return "ec8e5cab13b60dcd46bf2d4b11214b9d"; };

  };

}
#endif