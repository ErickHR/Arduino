void setup() {
  Serial.begin(9600);
}

void loop() {

  int valor =(int) analogRead(A0);
  //int valor2 = digitalRead(13);
  Serial.print(valor);
  //Serial.print("    ");
  //Serial.print(valor2);
  Serial.println();
  Serial.print("salto");
  Serial.write(valor);
}
