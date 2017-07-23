#include <Threat.h>

void setup() {
  Serial.begin(9600);
  Threat threat = new Threat(Sensor.Sonar, "testing");
  Serial.println(threat.getMessage());
  Serial.println(threat.getSensor());
}

void loop() {
  // put your main code here, to run repeatedly:

}