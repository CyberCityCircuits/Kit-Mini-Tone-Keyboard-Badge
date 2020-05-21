#include "pitches.h"
int speaker =  3;
int led = 2;
int wait = 500;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  playNote(B5, 250, 300);
  playNote(A5, 250, 300);
  playNote(G5, 250, 300);
  playNote(A5, 250, 300);
  playNote(B5, 250, 300);
  playNote(B5, 250, 300);
  playNote(B5, 250, 300);
  playNote(A5, 250, 300);
  playNote(A5, 250, 300);
  playNote(A5, 250, 300);
  playNote(B5, 250, 300);
  playNote(B5, 250, 300);
  playNote(B5, 250, 300);
}

void playNote(int note, int duration, int rest) {
  digitalWrite(led, HIGH);
  tone(speaker, note, duration);
  digitalWrite(led, LOW);
  delay(rest);
}
