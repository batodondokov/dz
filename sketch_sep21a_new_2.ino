#define sensor_pin A2

long lastm = 0;
long interval = 0;
int status = 1;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  long currentm = millis();
  int val = analogRead(sensor_pin);
  Serial.println(val);
  interval = pow(val/100,3);
  if (currentm - lastm > interval){
    lastm = currentm;
    if (status == 1){
      status = 0;
      digitalWrite(LED_BUILTIN, LOW);
    }else{
      status = 1;
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }
}
