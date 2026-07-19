#include <SoftwareSerial.h>

SoftwareSerial RadioSerial(10, 11); 

int pin;

int start_delay = 0;   // delay before firing first igniter
int fire_delay = 30;   // time between firing each pyro (seconds)
int ignite_time = 5;   // how long to power the fuse for (seconds)
bool signal = false; 

void setup() {
  Serial.begin(9600);
  RadioSerial.begin(9600); 
  
  for (pin = 4; pin < 8; pin++) {
    pinMode(pin, OUTPUT);  
    digitalWrite(pin, LOW);
  }
}

void loop() {  
  if (!signal) {
    if (RadioSerial.available() > 0) {
      String command = RadioSerial.readStringUntil('\n');
      command.trim();
      
      if (command == "LETS_FUCKING_GO") {
        signal = true;
        delay(start_delay * 1000); 
      }
    }
  }
  
  if (signal) {
    for (pin = 4; pin < 8; pin++) {
      digitalWrite(pin, HIGH);
      delay(ignite_time * 1000);
      digitalWrite(pin, LOW);
      
      if (pin < 7) {
        delay((fire_delay - ignite_time) * 1000);    
      }
    }
  }
}
