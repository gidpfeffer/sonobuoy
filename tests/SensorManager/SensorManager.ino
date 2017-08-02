#include <SensorManager.h>
#include <SensorData.h>

String DETECTED_STR = "Threat Detected: ";
String AVERAGE_STR = "Average: ";
String THREAT_VAL_STR = "Threat Val: ";
String CALIBRATING_STR = "Calibrating: ";
String DATA_STR = "Data: ";
String STD_DEV_STR = "Std Dev: ";
String START_STR = "Starting: ";
String DONE_SETUP_STR = "Done Calibrating";

/*
 * ms delay between reading the sensors when calibration
 * should be 1000 (1 second) or higher in my opinion
 */
#define CALIBRATION_DELAY 100

/*
 * ms delay between reading sensors in loop
 */
#define LOOP_DELAY 1000


/*
 * defines the number of loops a sensor will sit at
 * "threated" before being reset and recalibrated
 */
#define LOOPS_BETWEEN_RESETS 5

/**
 * Defines how many multiples of the standard deviation
 * are needed for a sensor value to be considered a threat
 * 
 * 2.0 = 95% of normal distribution
 */
#define THRESHOLD 1.0

//number of sensors in use
#define NUM_SENSORS 4

/**
 * amount of data point a sensor data will hold at one time. 
 * Should be maxed out in terms of space for string
 */
#define SENSOR_CAPACITY 30

SensorManager<double>* manager = new SensorManager<double>
  (LOOPS_BETWEEN_RESETS, THRESHOLD, NUM_SENSORS, SENSOR_CAPACITY);

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  Serial.println(START_STR);
  Serial.println();
  calibrateSensors();
  Serial.println(DONE_SETUP_STR);
  //Any other initializations you need here...
  /**
   * Setting pins ot output for example
   */
}


void loop() {
  recalibrateWhereNecessary();
  updateValues();
  logThreats();
  incrementThreatCounters();
  delay(LOOP_DELAY);
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
  Serial.print(CALIBRATING_STR);
  Serial.println(0);
  Serial.println();
  SensorData<double>* sensor0 = manager -> getSensor(0);
  while(!sensor0 -> isCalibrated())
  { 
    sensor0 -> updateData(readSensor0());
    delay(CALIBRATION_DELAY);
  }
}

/**
 * Should be the same as void calibrateSensor0()
 * syntactically, but should update sensor1, not sensor0
 * and should use values read in by sensor 1, not 0
 */
void calibrateSensor1(){
  Serial.print(CALIBRATING_STR);
  Serial.println(1);
  Serial.println();
  SensorData<double>* sensor1 = manager -> getSensor(1);
  while(!sensor1 -> isCalibrated())
  { 
    sensor1 -> updateData(readSensor1());
    delay(CALIBRATION_DELAY);
  }
}


/**
 * Should be the same as void calibrateSensor0()
 * syntactically, but should update sensor2, not sensor0
 * and should use values read in by sensor 2, not 0
 */
void calibrateSensor2(){
  Serial.print(CALIBRATING_STR);
  Serial.println(2);
  Serial.println();
  SensorData<double>* sensor2 = manager -> getSensor(2);
  while(!sensor2 -> isCalibrated())
  { 
    sensor2 -> updateData(readSensor2());
    delay(CALIBRATION_DELAY);
  }
}


/**
 * Should be the same as void calibrateSensor0()
 * syntactically, but should update sensor3, not sensor0
 * and should use values read in by sensor 3, not 0
 */
void calibrateSensor3(){
  Serial.print(CALIBRATING_STR);
  Serial.println(3);
  Serial.println();
  SensorData<double>* sensor3 = manager -> getSensor(3);
  while(!sensor3 -> isCalibrated())
  { 
    sensor3 -> updateData(readSensor3());
    delay(CALIBRATION_DELAY);
  }
}


//PLACE WHERE YOU SHOULD START IMPLEMENTING


/**
 * THIS IS WHERE YOU IMPLEMENT THE CODE FOR EACH SENSOR
 */
double readSensor0(){
  //for example, return the acceleromator value
  return random(1, 25);
}

double readSensor1(){
  return random(1, 10);
}

double readSensor2(){
  return random(1, 50);
}

double readSensor3(){
  return random(1, 15);
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
   Serial.print(DETECTED_STR);
   Serial.println(0);
   Serial.print(AVERAGE_STR);
   Serial.println(average);
   Serial.print(STD_DEV_STR);
   Serial.println(stdDev);
   Serial.print(THREAT_VAL_STR);
   Serial.println(threatVal);
   Serial.print(DATA_STR);
   Serial.println(dataStr);
   Serial.println();
}

void logSensor1(){
  double average = manager -> getSensor(1) -> getAverage();
  double stdDev = manager -> getSensor(1) -> getStdDev();
  String dataStr = manager -> getSensor(1) -> dataToString();
  double threatVal = manager -> getSensor(1) -> getThreatCausingVal();

  /**
   * LOG SOMETHING HERE
   */
   Serial.print(DETECTED_STR);
   Serial.println(1);
   Serial.print(AVERAGE_STR);
   Serial.println(average);
   Serial.print(STD_DEV_STR);
   Serial.println(stdDev);
   Serial.print(THREAT_VAL_STR);
   Serial.println(threatVal);
   Serial.print(DATA_STR);
   Serial.println(dataStr);
   Serial.println();
}

void logSensor2(){
  double average = manager -> getSensor(2) -> getAverage();
  double stdDev = manager -> getSensor(2) -> getStdDev();
  String dataStr = manager -> getSensor(2) -> dataToString();
  double threatVal = manager -> getSensor(2) -> getThreatCausingVal();

  /**
   * LOG SOMETHING HERE
   */
   Serial.print(DETECTED_STR);
   Serial.println(2);
   Serial.print(AVERAGE_STR);
   Serial.println(average);
   Serial.print(STD_DEV_STR);
   Serial.println(stdDev);
   Serial.print(THREAT_VAL_STR);
   Serial.println(threatVal);
   Serial.print(DATA_STR);
   Serial.println(dataStr);
   Serial.println();
}

void logSensor3(){
  double average = manager -> getSensor(3) -> getAverage();
  double stdDev = manager -> getSensor(3) -> getStdDev();
  String dataStr = manager -> getSensor(3) -> dataToString();
  double threatVal = manager -> getSensor(3) -> getThreatCausingVal();

  /**
   * LOG SOMETHING HERE
   */
   Serial.print(DETECTED_STR);
   Serial.println(3);
   Serial.print(AVERAGE_STR);
   Serial.println(average);
   Serial.print(STD_DEV_STR);
   Serial.println(stdDev);
   Serial.print(THREAT_VAL_STR);
   Serial.println(threatVal);
   Serial.print(DATA_STR);
   Serial.println(dataStr);
   Serial.println();
}
