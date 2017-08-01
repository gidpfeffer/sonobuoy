#include <SensorManager.h>
#include <SensorData.h>

SensorManager<double>* manager = new SensorManager<double>();

void setup() {
  calibrateSensors();
}


void loop() {
  // put your main code here, to run repeatedly:

}

void calibrateSensors(){
  calibrateSensor0();
  calibrateSensor1();
  calibrateSensor2();
  calibrateSensor3();
}

void calibrateSensor0()
{
  
  SensorData<double>* sensor0 = manager -> getSensor(0);
  while(!sensor0 -> isCalibrated())
  {
    //SHOULD BE REPLACED WITH REAL SENSOR READ
    int someValue = 1.5;
    //
    
    sensor0 -> updateData(someValue);
    delay(1000);
  }
}

/**
 * Should be the same as void calibrateSensor0()
 * syntactically, but should update sensor1, not sensor0
 * and should use values read in by sensor 1, not 0
 */
void calibrateSensor1(){
  SensorData<double>* sensor1 = manager -> getSensor(1);
  /**
   * ...
   */
}


/**
 * Should be the same as void calibrateSensor0()
 * syntactically, but should update sensor2, not sensor0
 * and should use values read in by sensor 2, not 0
 */
void calibrateSensor2(){
  SensorData<double>* sensor2 = manager -> getSensor(2);
  /**
   * ...
   */
}


/**
 * Should be the same as void calibrateSensor0()
 * syntactically, but should update sensor3, not sensor0
 * and should use values read in by sensor 3, not 0
 */
void calibrateSensor3(){
  SensorData<double>* sensor3 = manager -> getSensor(3);
  /**
   * ...
   */
}

