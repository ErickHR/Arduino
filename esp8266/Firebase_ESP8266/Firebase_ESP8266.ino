#include <Firebase.h>

#include <ESP8266WiFi.h>

// Set these to run example.
#define FIREBASE_HOST "dsesp8266.firebaseio.com"
#define FIREBASE_AUTH "ODvOEQzeNC6s4HrwyyFZDQzsNB3dCw6CxjFD1WVe"
#define WIFI_SSID "WIFI"
#define WIFI_PASSWORD "Ju@n-123"

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

  //pinMode(2, OUTPUT);//agregando
}

int n = 0;

void loop() {
  //agrengando
  /*if(Firebase.getFloat("led"){
    digitalWrite(2, LOW)
  }else{
    digitalWrite(2, HIGH);
  }*/
  
  // set value
  Firebase.setFloat("number", 7);//cambio de 42.00 a 7 
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // update value
  Firebase.setFloat("number", 43.0);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
/*
  // get value 
  Serial.print("number: ");
  Serial.println(Firebase.getFloat("number"));
  delay(1000);

  // remove value
  Firebase.remove("number");
  delay(1000);

  // set string value
  Firebase.setString("message", "hello world");
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // set bool value
  Firebase.setBool("truth", false);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /truth failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // append a new value to /logs
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
