int light = 200; 
int dark; 
int min_dark = 1; 
int max_dark = 50; 
int light_pin = 5; 
int potent1_pin = 2; 
int potent2_pin = 3; 
int shortdark;



void setup() {
  pinMode(light_pin, OUTPUT);

}

void loop() {
  dark = map(analogRead(potent1_pin), 0, 877, min_dark, max_dark);
  shortdark = map(analogRead(potent2_pin), 0, 882, 2000, 4500);
  digitalWrite(light_pin, HIGH); 
  delayMicroseconds(light); 
  digitalWrite(light_pin, LOW); 
  delay(dark);
  delayMicroseconds(shortdark);  

}
