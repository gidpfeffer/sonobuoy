/*
This class was written by Gideon

This class is inteded to be used to store a threat when one is detected.
It stores the sensor as an enum and the threat message as a String
*/

#include "Arduino.h"
#include "Threat.h"

Threat::Threat(Sensor sensor, String message)
{
  _sensor = sensor;
  _message = message;
}

Sensor Threat::getSensor()
{
  return _sensor;
}

String Threat::getMessage()
{
  return _message;
}