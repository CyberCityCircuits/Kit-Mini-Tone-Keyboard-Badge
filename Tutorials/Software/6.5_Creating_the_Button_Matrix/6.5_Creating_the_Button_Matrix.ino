#include "pitches.h"  //Use the user created library header for note values
#include <Keypad.h>   //Import the 'keypad' library to use the buttom matrix

int play = 250;  //How long to play a note.
int wait = 100;  //How long to rest between notes

//Assign pins
int speaker =  3;  //This is the pin that the speaker is on
int led     =  2;  //This is the pin for the LED that is on board

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

//Assign names to the buttons
char keys[ROWS][COLS] = {  
{'1','2','3','4','5','6'},
{'7','8','9','a','b','c'},
{'d','e','f','g','h','i'},
{'j','k','l','m','n','o'},
{'p','q','r','s','t','u'}
};

//connect to the row pinouts of the keypad
byte rowPins[ROWS] = {row_1, row_2, row_3, row_4, row_5};        
//connect to the column pinouts of the keypad
byte colPins[COLS] = {col_1, col_2, col_3, col_4, col_5, col_6}; 

//Construct the Keypad object called 'buttons'
Keypad buttons = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//An array of note values to associate to the array of buttons (keys)
int notes[29] = {
    C4, CS4,  D4, DS4,  E4,  F4,
   FS4,  G4, GS4,  A4, AS4,  B4, 
    C5, CS5,  D5, DS5,  E5,  F5,
   FS5,  G5, GS5,  A5, AS5,  B5, 
    C6, CS6,  D6, DS6,  E6 
};

void setup() {
  pinMode(led,   OUTPUT);
}

void loop() {
  check_keyboard();
}

void check_keyboard(){
  char key = buttons.getKey();

  //Find the value of the key press and play a note.
  if (key){
    if (key == '1'){playNote(notes[0],  play, wait);}
    if (key == '2'){playNote(notes[1],  play, wait);}
    if (key == '3'){playNote(notes[2],  play, wait);}
    if (key == '4'){playNote(notes[3],  play, wait);}
    if (key == '5'){playNote(notes[4],  play, wait);}
    if (key == '6'){playNote(notes[5],  play, wait);}
    if (key == '7'){playNote(notes[6],  play, wait);}
    if (key == '8'){playNote(notes[7],  play, wait);}
    if (key == '9'){playNote(notes[8],  play, wait);}
    if (key == 'a'){playNote(notes[9],  play, wait);}
    if (key == 'b'){playNote(notes[10], play, wait);}
    if (key == 'c'){playNote(notes[11], play, wait);}
    if (key == 'd'){playNote(notes[12], play, wait);}
    if (key == 'e'){playNote(notes[13], play, wait);}
    if (key == 'f'){playNote(notes[14], play, wait);}
    if (key == 'g'){playNote(notes[15], play, wait);}
    if (key == 'h'){playNote(notes[16], play, wait);}
    if (key == 'i'){playNote(notes[17], play, wait);}
    if (key == 'j'){playNote(notes[18], play, wait);}
    if (key == 'k'){playNote(notes[19], play, wait);}
    if (key == 'l'){playNote(notes[20], play, wait);}
    if (key == 'm'){playNote(notes[21], play, wait);}
    if (key == 'n'){playNote(notes[22], play, wait);}
    if (key == 'o'){playNote(notes[23], play, wait);}
    if (key == 'p'){playNote(notes[24], play, wait);}
    if (key == 'q'){playNote(notes[25], play, wait);}
    if (key == 'r'){playNote(notes[26], play, wait);}
    if (key == 's'){playNote(notes[27], play, wait);}
    if (key == 't'){playNote(notes[28], play, wait);}
  }
}

//Function to play notes
void playNote(int note, int duration, int rest) {
  digitalWrite(led, HIGH);
  tone(speaker, note, duration);
  delay(rest);
  digitalWrite(led, LOW);
}
