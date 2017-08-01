template <typename T> 
double MathHelper::stdDev(double average, T* values, int capacity)
{
  double squaredDif = 0;
  for(int i = 0; i < capacity; i++)
  {
    squaredDif += sq(values[i] - average);
  }
  return sqrt((1.0/capacity) * squaredDif);
}

template <typename T> 
double MathHelper::newAverage(double average, T oldestVal, T newestVal, int capacity)
{
  return ((average * capacity) - oldestVal + newestVal)/capacity;
}
