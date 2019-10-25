#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "dsesp8266.firebaseio.com"
#define FIREBASE_AUTH "ODvOEQzeNC6s4HrwyyFZDQzsNB3dCw6CxjFD1WVe"
#define WIFI_SSID "UNTELS WIFI"
#define WIFI_PASSWORD "untelswifi"


void setup() {
  Serial.begin(9600);

  // connect to wifi.
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

int mq_135 = Serial.read();

void loop() {
  
  Firebase.setInt("mq_135", mq_135);
  
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /logs/");
  delay(2000);
  mq_135 = Serial.read();
}
