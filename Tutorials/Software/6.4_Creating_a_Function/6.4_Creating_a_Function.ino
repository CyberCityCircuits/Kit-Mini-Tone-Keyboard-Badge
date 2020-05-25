#include "pitches.h"
int speaker =  3;
int led = 2;
int play = 250;
int wait = 300;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  playNote(B5, play, wait);
  playNote(A5, play, wait);
  playNote(G5, play, wait);
  playNote(A5, play, wait);
  playNote(B5, play, wait);
  playNote(B5, play, wait);
  playNote(B5, play, wait);
  playNote(A5, play, wait);
  playNote(A5, play, wait);
  playNote(A5, play, wait);
  playNote(B5, play, wait);
  playNote(B5, play, wait);
  playNote(B5, play, wait);
}

void playNote(int note, int duration, int rest) {
  digitalWrite(led, HIGH);
  tone(speaker, note, duration);
  digitalWrite(led, LOW);
  delay(rest);
}
