#include <SoftwareSerial.h>

int pin;
int fire_delay = 30; 
SoftwareSerial HC12(10, 11); 

void setup() {  
  for (pin = 4; pin < 8; pin++) {
    pinMode(pin, OUTPUT);  
    digitalWrite(pin, LOW);
  }
  HC12.begin(9600); 
}

void loop() {  
  if (HC12.available() > 0) {
    String received = HC12.readStringUntil('\n');
    received.trim();
    
    if (received == "LETS_FUCKING_GO") {
      for (pin = 4; pin < 8; pin++) {
        digitalWrite(pin, HIGH);
        delay(4 * 1000);
        digitalWrite(pin, LOW);
        delay((fire_delay - 4) * 1000);          
      }
      exit(0)
    }
  }
}
