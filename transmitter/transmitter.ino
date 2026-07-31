#include <SoftwareSerial.h>

int pin;
int fire_delay = 30;
bool triggered = false;
SoftwareSerial HC12(3, 11);

void setup() { 
  for (pin = 4; pin < 8; pin++) {
    digitalWrite(pin, LOW); 
    pinMode(pin, OUTPUT);     
  }
  HC12.begin(9600); 
  pinMode(12, INPUT_PULLUP); 
  while (digitalRead(12) == LOW);
}

void loop() {    
  if (!triggered && digitalRead(12) == LOW) {    
    delay(50);
    if (digitalRead(12) == LOW) {
      triggered = true;
      transmit(4, 200);
      for (pin = 4; pin < 8; pin++) {
        digitalWrite(pin, HIGH);
        delay(4 * 1000);
        digitalWrite(pin, LOW);
        if (pin == 4) {
          transmit((fire_delay - 4) * 2, 500);
        } else {
          delay((fire_delay - 4) * 1000);    
        }
      }
    }
  }
}

void transmit(int bursts, int spacing) {
  for (int i = 0; i < bursts; i++) {
    HC12.print("PARTY_TIME\n");
    delay(spacing); 
  }    
}