#include <SoftwareSerial.h>

SoftwareSerial RadioSerial(10, 11); 

int pin;
bool trigger = false; 

const int start_delay = 0; 
const int fire_delay = 30; 
const int ignite_time = 5; 

void setup() {
  RadioSerial.begin(2400); 
  
  for (pin = 4; pin < 8; pin++) {
    pinMode(pin, OUTPUT);  
    digitalWrite(pin, LOW);
  }
}

void loop() {  
  if (!trigger) {
    if (RadioSerial.available() > 0) {
      String command = RadioSerial.readStringUntil('\n');
      command.trim();
      
      if (command == "LETS_FUCKING_GO") {
        trigger = true;
        delay(start_delay * 1000); 
      }
    }
  }
  
  if (trigger) {
    for (pin = 4; pin < 8; pin++) {
      digitalWrite(pin, HIGH);
      delay(ignite_time * 1000);
      digitalWrite(pin, LOW);
      
      if (pin < 7) {
        delay((fire_delay - ignite_time) * 1000);    
      }
    }
    exit(0)
  }
}
