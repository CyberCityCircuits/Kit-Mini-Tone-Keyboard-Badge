//Cyber City Circuits Mini-Tone Keyboard
//https://shop.cybercitycircuits.com/products/mini-tone-keyboard-badge
//This is the software that is shipped with all new Mini-Tone Keyboards.

#include "pitches.h"  //Use the user created library header for note values
#include <Keypad.h>   //Import the 'keypad' library to use the buttom matrix
#include <Adafruit_NeoPixel.h>


int play_length = 250;  //How long to play a note.
int rest_length = 100;  //How long to rest between notes

int tuning = 0;  //Slightly change the value of notes, corrects speaker issues.

//unsigned long time_since      =    0;  //How long since last note played.
//int           time_start_demo =  250;  //Wait to start color demo

int wait = 100;  //General delay value

//Assign pins
int speaker =  3;  //This is the pin that the speaker is on
int led     =  2;  //This is the pin for the LED that is on board
int rgb_d   = 16;  //RGB Lights

int row_1 =  6;  //Row 1 of the keyboard matrix
int row_2 = 10;  //Row 2 of the keyboard matrix
int row_3 = 11;  //Row 3 of the keyboard matrix
int row_4 = 14;  //Row 4 of the keyboard matrix
int row_5 = 13;  //Row 5 of the keyboard matrix

int col_1 =  8;  //Column 1 of the keyboard matrix
int col_2 =  5;  //Column 2 of the keyboard matrix
int col_3 = 15;  //Column 3 of the keyboard matrix
int col_4 =  7;  //Column 4 of the keyboard matrix
int col_5 =  9;  //Column 5 of the keyboard matrix
int col_6 = 12;  //Column 6 of the keyboard matrix

const byte ROWS = 5; //There are three rows
const byte COLS = 6; //The are six columns

Adafruit_NeoPixel strip(8, rgb_d, NEO_GRB + NEO_KHZ800);
int brightness = 50;
int r = 0;
int g = 0;
int b = 0;
int x = 0;

//Assign names to the buttons
char keys[ROWS][COLS] = {  
{'1','2','3','4','5','6'},
{'7','8','9','a','b','c'},
{'d','e','f','g','h','i'},
{'j','k','l','m','n','o'},
{'p','q','r','s','t','u'}
};

byte rowPins[ROWS] = {row_1, row_2, row_3, row_4, row_5};                      //connect to the row pinouts of the keypad
byte colPins[COLS] = {col_1, col_2, col_3, col_4, col_5, col_6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//An array of note values to associate to the array of buttons (keys)
int notes[29] = {
    C4, CS4,  D4, DS4,  E4,  F4,
   FS4,  G4, GS4,  A4, AS4,  B4, 
    C5, CS5,  D5, DS5,  E5,  F5,
   FS5,  G5, GS5,  A5, AS5,  B5, 
    C6, CS6,  D6, DS6,  E6 
};

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  
  pinMode(speaker, OUTPUT);
  pinMode(led,   OUTPUT);

  strip.begin();  //Initialize the RGB LEDs
  strip.show();
  strip.setBrightness(brightness);
}

void loop() {
if (millis() % 50 == 0){
  light_panel();
  }
  
  check_keyboard();

  //Serial.println(millis()-time_since);  

  /*
  Serial.print(" X: "); Serial.print(x);
  Serial.print(" R: "); Serial.print(r);
  Serial.print(" G: "); Serial.print(g);
  Serial.print(" B: "); Serial.print(b);
  Serial.println();
  */
}

void check_keyboard(){
  char key = keypad.getKey();

  //Find the value of the key press and play a note.
  if (key){
    if (key == '1'){playNote(notes[0],  play_length, rest_length); x =   0; light_panel();}
    if (key == '2'){playNote(notes[1],  play_length, rest_length); x =  26; light_panel();}
    if (key == '3'){playNote(notes[2],  play_length, rest_length); x =  53; light_panel();}
    if (key == '4'){playNote(notes[3],  play_length, rest_length); x =  79; light_panel();}
    if (key == '5'){playNote(notes[4],  play_length, rest_length); x = 106; light_panel();}
    if (key == '6'){playNote(notes[5],  play_length, rest_length); x = 132; light_panel();}
    if (key == '7'){playNote(notes[6],  play_length, rest_length); x = 158; light_panel();}
    if (key == '8'){playNote(notes[7],  play_length, rest_length); x = 185; light_panel();}
    if (key == '9'){playNote(notes[8],  play_length, rest_length); x = 211; light_panel();}
    if (key == 'a'){playNote(notes[9],  play_length, rest_length); x = 237; light_panel();}
    if (key == 'b'){playNote(notes[10], play_length, rest_length); x = 264; light_panel();}
    if (key == 'c'){playNote(notes[11], play_length, rest_length); x = 290; light_panel();}
    if (key == 'd'){playNote(notes[12], play_length, rest_length); x = 317; light_panel();}
    if (key == 'e'){playNote(notes[13], play_length, rest_length); x = 343; light_panel();}
    if (key == 'f'){playNote(notes[14], play_length, rest_length); x = 369; light_panel();}
    if (key == 'g'){playNote(notes[15], play_length, rest_length); x = 396; light_panel();}
    if (key == 'h'){playNote(notes[16], play_length, rest_length); x = 422; light_panel();}
    if (key == 'i'){playNote(notes[17], play_length, rest_length); x = 448; light_panel();}
    if (key == 'j'){playNote(notes[18], play_length, rest_length); x = 475; light_panel();}
    if (key == 'k'){playNote(notes[19], play_length, rest_length); x = 501; light_panel();}
    if (key == 'l'){playNote(notes[20], play_length, rest_length); x = 528; light_panel();}
    if (key == 'm'){playNote(notes[21], play_length, rest_length); x = 554; light_panel();}
    if (key == 'n'){playNote(notes[22], play_length, rest_length); x = 580; light_panel();}
    if (key == 'o'){playNote(notes[23], play_length, rest_length); x = 607; light_panel();}
    if (key == 'p'){playNote(notes[24], play_length, rest_length); x = 633; light_panel();}
    if (key == 'q'){playNote(notes[25], play_length, rest_length); x = 659; light_panel();}
    if (key == 'r'){playNote(notes[26], play_length, rest_length); x = 686; light_panel();}
    if (key == 's'){playNote(notes[27], play_length, rest_length); x = 712; light_panel();}
    if (key == 't'){playNote(notes[28], play_length, rest_length); x = 739; light_panel();}
    
    //Serial.print("Key: "); Serial.println(key);
  }
}

//Function to play notes
void playNote(int note, int duration, int rest) {
  //time_since = millis();
  digitalWrite(led, HIGH);
  tone(speaker, note + tuning, duration);
  delay(rest);
  digitalWrite(led, LOW);

}


void light_panel(){
  x += 1;
  if (x > 765){x = 0;}  
  if (r > 255){r = 0;}
  if (g > 255){g = 0;}
  if (b > 255){b = 0;}

  if (x <= 255)          {r = 255 - x;          g =   0 + x;        b =   0;}
  if (x  > 255 & x < 510){r =   0;              g = 255 - (x-255);  b =   0 + (x-255);}
  if (x  > 510 & x < 765){r =   0 + (x - 510);  g = 0;              b = 255 - (x - 510);}
  for(int y = 0; y < 4; y++) {
    strip.setPixelColor(y, strip.Color(r,g,b));
  }
  strip.show();
}
