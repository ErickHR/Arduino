int mq_135 = 0;
void setup() {
  Serial.begin(115200);
}

void loop() {
  
  mq_135 =  analogRead(A0);
  Serial.write((int)mq_135);
  
}
