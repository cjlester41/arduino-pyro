#include <SoftwareSerial.h>

int pin;
int fire_delay = 30;
bool triggered = false;
SoftwareSerial HC12(10, 11); 

void setup() { 
  for (pin = 4; pin < 8; pin++) {
    digitalWrite(pin, LOW); 
    pinMode(pin, OUTPUT);     
  }
  HC12.begin(9600); 
  pinMode(2, INPUT_PULLUP); 
  while (digitalRead(2) == LOW);
}

void loop() {    
  if (!triggered && digitalRead(2) == LOW) {    
    delay(50);
    if (digitalRead(2) == LOW) {
      triggered = true;
      for (int i = 0; i < 4; i++) {
        HC12.print("LETS_FUCKING_GO\n");
        delay(50); 
      }      
      for (pin = 4; pin < 8; pin++) {
        digitalWrite(pin, HIGH);
        delay(4 * 1000);
        digitalWrite(pin, LOW);
        delay((fire_delay - 4) * 1000);    
      }
    }
  }
}
