#ifndef Threat_h
#define Threat_h

#include "Arduino.h"


//if you want to add a new sensor enum, add it here
typedef enum Sensor{
  Temperature,
  Sonar,
  Accelerometer,
  NRF,
  LiquidLevel
};

class Threat
{
  public:
    Threat(Sensor sensor, const char* message);
    
    Sensor setSensor();
    const char* getMessage();

  private:
    const char* _message;
    Sensor _sensor;
};

#endif