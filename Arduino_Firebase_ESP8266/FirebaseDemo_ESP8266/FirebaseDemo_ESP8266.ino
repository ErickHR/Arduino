#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "dsesp8266.firebaseio.com"
#define FIREBASE_AUTH "ODvOEQzeNC6s4HrwyyFZDQzsNB3dCw6CxjFD1WVe"
#define WIFI_SSID "WWLAN-4830"
#define WIFI_PASSWORD "ERICK.08"
SoftwareSerial mySerial(14, 12, false, 128);


int mq_2 = 0;
int mq_135 = 0;

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}



void loop() {

  if (Serial.available() > 0 ) {
    mq_135 = (int) Serial.read();
    Firebase.setInt("mq_135", mq_135);

    if (Firebase.failed()) {
      Serial.print("error al subir mq_135");
      Serial.println(Firebase.error());
      return;
    }
  }

  mq_2 = (int) mySerial.read();
  Firebase.setInt("mq_2", mq_2);

  if (Firebase.failed()) {
    Serial.print("error al subir mq_2");
    Serial.println(Firebase.error());
    return;
  }

  Serial.print(mq_135);
  Serial.print(" ");
  Serial.print(mq_2);
  Serial.println();

}
