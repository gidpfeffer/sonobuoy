
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