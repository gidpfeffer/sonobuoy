/*
Written by: Gideon Pfeffer

This class stored data and determines whether or not threats are caught. It has
API's to make storing, accessing, and interpreting data more straight forward.
*/

#ifndef SensorManager_h
#define SensorManager_h

#include "Arduino.h"
#include "SensorData.h"


//number of sensors that will be stored in the array
//wanted to avoid malloc'ing
#define NUM_SENSORS 4

//Threshold the sensor datas are initialized with
#define DEFAULT_THRESHOLD 2.0

//defines the number of steps a threat will be lock consecutively
//before being reset
#define RESET_STEPS 100

template <class T> class SensorManager
{
	public:
		SensorManager();
		~SensorManager();
		SensorData<T>* getSensor(int index);
		bool setSensor(int index, SensorData<T>* sensor_data);
		int incrementThreats();

	private:
		SensorData<T>* _sensor_data_array[NUM_SENSORS];
		int _threat_incrementer[NUM_SENSORS];
};

#include "SensorManager.hxx"

#endif