
#include "SensorManager.h"
#include "Arduino.h"

//sets up the sensors with the default thresholds
template <class T> SensorManager<T>::SensorManager()
{
   for(int i = 0; i < NUM_SENSORS; i++)
   {
      _sensor_data_array[i] = new SensorData<T>(DEFAULT_THRESHOLD);
      _threat_incrementer[i] = 0;
   }
}

//deletes the allocated arrays
template <class T> SensorManager<T>::~SensorManager()
{
   delete [] _sensor_data_array;
   delete [] _threat_incrementer;
}

//returns a sensor or null if out of bounds
template <class T> SensorData<T>* SensorManager<T>::getSensor(int index)
{
   return (index < NUM_SENSORS && index >= 0) ? _sensor_data_array[index] : NULL;
}

//returns whether or not the sensor was set
template <class T> bool SensorManager<T>::setSensor(int index, SensorData<T>* sensor_data)
{
   if(index < NUM_SENSORS)
   {
      _sensor_data_array[index] = sensor_data;
      return true;
   }
   return false;
}

//returns whether or not the sensor was set
template <class T> int SensorManager<T>::incrementThreats()
{
   int num_reset = 0;
   for(int i = 0; i < NUM_SENSORS; i++)
   {
      //if threat incrementer isn't 0, start investigating
      if(_threat_incrementer[i] != 0)
      {
         //if the sensor is no longer threatened, set incrementer to 0
         if(!(_sensor_data_array[i] -> isThreatened()))
         {
            _threat_incrementer[i] = 0;
         }
         //otherwise, if the threshold is passed, reset the data
         else if(_threat_incrementer[i] >= RESET_STEPS)
         {
            _sensor_data_array[i] -> reset();
            num_reset++;
         }
         //otherwise, just increment the counter
         else
         {
            _threat_incrementer[i]++;
         }
      }
      //if sensor is threatened, start incrementing
      else if(_sensor_data_array[i] -> isThreatened())
      {
         _threat_incrementer[i] = 1;
      }
   }
   return num_reset;
}