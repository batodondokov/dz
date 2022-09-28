
#define sensor_pin A2
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {


  int val = analogRead(sensor_pin);
  Serial.println(val);
  delay(10);
  if (val < 800 ){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);  
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);  
  }

}
