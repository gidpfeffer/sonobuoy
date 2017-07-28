#include "Arduino.h"
#include "MathHelper.h"

double MathHelper::newAverage(double average, double oldestVal, double newestVal, int capacity)
{
  return ((average * capacity) - oldestVal + newestVal)/capacity;
}

double MathHelper::stdDev(double average, double values[], int capacity)
{
  double squaredDif = 0;
  for(int i = 0; i < capacity; i++)
  {
    squaredDif += sq(values[i] - average);
  }
  return sqrt((1.0/capacity) * squaredDif);
}