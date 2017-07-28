#ifndef SensorData_h
#define SensorData_h

#include "Arduino.h"

#define MAX_CAPACITY 25

template <class T> class SensorData
{
	public:
		T update(int index, T value);

	private:
		T* _data[MAX_CAPACITY];
		float _avg;
		float _std_deviation;
		int _index;
		bool _isThreatened;
		float _mostRecentValue;
};

template <class T> T SensorData<T>::update(int index, T value) {
	_data[index] = value;
	return value * 2;
}

#endif