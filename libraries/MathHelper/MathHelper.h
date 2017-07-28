#ifndef MathHelper_h
#define MathHelper_h

#include "Arduino.h"

/*
Written by Gideon

Static class to be used for calculating the standard deviation anf new averages
in the sensor data class.
*/

class MathHelper
{
  public:
    static double newAverage(double average, double oldestVal, double newestVal, int capacity);
    static double stdDev(double average, double values[], int capcity);

  private:
    MathHelper(){}
};

#endif