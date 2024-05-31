/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"

#define ROW1 13
#define ROW2 12
#define ROW3 11
#define ROW4 10
#define ROW5 9
#define ROW6 8
#define ROW7 7
#define ROW8 6

#define COL1 5
#define COL2 4
#define COL3 3
#define COL4 A4
#define COL5 A3
#define COL6 A2
#define COL7 A1
#define COL8 A0

#define BUTTON 2


const int row[] = {ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};
const int col[] = {COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8};

int imgIndexNow = 0;
bool isPressing = false;

int circle[8][8] = {{1,1,0,0,0,0,1,1},
		           {1,0,1,1,1,1,0,1},
		           {0,1,1,1,1,1,1,0},
		           {0,1,1,1,1,1,1,0},
		           {0,1,1,1,1,1,1,0},
		           {0,1,1,1,1,1,1,0},
		           {1,0,1,1,1,1,0,1},
		           {1,1,0,0,0,0,1,1}};

int face[8][8] = {{1,1,0,0,0,0,1,1},
		          {1,0,1,1,1,1,0,1},
		          {0,1,1,0,0,1,1,0},
		          {0,1,1,1,1,1,1,0},
		          {0,1,0,1,1,0,1,0},
		          {0,1,1,0,0,1,1,0},
		          {1,0,1,1,1,1,0,1},
		          {1,1,0,0,0,0,1,1}};
int iiiiii[8][8] = {{1,1,0,0,1,1,0,0},
		                {1,1,0,0,1,1,0,0},
		                {0,0,1,1,0,0,1,1},
		                {0,0,1,1,0,0,1,1},
		                {1,1,0,0,1,1,0,0},
		                {1,1,0,0,1,1,0,0},
		                {0,0,1,1,0,0,1,1},
		                {0,0,1,1,0,0,1,1}};
int fuck[8][8] =   {{1,0,0,1,1,0,0,0},
		                {1,0,0,1,1,0,0,0},
		                {1,0,0,1,1,0,0,0},
		                {1,0,0,1,1,0,0,0},
		                {0,1,1,1,1,1,1,1},
		                {0,1,1,1,1,1,1,1},
		                {0,1,1,1,1,1,1,1},
		                {0,1,1,1,1,1,1,1}};
int tttt[8][8] =   {{1,1,1,1,1,1,1,1},
		                {1,1,0,1,1,1,1,1},
		                {1,0,0,1,1,1,1,1},
		                {0,0,0,0,0,0,0,0},
		                {1,0,0,1,1,1,1,1},
		                {1,1,0,1,1,1,1,1},
		                {1,1,1,1,1,1,1,1},
		                {1,1,1,1,1,1,1,1}};








const int BUTTON_PIN = 2;
int buttonState = 0;
// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int c4[] = {
  NOTE_GS5, NOTE_C4, NOTE_GS5, NOTE_C4, NOTE_D6, NOTE_C4, NOTE_D6, NOTE_C4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4
};
int m3[] = {
  8, 8, 8, 8, 8, 8, 8, 8
};
int thisNote=-1;
int noteDuration=0;
long start_time=0 ;
long present_time=0 ;
long pauseBetweenNotes=0;


void setup() {
  
  for (int i = 3; i <= 13; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  
  digitalWrite(A0, LOW);
  digitalWrite(A1, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);

  pinMode(BUTTON_PIN, INPUT_PULLUP);






  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}
void check(){
  present_time=millis();
  if(present_time-start_time>=pauseBetweenNotes)
  {
    thisNote+=1;
    if(thisNote >=8)
    {
      thisNote = -1 ;
      pauseBetweenNotes=100;
      start_time=millis();
    }
  else
  {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(A5, melody[thisNote], noteDuration);     //可能要改
    int pauseBetweenNotes = noteDuration * 1.30;
    start_time=millis();
  }
}
}

void check_2(){
  present_time=millis();
  if(present_time-start_time>=pauseBetweenNotes)
  {
    thisNote+=1;
    if(thisNote >=8)
    {
      thisNote = -1 ;
      pauseBetweenNotes=100;
      start_time=millis();
    }
  else
  {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(A5, c4[thisNote], noteDuration);     //可能要改
    int pauseBetweenNotes = noteDuration * 1.30;
    start_time=millis();
  }
}
}




void loop() {

  buttonState = digitalRead(BUTTON_PIN);
  if(buttonState == LOW){          //如果按鍵按了
  for (int i = 0 ; i<8 ; i++) {
    lightup(tttt);
    check();
    delay(1);
  }  
    
  }else{                           //如果按鍵是未按下
  for (int i = 0 ; i<8 ; i++) {
    lightup(iiiiii);
    check_2();
    delay(1);
  }    
  }
  // no need to repeat the melody.
}



void lightup(int matrix[8][8]){
  for (int i=0; i<8; i++){
    digitalWrite(col[i], HIGH);
    for (int j = 0; j < 8; j++){
      digitalWrite(row[j], matrix[j][i]);
      
    }
    for (int j = 0; j < 8; j++){
      digitalWrite(row[j], HIGH);
      //delay(1);
    }
    digitalWrite(col[i], LOW);
  }
}