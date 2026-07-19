#include <SoftwareSerial.h>

SoftwareSerial RadioSerial(10, 11); 

int pin;
int last_state = HIGH;

const int button_pin = 2; 
const int start_delay = 0;   
const int fire_delay = 30;   
const int ignite_time = 5;

void setup() {
  RadioSerial.begin(2400); 
  pinMode(button_pin, INPUT_PULLUP); 
 
  for (pin = 4; pin < 8; pin++) {
    pinMode(pin, OUTPUT);  
    digitalWrite(pin, LOW); 
  }
}

void loop() {  
  int button_state = digitalRead(button_pin);
  
  if (button_state == LOW && last_state == HIGH) {
    
    for (int i = 0; i < 5; i++) {
      RadioSerial.print("LETS_FUCKING_GO\n");
      delay(30); 
    }
    
    delay(start_delay * 1000); 
    for (pin = 4; pin < 8; pin++) {
      digitalWrite(pin, HIGH);
      delay(ignite_time * 1000);
      digitalWrite(pin, LOW);
      if (pin < 7) {
        delay((fire_delay - ignite_time) * 1000);    
      }
    }
    delay(500); 
  }
  last_state = button_state;
}
