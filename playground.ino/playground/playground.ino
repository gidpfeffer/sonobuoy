#include <Threat.h>
#include <MathHelper.h>


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  double avg = 1.0;
  double vals[2] = {4.0, 2.0};
  int capacity = sizeof(vals)/sizeof(double);
  Serial.println(capacity);
  Serial.println(MathHelper::stdDev(avg, vals, capacity));
}

void loop() {
  // put your main code here, to run repeatedly:

}
