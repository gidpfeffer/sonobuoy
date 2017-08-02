/*
Written by: Gideon Pfeffer

This class stored data and determines whether or not threats are caught. It has
API's to make storing, accessing, and interpreting data more straight forward.
*/

#ifndef SensorManager_h
#define SensorManager_h

#include "Arduino.h"
#include "SensorData.h"

template <class T> class SensorManager
{
	public:
		SensorManager(int resetSteps, double threshold, int numSensors, int capacity);
		~SensorManager();
		SensorData<T>* getSensor(int index);
		bool setSensor(int index, SensorData<T>* sensor_data);
		int incrementThreats();

	private:
		SensorData<T>** _sensorDataArray;
		int* _threatIncrementer;
		int _resetSteps;
		int _numSensors;
};

#include "SensorManager.hxx"

#endif