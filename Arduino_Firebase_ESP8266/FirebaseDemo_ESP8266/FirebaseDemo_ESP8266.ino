#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "dsesp8266.firebaseio.com"
#define FIREBASE_AUTH "ODvOEQzeNC6s4HrwyyFZDQzsNB3dCw6CxjFD1WVe"
#define WIFI_SSID "WWLAN-4830"
#define WIFI_PASSWORD "ERICK.08"

void setup() {
  Serial.begin(115200);

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



void loop() {

  if (Serial.available() > 0 ) {
    int mq = (int) Serial.read();
    Firebase.setInt("mq", mq);

    if (Firebase.failed()) {
      Serial.print("error al subir");
      Serial.println(Firebase.error());
      return;
    }
    Serial.println();
    Serial.print(mq);
    Serial.println();
  }



  /* // append a new value to /logs
    String name = Firebase.pushInt("logs", n++);
    // handle error
    if (Firebase.failed()) {
       Serial.print("pushing /logs failed:");
       Serial.println(Firebase.error());
       return;
    }
    Serial.print("pushed: /logs/");
    Serial.println(name);
    delay(1000);*/
}
