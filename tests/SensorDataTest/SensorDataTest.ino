#include <SensorData.h>
#include <SensorData.h>

int counter = 1;
String restartingMsg = "restarting....";
String randNumStr = "rand num: ";
String initializedMsg = "Initialized data:";
String indicator = "not threatened by ";
String stoppingMsg = "STOPPING TEST";
String startMsg = "STARTING TEST";
String currentDataMsg = "Current Data: ";

/**
 * Edit this section to change the tester
 * 
 * Threshold signifies how many multiples
 * of the standard deviation
 * the data will accept before
 * deeming it a threat.
 * 
 * 1.65 = 90% sure it nots a threat based on normal distribution
 * 2.00 = 95% sure it nots a threat based on normal distribution
 */
double THRESHOLD = 2.0;
SensorData<double>* sd = new SensorData<double>(THRESHOLD);
/**
 * 
 */

 
void setup() {
  Serial.begin(9600);
  
  //Seed will change the random numbers generated
  randomSeed(analogRead(0));
  
  delay(1000);
  while(!(sd -> isCalibrated()))
  {
    sd -> updateData(counter);
    counter++;
  }
  Serial.println(initializedMsg);
  Serial.println(sd -> dataToString());
  Serial.println();
  Serial.println(startMsg);
  Serial.println();
}

void loop(){
  while(!(sd -> isThreatened()))
  {
    int randNum = random(1, 25);
    Serial.println(randNumStr + randNum);
    sd -> updateData(randNum);
    delay(500);
    if(sd -> isThreatened())
    {
      Serial.println(stoppingMsg);
      indicator = "threatened by ";
    }
    Serial.println(indicator + randNum);
    delay(500);
    Serial.print("Average: ");
    Serial.println(sd -> getAverage());
    delay(500);
    Serial.print("StdDev: ");
    Serial.println(sd -> getStdDev());
    delay(500);
    Serial.print(currentDataMsg);
    Serial.println(sd -> dataToString());
    if(!(sd -> isThreatened()))
    {
      Serial.println(restartingMsg);
    }
    Serial.println();
    delay(3000);
  }
}
