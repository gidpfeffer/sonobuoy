const int LiquidSensorPin = 24;
int pw_pin=7;
int arraysize = 9;
int array[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};
long inch;
int exact_cm_value;

void setup() {
  Serial.begin(9600);      
  pinMode(pw_pin, INPUT);
  pinMode(LiquidSensorPin, INPUT);
}

int getLiquidLevel(){
    return !digitalRead(LiquidSensorPin);
}

void sensorRead(){
for(int i = 0; i < arraysize; i++)
{ 
inch = pulseIn(pw_pin, HIGH);
array[i] = inch/58;
delay(10);
}
}
void array_arrangment(int *a,int n){
// Author: Bill Gentles, Nov. 12, 2010)
for (int i = 1; i < n; ++i)
{
int j = a[i];
int k;
for (k = i - 1; (k >= 0) && (j < a[k]); k--)
{
a[k + 1] = a[k];
}
a[k + 1] = j;
}
}

int filter(int *a,int n){
int i = 0;
int count = 0;
int maxCount = 0;
int filter = 0;
int median;
int prevCount = 0;
while(i<(n-1)){
prevCount=count;
count=0;
while(a[i]==a[i+1]){
count++;
i++;
}
if(count>prevCount && count>maxCount){
filter=a[i];
maxCount=count;
median=0;
}
if(count==0){
i++;
}
if(count==maxCount){//If the dataset has 2 or more modes.
median=1;
}
if(filter==0||median==1){//Return the median if there is no mode.
filter=a[(n/2)];
}

return filter;

} 
}

void loop() {
  sensorRead();
  array_arrangment(array,arraysize);
  exact_cm_value= filter(array,arraysize);
  boolean underwater = getLiquidLevel();
  String liquidStatus = "Liquid level is not underwater";
  if(getLiquidLevel()){
    liquidStatus = "Threat Detected: Liquid level is underwater";
  }
  
  Serial.print(liquidStatus + " Distance: " + (String) exact_cm_value);
  Serial.print("\n");
  delay(1000);
}


