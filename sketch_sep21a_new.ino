#define sensor_pin A2
int min = 1023;
int max = 0;
int treshold = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  while(millis() < 10000){
    digitalWrite(LED_BUILTIN, HIGH);
    int val = analogRead(sensor_pin);
    if (val < min){
      min = val;
    }
    if (val > max){
      max = val;
    }
    treshold = min + (max-min)/2;
  }
}


void loop() {
  int val = analogRead(sensor_pin);
  Serial.println(val);
  delay(10);
  if (val < treshold ){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);  
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);  
  }
}
