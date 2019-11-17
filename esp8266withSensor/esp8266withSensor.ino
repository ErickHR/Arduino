#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "dsesp8266.firebaseio.com"
#define FIREBASE_AUTH "ODvOEQzeNC6s4HrwyyFZDQzsNB3dCw6CxjFD1WVe"
#define WIFI_SSID "WIFI"
#define WIFI_PASSWORD "Ju@n-123"

#define puerto ADC0

void setup() {
  Serial.begin(9600);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(2, OUTPUT);
  
}

void loop() {
  
  //int mq_135 = analogRead(0);

  //String name = Firebase.pushInt("mq_135", mq_135);
  
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("name: ");
  Serial.println(name);
  
  Serial.print("mq_135: ");
  Serial.println(mq_135); 
  delay(2000);
}
