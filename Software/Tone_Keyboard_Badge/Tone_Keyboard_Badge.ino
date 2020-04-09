#include "pitches.h"  //Use the user created library header for note values
#include <Keypad.h>   //Import the 'keypad' library to use the buttom matrix
#include <Adafruit_NeoPixel.h>


int play_length = 250;  //How long to play a note.
int rest_length = 100;  //How long to rest between notes

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
int r;
int g;
int b;

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

  strip.begin();  //Initisalze the RGB LEDs
  strip.show();
  strip.setBrightness(brightness);

/*    for(int y = 0; y < 3; y++) {
    for(int x = 0; x < 4; x++) {
      if(y == 0) {
        strip.setPixelColor(x, strip.Color(255,0,0));         //  Set pixel's color (in RAM)
      }
      if(y == 1) {
        strip.setPixelColor(x, strip.Color(0,0,255));         //  Set pixel's color (in RAM)
      }
      if(y == 2) {
        strip.setPixelColor(x, strip.Color(0,255,0));         //  Set pixel's color (in RAM)        
      }
      strip.show();               
      delay(25);
    }
  } 
  */
}

void loop() {
  char key = keypad.getKey();

  //Find the value of the key press and play a note.
  if (key){
    if (key == '1'){playNote(notes[0],  play_length, rest_length); r = 255, g =   0, b =   0;}
    if (key == '2'){playNote(notes[1],  play_length, rest_length); r = 237, g =  36, b =   0;}
    if (key == '3'){playNote(notes[2],  play_length, rest_length); r = 219, g =  55, b =   0;}
    if (key == '4'){playNote(notes[3],  play_length, rest_length); r = 200, g =  72, b =   0;}
    if (key == '5'){playNote(notes[4],  play_length, rest_length); r = 182, g =  91, b =   0;}
    if (key == '6'){playNote(notes[5],  play_length, rest_length); r = 163, g = 109, b =   0;}
    if (key == '7'){playNote(notes[6],  play_length, rest_length); r = 146, g = 128, b =   0;}
    if (key == '8'){playNote(notes[7],  play_length, rest_length); r = 146, g = 146, b =   0;}
    if (key == '9'){playNote(notes[8],  play_length, rest_length); r = 128, g = 164, b =   0;}
    if (key == 'a'){playNote(notes[9],  play_length, rest_length); r =  91, g = 180, b =   0;}
    if (key == 'b'){playNote(notes[10], play_length, rest_length); r =  72, g = 200, b =   0;}
    if (key == 'c'){playNote(notes[11], play_length, rest_length); r =  54, g = 219, b =   0;}
    if (key == 'd'){playNote(notes[12], play_length, rest_length); r =  36, g = 237, b =   0;}
    if (key == 'e'){playNote(notes[13], play_length, rest_length); r =  18, g = 255, b =   0;}
    if (key == 'f'){playNote(notes[14], play_length, rest_length); r =   0, g = 245, b =  18;}
    if (key == 'g'){playNote(notes[15], play_length, rest_length); r =   0, g = 234, b =  36;}
    if (key == 'h'){playNote(notes[16], play_length, rest_length); r =   0, g = 216, b =  55;}
    if (key == 'i'){playNote(notes[17], play_length, rest_length); r =   0, g = 198, b =  72;}
    if (key == 'j'){playNote(notes[18], play_length, rest_length); r =   0, g = 180, b =  91;}
    if (key == 'k'){playNote(notes[19], play_length, rest_length); r =   0, g = 164, b = 109;}
    if (key == 'l'){playNote(notes[20], play_length, rest_length); r =   0, g = 146, b = 128;}
    if (key == 'm'){playNote(notes[21], play_length, rest_length); r =   0, g = 128, b = 146;}
    if (key == 'n'){playNote(notes[22], play_length, rest_length); r =   0, g = 109, b = 163;}
    if (key == 'o'){playNote(notes[23], play_length, rest_length); r =   0, g =  91, b = 182;}
    if (key == 'p'){playNote(notes[24], play_length, rest_length); r =   0, g =  72, b = 200;}
    if (key == 'q'){playNote(notes[25], play_length, rest_length); r =   0, g =  55, b = 218;}
    if (key == 'r'){playNote(notes[26], play_length, rest_length); r =   0, g =  36, b = 236;}
    if (key == 's'){playNote(notes[27], play_length, rest_length); r =   0, g =  18, b = 255;}
    if (key == 't'){playNote(notes[28], play_length, rest_length); r =   0, g =   0, b = 255;}
    for(int x = 0; x < 4; x++) {
      strip.setPixelColor(x, strip.Color(r,g,b));  //  Set pixel's color (in RAM)        
    }
    strip.show();
    Serial.print("Key: "); Serial.println(key);
  }
}

//Function to play notes
void playNote(int note, int duration, int rest) {
  digitalWrite(led, HIGH);
  tone(speaker, note, duration);
  for(int x = 0; x < 4; x++) {
    strip.setPixelColor(x, strip.Color(r,g,b));  //  Set pixel's color (in RAM)        
  }
  strip.show();  
  delay(rest);
  digitalWrite(led, LOW);
    //delay(250);
  for(int x = 0; x < 4; x++) {
    strip.setPixelColor(x, strip.Color(0,0,0));
  }
  strip.show();
  
}
