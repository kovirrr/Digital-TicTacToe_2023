#include "LedControl.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int button1 = 31;
int button2 = 32;
int button3 = 33;
int button4 = 34;
int button5 = 35;
int button6 = 36;
int button7 = 37;
int button8 = 38;
int button9 = 39;

bool isTie;
int currentMove;

int turn = 1;
String curMoves;

int board[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};


int din0 = 2;
int cs0 = 3;
int clk0 = 4;

int din1 = 5;
int cs1 = 6;
int clk1 = 7;

int din2 = 8;
int cs2 = 9;
int clk2 = 10;

int din3 = 11;
int cs3 = 12;
int clk3 = 13;

int din4 = 14;
int cs4 = 15;
int clk4 = 16;

int din5 = 17;
int cs5 = 18;
int clk5 = 19;

int din6 = 20;
int cs6 = 21;
int clk6 = 22;

int din7 = 23;
int cs7 = 24;
int clk7 = 25;

int din8 = 26;
int cs8 = 27;
int clk8 = 28;

LedControl lc0 = LedControl(din0, clk0, cs0, 1);
LedControl lc1 = LedControl(din1, clk1, cs1, 1);
LedControl lc2 = LedControl(din2, clk2, cs2, 1);
LedControl lc3 = LedControl(din3, clk3, cs3, 1);
LedControl lc4 = LedControl(din4, clk4, cs4, 1);
LedControl lc5 = LedControl(din5, clk5, cs5, 1);
LedControl lc6 = LedControl(din6, clk6, cs6, 1);
LedControl lc7 = LedControl(din7, clk7, cs7, 1);
LedControl lc8 = LedControl(din8, clk8, cs8, 1);

byte ex[8] = {
  B10000001,
  B01000010,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B01000010,
  B10000001
};

byte oh[8] = {
  B00111100,
  B01000010,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B01000010,
  B00111100
};

int timeStarted = millis();

int timeLapsed(){
  return (millis()-timeStarted)/1000;
}


void disp(int boardNumber, int shape) { //boardNumber is from 0-8
  if (boardNumber == 0) {
    if (shape == 0) {
      lc0.clearDisplay(0);
    }
    else if (shape == 1) {
      for (int i = 0; i < 8; i++) {
        lc0.setRow(0, i, ex[i]);
        Serial.println("set 1 to x");
      }
    }
    else if (shape == 2) {
      for (int i = 0; i < 8; i++) {
        lc0.setRow(0, i, oh[i]);
      }
    }
  }
  else if (boardNumber == 1) {
    if (shape == 0) {
      lc1.clearDisplay(0);
    }
    else if (shape == 1) {
      for (int i = 0; i < 8; i++) {
        lc1.setRow(0, i, ex[i]);
      }
    }
    else if (shape == 2) {
      for (int i = 0; i < 8; i++) {
        lc1.setRow(0, i, oh[i]);
      }
    }
  }
  else if (boardNumber == 2) {
    if (shape == 0) {
      lc2.clearDisplay(0);
    }
    else if (shape == 1) {
      for (int i = 0; i < 8; i++) {
        lc2.setRow(0, i, ex[i]);
      }
    }
    else if (shape == 2) {
      for (int i = 0; i < 8; i++) {
        lc2.setRow(0, i, oh[i]);
      }
    }
  }
  else if (boardNumber == 3) {
    if (shape == 0) {
      lc3.clearDisplay(0);
    }
    else if (shape == 1) {
      for (int i = 0; i < 8; i++) {
        lc3.setRow(0, i, ex[i]);
      }
    }
    else if (shape == 2) {
      for (int i = 0; i < 8; i++) {
        lc3.setRow(0, i, oh[i]);
      }
    }
  }
  else if (boardNumber == 4) {
    if (shape == 0) {
      lc4.clearDisplay(0);
    }
    else if (shape == 1) {
      for (int i = 0; i < 8; i++) {
        lc4.setRow(0, i, ex[i]);
      }
    }
    else if (shape == 2) {
      for (int i = 0; i < 8; i++) {
        lc4.setRow(0, i, oh[i]);
      }
    }
  }
  else if (boardNumber == 5) {
    if (shape == 0) {
      lc5.clearDisplay(0);
    }
    else if (shape == 1) {
      for (int i = 0; i < 8; i++) {
        lc5.setRow(0, i, ex[i]);
      }
    }
    else if (shape == 2) {
      for (int i = 0; i < 8; i++) {
        lc5.setRow(0, i, oh[i]);
      }
    }
  }
  else if (boardNumber == 6) {
    if (shape == 0) {
      lc6.clearDisplay(0);
    }
    else if (shape == 1) {
      for (int i = 0; i < 8; i++) {
        lc6.setRow(0, i, ex[i]);
      }
    }
    else if (shape == 2) {
      for (int i = 0; i < 8; i++) {
        lc6.setRow(0, i, oh[i]);
      }
    }
  }
  else if (boardNumber == 7) {
    if (shape == 0) {
      lc7.clearDisplay(0);
    }
    else if (shape == 1) {
      for (int i = 0; i < 8; i++) {
        lc7.setRow(0, i, ex[i]);
      }
    }
    else if (shape == 2) {
      for (int i = 0; i < 8; i++) {
        lc7.setRow(0, i, oh[i]);
      }
    }
  }
  else if (boardNumber == 8) {
    if (shape == 0) {
      lc8.clearDisplay(0);
    }
    else if (shape == 1) {
      for (int i = 0; i < 8; i++) {
        lc8.setRow(0, i, ex[i]);
      }
    }
    else if (shape == 2) {
      for (int i = 0; i < 8; i++) {
        lc8.setRow(0, i, oh[i]);
      }
    }
  }
}


void light(int spot, String color) {
  Serial.print("Lighting: ");
  Serial.print(spot);
  Serial.print("  ");
  Serial.println(color);
  if (color == "r") {
    board[spot - 1] = 1;

  }
  else if (color == "g") {
    board[spot - 1] = 2;
  }



}



void reset() {
  for (int i = 0; i < 9; i++) {
    board[i] = 0;
  }
}



int winCon() { //change later to apply new variable power method
  for (int i = 0; i < 9; i += 3) { //checks all leds horizontally
    if (board[i] == 1 && board[i + 1] == 1  && board[i + 2] == 1)  {
      Serial.println("red wins");
      return 1;
    }
    if (board[i] == 2 && board[i+1] == 2 && board[i+2] == 2)  {
      Serial.println("green wins");
      return 2;
    }
  }

  for (int i = 0; i < 3; i += 2) { //checks all leds virtically
    if (board[i] == 1 && board[i + 3] == 1 && board[i + 6] == 1) {
      Serial.println("red wins");
      return 1;
    }
    if (board[i] == 2 && board[i + 3] == 2 && board[i + 6] == 2) {
      Serial.println("green wins");
      return 2;
    }
  }

  //check all leds diagnanolly
  if (board[0] == 1 && board[4] == 1 && board[8] == 1) { //top left to bottom right - red
    Serial.println("red wins");
    return 1;
  }
  if (board[0] == 2 && board[4] == 2 && board[8] == 2) { //top left to bottom right - green
    Serial.println("green wins");
    return 2;
  }

  if (board[2] == 1 && board[4] == 1 && board[6] == 1) { //top right to bottom left - red
    Serial.println("red wins");
    return 1;
  }
  if (board[2] == 2 && board[4] == 2 && board[6] == 2) { //top right to bottom left - green
    Serial.println("green wins");
    return 2;
  }

  //check for tie
  isTie = true;
  for(int i = 0; i < 9; i++){
    if (board[i] == 0){
      isTie = false;
      break;
    }
  }
  if (isTie == true){
    Serial.println("tie");
    return 0;
  }

  return -1;

}

void takeTurn(int led) { // will take out var later for the buttons telling you where to go instead
  //check buttons for where they want to go

  if (board[led-1] == 0) { //if the spot the player wants to go to is empty
    Serial.println("spot is empty");
    if (turn == 1) { //if it's x's turn
      light(led, "r"); //make their spot red

      turn = 2; //make it greens turn

    }


    else if (turn == 2) { //if it's o's turn
      light(led, "g"); //make their spot green

      turn = 1; //make it reds turn
    }


  }





}



void displayBoard() {
Serial.print(board[6]);
Serial.print(" ");
Serial.print(board[3]);
Serial.print(" ");
Serial.println(board[0]);

Serial.print(board[7]);
Serial.print(" ");
Serial.print(board[4]);
Serial.print(" ");
Serial.println(board[1]);

Serial.print(board[8]);
Serial.print(" ");
Serial.print(board[5]);
Serial.print(" ");
Serial.println(board[2]);


  //display board for Matrises
  for (int i = 0; i < 9; i++){
    disp(i, board[i]);
  }
  

  int winner = winCon();

  if (winner == 1) {
    while(true){}
  }
  else if (winner == 2) {
    while(true){}
  }
  if (winner == 0) {
    while(true){}
  }

}


int readButtons() {
  if (digitalRead(button1) == HIGH) {
    while (digitalRead(button1) == HIGH) {
      Serial.println("button 1 being held");
    }
    return 1;
  }
  if (digitalRead(button2) == HIGH) {
    while (digitalRead(button2) == HIGH) {
    }
    return 2;
  }
  if (digitalRead(button3) == HIGH) {
    while (digitalRead(button3) == HIGH) {
    }
    return 3;
  }
  if (digitalRead(button4) == HIGH) {
    while (digitalRead(button4) == HIGH) {
    }
    return 4;
  }
  if (digitalRead(button5) == HIGH) {
    while (digitalRead(button5) == HIGH) {
    }
    return 5;
  }
  if (digitalRead(button6) == HIGH) {
    while (digitalRead(button6) == HIGH) {
    }
    return 6;
  }
  if (digitalRead(button7) == HIGH) {
    while (digitalRead(button7) == HIGH) {
    }
    return 7;
  }
  if (digitalRead(button8) == HIGH) {
    while (digitalRead(button8) == HIGH) {
    }
    return 8;
  }
  if (digitalRead(button9) == HIGH) {
    while (digitalRead(button9) == HIGH) {
    }
    return 9;
  }
  return 0;


}





void setup() {


  
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("Turn: X");
//  lcd.setCursor(0,1);
//  lcd.print("Time: ");
//  lcd.print(timeLapsed());


  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  pinMode(button6, INPUT);
  pinMode(button7, INPUT);
  pinMode(button8, INPUT);
  pinMode(button9, INPUT);

  
  lc0.shutdown(0, false);
  lc0.setIntensity(0, 8);
  lc0.clearDisplay(0);

  lc1.shutdown(0, false);
  lc1.setIntensity(0, 8);
  lc1.clearDisplay(0);

  lc2.shutdown(0, false);
  lc2.setIntensity(0, 8);
  lc2.clearDisplay(0);

  lc3.shutdown(0, false);
  lc3.setIntensity(0, 8);
  lc3.clearDisplay(0);

  lc4.shutdown(0, false);
  lc4.setIntensity(0, 8);
  lc4.clearDisplay(0);

  lc5.shutdown(0, false);
  lc5.setIntensity(0, 8);
  lc5.clearDisplay(0);

  lc6.shutdown(0, false);
  lc6.setIntensity(0, 8);
  lc6.clearDisplay(0);

  lc7.shutdown(0, false);
  lc7.setIntensity(0, 8);
  lc7.clearDisplay(0);

  lc8.shutdown(0, false);
  lc8.setIntensity(0, 8);
  lc8.clearDisplay(0);
}

void loop() {
  Serial.println("working");



currentMove = 1;
  if (currentMove != 0) {
    Serial.print("move was made. LED turned on: ");
    Serial.println(currentMove);
    takeTurn(currentMove);
    displayBoard();
    currentMove = 0;
    lcd.setCursor(0,0);
      if (turn == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Turn: X");
    
      }
       else if (turn == 2){
    lcd.clear();
    lcd.setCursor(0,0);
       }
      


}






}
