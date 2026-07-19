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
  pinMode(2, INPUT_PULLUP); 
}

void loop() {    
  if (digitalRead(2) == LOW) {    
    for (int i = 0; i < 30; i++) {
      HC12.print("LETS_FUCKING_GO\n");
      delay(30); 
    }
    
    for (pin = 4; pin < 8; pin++) {
      digitalWrite(pin, HIGH);
      delay(4 * 1000);
      digitalWrite(pin, LOW);
      delay((fire_delay - 4) * 1000);    
    }
    exit(0)
  }
}
