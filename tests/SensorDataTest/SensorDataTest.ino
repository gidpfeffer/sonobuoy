#include <SensorData.h>
#include <SensorData.h>

SensorData<double>* sd = new SensorData<double>(2.0);
int counter = 1;
String restartingMsg = "restarting....";
String randNumStr = "rand num: ";
String initializedMsg = "Initialized data:";
String indicator = "not threatened by ";
String stoppingMsg = "STOPPING TEST";
String startMsg = "STARTING TEST";
String currentDataMsg = "Current Data: ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
