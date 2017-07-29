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
  	//Calculates the new average based on the old average
  	template<typename T> 
  	static double stdDev(double average, T* values, int capacity);
  	//calculates the population standard deviation based on the data
  	template<typename T> 
    static double newAverage(double average, T oldestVal, T newestVal, int capacity);

  private:
    MathHelper(){}
};

#include "MathHelper.hxx"

#endif