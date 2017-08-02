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

template <class T> class SensorManager
{
	public:
		SensorManager(int resetSteps);
		~SensorManager();
		SensorData<T>* getSensor(int index);
		bool setSensor(int index, SensorData<T>* sensor_data);
		int incrementThreats();

	private:
		SensorData<T>* _sensorDataArray[NUM_SENSORS];
		int _threatIncrementer[NUM_SENSORS];
		int _resetSteps;
};

#include "SensorManager.hxx"

#endif