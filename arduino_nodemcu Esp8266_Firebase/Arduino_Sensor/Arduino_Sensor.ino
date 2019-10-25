void setup() {
  Serial.begin(9600);
}

void loop() {

  int mq_135 =(int) analogRead(A0);
  //int valor2 = digitalRead(13);
  Serial.print(mq_135);
  //Serial.print("    ");
  //Serial.print(valor2);
  Serial.println();
  Serial.print("salto");
  Serial.write(mq_135);
}
