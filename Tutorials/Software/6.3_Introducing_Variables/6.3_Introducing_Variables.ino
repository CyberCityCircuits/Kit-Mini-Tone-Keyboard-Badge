#include "pitches.h"  //Include the pitches.h header file.
int speaker =  3;     //Assign the speaker to a pin.
int wait = 300;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  tone(speaker, B5, 250); 
  delay(wait);
  tone(speaker, A5, 250); 
  delay(wait);
  tone(speaker, G5, 250); 
  delay(wait);
  tone(speaker, A5, 250); 
  delay(wait);
  tone(speaker, B5, 250); 
  delay(wait);
  tone(speaker, B5, 250); 
  delay(wait);
  tone(speaker, B5, 250); 
  delay(wait);
  tone(speaker, A5, 250); 
  delay(wait);
  tone(speaker, A5, 250); 
  delay(wait);
  tone(speaker, A5, 250); 
  delay(wait);
  tone(speaker, B5, 250); 
  delay(wait);
  tone(speaker, B5, 250); 
  delay(wait);
  tone(speaker, B5, 250); 
  delay(wait);
}
