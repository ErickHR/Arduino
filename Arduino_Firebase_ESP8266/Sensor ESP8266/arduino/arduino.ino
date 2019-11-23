#include <SoftwareSerial.h>

#define rxPin 2
#define txPin 3
int mq_135 = 0;
int mq_2 = 0;

SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
}

void loop() {

  mq_135 =  analogRead(A0);
  Serial.write((int)mq_135);

  mq_2 = analogRead(A1);
  mySerial.write((int)mq_2);

}
