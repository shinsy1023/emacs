#include <SoftwareSerial.h>

int Tx=2;
int Rx=3;
//int Scl=A5;
//int Sda=A4;
int Int=4;
SoftwareSerial fir(Tx, Rx);
String my="";

void setup() {
  Serial.begin(9600);
  fir.begin(9600);
}

void loop() {
  char mine;
  int Scl;
  int Sda;
  int runn;
  while(fir.available()){
    mine=(char)fir.read();
    my+=mine;
    Scl=analogRead(A5);
    Sda=analogRead(A4);
    runn=Serial.read();
    Serial.println(Scl+"    "+Sda);
    delay(2);
  }
  if(!my.equals("")){
    Serial.println(my+"   "+Scl+"    "+Sda);
    my="";
  }
}
