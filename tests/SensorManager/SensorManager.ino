#include <SensorManager.h>
#include <SensorData.h>

SensorManager<double>* manager = new SensorManager<double>();

void setup() {
  Serial.begin(9600);
  Serial.println("Starting");
  calibrateSensors();
  Serial.println("Done Calibrating");
  delay(100);
  Serial.println(manager -> getSensor(0) -> dataToString());
  Serial.println(manager -> getSensor(1) -> dataToString());
  //Any other initializations you need here...
  /**
   * Serial.begin(9600); for example
   */
}


void loop() {
  recalibrateWhereNecessary();
  updateValues();
  logThreats();
  incrementThreatCounters();

  /**
   * PROCESS NRF COMMANDS HERE IF APPLICABLE
   */
}

//pushes new values to the data
void updateValues(){
  manager -> getSensor(0) -> updateData(readSensor0());
  manager -> getSensor(1) -> updateData(readSensor1());
  manager -> getSensor(2) -> updateData(readSensor2());
  manager -> getSensor(3) -> updateData(readSensor3());
}

//logs threats that have not yet been logged
void logThreats(){
  if(manager -> getSensor(0) -> shouldBeLogged()){
    logSensor0();
    manager -> getSensor(0) -> setLogged();
  }
  if(manager -> getSensor(1) -> shouldBeLogged()){
    logSensor1();
    manager -> getSensor(1) -> setLogged();
  }
  if(manager -> getSensor(2) -> shouldBeLogged()){
    logSensor2();
    manager -> getSensor(2) -> setLogged();
  }
  if(manager -> getSensor(3) -> shouldBeLogged()){
    logSensor3();
    manager -> getSensor(3) -> setLogged();
  }
}

void incrementThreatCounters(){
  manager -> incrementThreats();
}

void recalibrateWhereNecessary(){
  if(!(manager -> getSensor(0) ->isCalibrated())){
    calibrateSensor0();
  }
  if(!(manager -> getSensor(1) ->isCalibrated())){
    calibrateSensor1();
  }
  if(!(manager -> getSensor(2) ->isCalibrated())){
    calibrateSensor2();
  }
  if(!(manager -> getSensor(3) ->isCalibrated())){
    calibrateSensor3();
  }
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
    sensor0 -> updateData(readSensor0());
    delay(100);
  }
}

/**
 * Should be the same as void calibrateSensor0()
 * syntactically, but should update sensor1, not sensor0
 * and should use values read in by sensor 1, not 0
 */
void calibrateSensor1(){
  SensorData<double>* sensor1 = manager -> getSensor(1);
  while(!sensor1 -> isCalibrated())
  { 
    sensor1 -> updateData(readSensor1());
    delay(100);
  }
}


/**
 * Should be the same as void calibrateSensor0()
 * syntactically, but should update sensor2, not sensor0
 * and should use values read in by sensor 2, not 0
 */
void calibrateSensor2(){
  SensorData<double>* sensor2 = manager -> getSensor(2);
  while(!sensor2 -> isCalibrated())
  { 
    sensor2 -> updateData(readSensor2());
    delay(100);
  }
}


/**
 * Should be the same as void calibrateSensor0()
 * syntactically, but should update sensor3, not sensor0
 * and should use values read in by sensor 3, not 0
 */
void calibrateSensor3(){
  SensorData<double>* sensor3 = manager -> getSensor(3);
  while(!sensor3 -> isCalibrated())
  { 
    sensor3 -> updateData(readSensor3());
    delay(100);
  }
}


//PLACE WHERE YOU SHOULD START IMPLEMENTING


/**
 * THIS IS WHERE YOU IMPLEMENT THE CODE FOR EACH SENSOR
 */
double readSensor0(){
  //for example, return the acceleromator value
  return 1;
}

double readSensor1(){
  return 2;
}

double readSensor2(){
  return 3;
}

double readSensor3(){
  return 4;
}



//IMPLEMENT CODE HERE TO LOG THE SENSOR

/*
 * Calls:
 * 
 * Average: manager -> getSensor(0) -> getAverage();
 * StdDev: manager -> getSensor(0) -> getStdDev();
 * Data as String: manager -> getSensor(0) -> dataToString();
 * Value That Caused Threat: manager -> getSensor(0) -> getThreatCausingVal();
 */
   
void logSensor0(){
  double average = manager -> getSensor(0) -> getAverage();
  double stdDev = manager -> getSensor(0) -> getStdDev();
  String dataStr = manager -> getSensor(0) -> dataToString();
  double threatVal = manager -> getSensor(0) -> getThreatCausingVal();

  /**
   * LOG SOMETHING HERE
   */
}

void logSensor1(){
  //same syntax as logSensor0()
}

void logSensor2(){
  //same syntax as logSensor0()
}

void logSensor3(){
  //same syntax as logSensor0()
}
