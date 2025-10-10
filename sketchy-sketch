int pin;

int start_delay = 0; // delay before firing first igniter
int fire_delay = 30; // time between between each pyro
int ignite_time = 5; // how long to power the fuse for
bool repeat = false; // change to true to loop indefinitly

void setup() {

  delay(start_delay * 1000);
  Serial.begin(9600);
 
  for (pin = 4; pin < 8; pin++) {
    pinMode(pin, OUTPUT);  
  }

}

void loop() {  

  for (pin = 4; pin < 8; pin++) {
    digitalWrite(pin, HIGH);
    delay(ignite_time * 1000);
    digitalWrite(pin, LOW);
    delay((fire_delay - ignite_time) * 1000);    
  }

  if (repeat == false) {
    delay(42069 * 1000);
  }
 
}
