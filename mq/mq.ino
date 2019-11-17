#include <ESP8266WiFi.h>

const char* wifi = "WIFI";
const char* contra = "Ju@n-123";

WiFiServer server(80);

int PindLed = 16;
int estado = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(PindLed, OUTPUT);
  digitalWrite(PindLed, LOW);

  WiFi.begin(wifi, contra);
  Serial.printf("Conectando a la red: %\n", WiFi.SSID().c_str());
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".";
  }
  Serial.println("");
  Serial.println("Wifi conectada");

  server.begin();
  Serial.println("servidor inicializado");
  Serial.printf("\n\n utiliza esta url para conectar : http://%s/\n",WiFi.localIP().toString()
}

void loop() {
  
  int adc_MQ = analogRead(A0); //Lemos la salida analógica del MQ
  float voltaje = adc_MQ * (5.0 / 1023.0); //Convertimos la lectura en un valor de voltaje

  Serial.print("adc:");
  Serial.print(adc_MQ);
  Serial.print("    voltaje:");
  Serial.println(voltaje);
  delay(100);
}
