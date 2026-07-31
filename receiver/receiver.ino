#include <SoftwareSerial.h>

int pin;
int fire_delay = 30; 
bool triggered = false;
SoftwareSerial HC12(11, 3);

void setup() {  
  for (pin = 4; pin < 8; pin++) {
    digitalWrite(pin, LOW); 
    pinMode(pin, OUTPUT); 
  }
  HC12.begin(9600); 
}

void loop() {  
  if (!triggered && HC12.available() > 0) {
    String received = HC12.readStringUntil('\n');
    received.trim();    
    if (received == "PARTY_TIME") {
      triggered = true;
      for (pin = 4; pin < 8; pin++) {
        digitalWrite(pin, HIGH);
        delay(4 * 1000);
        digitalWrite(pin, LOW);
        delay((fire_delay - 4) * 1000);          
      }
    }
  }
}
