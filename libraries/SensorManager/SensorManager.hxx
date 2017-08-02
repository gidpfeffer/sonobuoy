
#include "SensorManager.h"
#include "Arduino.h"

//sets up the sensors with the default thresholds
template <class T> SensorManager<T>::SensorManager(int resetSteps, double threshold, int numSensors, int capacity)
{
   _numSensors = numSensors;
   _sensorDataArray = new SensorData<T>*[_numSensors];
   _threatIncrementer = new int[_numSensors];
   for(int i = 0; i < _numSensors; i++)
   {
      _sensorDataArray[i] = new SensorData<T>(threshold, capacity);
      _threatIncrementer[i] = 0;
   }
   _resetSteps = resetSteps;
}

//deletes the allocated arrays
template <class T> SensorManager<T>::~SensorManager()
{
   delete [] _sensorDataArray;
   delete [] _threatIncrementer;
}

//returns a sensor or null if out of bounds
template <class T> SensorData<T>* SensorManager<T>::getSensor(int index)
{
   return (index < _numSensors && index >= 0) ? _sensorDataArray[index] : NULL;
}

//returns whether or not the sensor was set
template <class T> bool SensorManager<T>::setSensor(int index, SensorData<T>* sensor_data)
{
   if(index < _numSensors)
   {
      _sensorDataArray[index] = sensor_data;
      return true;
   }
   return false;
}

//returns whether or not the sensor was set
template <class T> int SensorManager<T>::incrementThreats()
{
   int num_reset = 0;
   for(int i = 0; i < _numSensors; i++)
   {
      //if threat incrementer isn't 0, start investigating
      if(_threatIncrementer[i] != 0)
      {
         //if the sensor is no longer threatened, set incrementer to 0
         if(!(_sensorDataArray[i] -> isThreatened()))
         {
            _threatIncrementer[i] = 0;
         }
         //otherwise, if the threshold is passed, reset the data
         else if(_threatIncrementer[i] >= _resetSteps)
         {
            _sensorDataArray[i] -> reset();
            _threatIncrementer[i] = 0;
            num_reset++;
         }
         //otherwise, just increment the counter
         else
         {
            _threatIncrementer[i]++;
         }
      }
      //if sensor is threatened, start incrementing
      else if(_sensorDataArray[i] -> isThreatened())
      {
         _threatIncrementer[i] = 1;
      }
   }
   return num_reset;
}