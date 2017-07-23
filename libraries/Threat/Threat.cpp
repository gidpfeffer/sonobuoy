#include "Arduino.h"
#include "Threat.h"

Threat::Threat(Sensor sensor, char* message)
{
  _sensor = sensor;
  _message = message;
}

Sensor Threat::getSensor(){
  return _sensor
}

const char* getMessage(){
  return _message;
}
