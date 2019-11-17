#include <Ethernet.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

byte mac_addr[] = {0xDE, 0xAD, 0xEF, 0xFE, 0xED};

IPAddress server_addr(192, 168, 1, 64);

char user[] = "arduino";
char password[] = "secreta";

char insert_data [] = "insert into dbarduino.hello_sensor(message, sensor_num

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
