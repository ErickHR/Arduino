void setup() {
  Serial.begin(9600);
}

void loop() {
  
  int mq_135 = analogRead(A0);
  //int mq_2 = analogRead(A1);
  
  Serial.print(mq_135);
  Serial.print("\n");
  
  Serial.write(mq_135);
  Serial.print("\n");
  delay(1000);
}
