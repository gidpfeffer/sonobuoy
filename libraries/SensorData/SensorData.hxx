/*
Written by: Gideon Pfeffer

This class stored data and determines whether or not threats are caught. It has
API's to make storing, accessing, and interpreting data more straight forward.
*/

template <class T> SensorData<T>::SensorData(double threshold)
{
   reset();
   _threshold = threshold;
}

template <class T> void SensorData<T>::updateData(T value)
{
   //checks for threats if calibrated and not currently threatened
   if(_isCalibrated && !_isThreatened){
      _isThreatened = checkForThreats(value);
   }
   //updates the averages, std dev, and index if threats were not found in above call
	if(!_isThreatened){
		updateMetrics(value);
      _index = (_index + 1) % MAX_CAPACITY;
      if(_index == 0 && !_isCalibrated)
      {
         _isCalibrated = true;
      }
	}
}

//returns whether or not the data is calibrated
template <class T> bool SensorData<T>::isCalibrated()
{
	return _isCalibrated;
}

//checks for 95% probabilty given the data to determine if its a threat
template <class T> bool SensorData<T>::checkForThreats(T newValue)
{
   double diff = _stdDeviation * _threshold;
   return newValue > _average + diff || newValue < _average - diff;
}

//updates the average, the array value, and the standard deviation based on the new average
template <class T> void SensorData<T>::updateMetrics(T newValue)
{
   T oldValue = _data[_index];
   _data[_index] = newValue;
	double newAverage = updateAverage(newValue, oldValue);
	double newStdDev = updateStdDev(newAverage);
	_average = newAverage;
	_stdDeviation = newStdDev;
}

//calls the math helper to update the average
template <class T> double SensorData<T>::updateAverage(T newValue, T oldValue)
{
	return MathHelper::newAverage(_average, oldValue, newValue, MAX_CAPACITY);
}

//calls the math helper to update the standard deviation (population model)
template <class T> double SensorData<T>::updateStdDev(double newAverage)
{
	return MathHelper::stdDev(newAverage, _data, MAX_CAPACITY);
}

//returns whether or not the data is threatened
template <class T> bool SensorData<T>::isThreatened()
{
   return _isThreatened;
}

//returns the average
template <class T> double SensorData<T>::getAverage()
{
   return _average;
}

//returns the standard deviation
template <class T> double SensorData<T>::getStdDev()
{
   return _stdDeviation;
}

//returns a String version of the data held by the instance
template <class T> String SensorData<T>::dataToString()
{
   String str_data = "[";
   for(int i = 0; i < MAX_CAPACITY - 1; i++)
   {
      str_data = str_data + _data[i] + ",";
   }
   return str_data + _data[MAX_CAPACITY -1] + "]";
}

//resets all instance variables to their fresh values
template <class T> void SensorData<T>::reset()
{
   _isCalibrated = false;
   _isThreatened = false;
   _average = 0;
   _stdDeviation = 0;
   _index = 0;
   for(int i = 0; i < MAX_CAPACITY; i++)
   {
      _data[i] = 0;
   }
}