// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START IQ MACROS
#define waitUntil(condition)                                                   
  do {                                                                         
    wait(5, msec);                                                             
  } while (!(condition))

#define repeat(iterations)                                                     
  for (int iterator = 0; iterator < iterations; iterator++)
// END IQ MACROS


// Robot configuration code.



// generating and setting random seed
void initializeRandomSeed(){
  wait(100,msec);
  double BrainTime = Brain.Timer.system() * 1000;
  double BrainVoltage = Brain.Battery.voltage();
  // Combine these values into a single integer
  int seed = int(
    BrainTime + BrainVoltage
  );
  // Set the seed
  srand(seed); 
}



void vexcodeInit() {

  // Initializing random seed.
  initializeRandomSeed(); 
}


// Generated code.

// Include the IQ Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

// User defined function
void moveSnake();
// User defined function
void myblockfunction_moveSnake_deleteLastPiece();
// User defined function
void myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection(double myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__x, double myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__y, double myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__lastDirection);
// User defined function
void myblockfunction_renderBoard();
// User defined function
void myblockfunction_renderBoard_drawScore();

int Brain_precision = 0;

float snakeLength, snakeDir, renderPosX, renderPosY, movementSpeed, nearestPartIndex, youDied, score, scoreIndex, scoreCalc, scoreSave, lastPieceCoordsX, lastPieceCoordsY, lastPieceCoordsUsed, lastPieceCoordsXloop, lastPieceCoordsYloop;

float Board[5][20];
float lastPieceCoords[20][4];
float snakeHeadPos[2];
float renderChars[4];
float lastPieceLoopPos[2];
float realLastPieceCoords[2];

// User defined function
void myblockfunction_moveSnake() {
  if (snakeDir == 0.0) {
    snakeHeadPos[static_cast<int>(1) - 1] = snakeHeadPos[static_cast<int>(1) - 1] + 1.0;
  }
  if (snakeDir == 1.0) {
    snakeHeadPos[static_cast<int>(2) - 1] = snakeHeadPos[static_cast<int>(2) - 1] + 1.0;
  }
  if (snakeDir == 2.0) {
    snakeHeadPos[static_cast<int>(1) - 1] = snakeHeadPos[static_cast<int>(1) - 1] + -1.0;
  }
  if (snakeDir == 3.0) {
    snakeHeadPos[static_cast<int>(2) - 1] = snakeHeadPos[static_cast<int>(2) - 1] + -1.0;
  }
  // check for apple
  if (Board[static_cast<int>(snakeHeadPos[static_cast<int>(2) - 1]) - 1][static_cast<int>(snakeHeadPos[static_cast<int>(1) - 1]) - 1] == 3.0) {
    snakeLength = snakeLength + 1.0;
    score = score + 25.0;
  }
  // check for collisions
  if (Board[static_cast<int>(snakeHeadPos[static_cast<int>(2) - 1]) - 1][static_cast<int>(snakeHeadPos[static_cast<int>(1) - 1]) - 1] == 2.0) {
    Board[static_cast<int>(snakeHeadPos[static_cast<int>(2) - 1]) - 1][static_cast<int>(snakeHeadPos[static_cast<int>(1) - 1]) - 1] = 1;
    myblockfunction_moveSnake_deleteLastPiece();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("You died!");
    youDied = 1.0;
  }
  // replace head piece and delete last piece
  Board[static_cast<int>(snakeHeadPos[static_cast<int>(2) - 1]) - 1][static_cast<int>(snakeHeadPos[static_cast<int>(1) - 1]) - 1] = 1;
  lastPieceCoordsX = 1.0;
  lastPieceCoordsY = 1.0;
  myblockfunction_moveSnake_deleteLastPiece();
}

// User defined function
void myblockfunction_moveSnake_deleteLastPiece() {
  lastPieceCoords[0][0] = 0.0;
  lastPieceCoords[0][1] = 0.0;
  lastPieceCoords[0][2] = 0.0;
  lastPieceCoords[0][3] = 0.0;
  lastPieceCoords[1][0] = 0.0;
  lastPieceCoords[1][1] = 0.0;
  lastPieceCoords[1][2] = 0.0;
  lastPieceCoords[1][3] = 0.0;
  lastPieceCoords[2][0] = 0.0;
  lastPieceCoords[2][1] = 0.0;
  lastPieceCoords[2][2] = 0.0;
  lastPieceCoords[2][3] = 0.0;
  lastPieceCoords[3][0] = 0.0;
  lastPieceCoords[3][1] = 0.0;
  lastPieceCoords[3][2] = 0.0;
  lastPieceCoords[3][3] = 0.0;
  lastPieceCoords[4][0] = 0.0;
  lastPieceCoords[4][1] = 0.0;
  lastPieceCoords[4][2] = 0.0;
  lastPieceCoords[4][3] = 0.0;
  lastPieceCoords[5][0] = 0.0;
  lastPieceCoords[5][1] = 0.0;
  lastPieceCoords[5][2] = 0.0;
  lastPieceCoords[5][3] = 0.0;
  lastPieceCoords[6][0] = 0.0;
  lastPieceCoords[6][1] = 0.0;
  lastPieceCoords[6][2] = 0.0;
  lastPieceCoords[6][3] = 0.0;
  lastPieceCoords[7][0] = 0.0;
  lastPieceCoords[7][1] = 0.0;
  lastPieceCoords[7][2] = 0.0;
  lastPieceCoords[7][3] = 0.0;
  lastPieceCoords[8][0] = 0.0;
  lastPieceCoords[8][1] = 0.0;
  lastPieceCoords[8][2] = 0.0;
  lastPieceCoords[8][3] = 0.0;
  lastPieceCoords[9][0] = 0.0;
  lastPieceCoords[9][1] = 0.0;
  lastPieceCoords[9][2] = 0.0;
  lastPieceCoords[9][3] = 0.0;
  lastPieceCoords[10][0] = 0.0;
  lastPieceCoords[10][1] = 0.0;
  lastPieceCoords[10][2] = 0.0;
  lastPieceCoords[10][3] = 0.0;
  lastPieceCoords[11][0] = 0.0;
  lastPieceCoords[11][1] = 0.0;
  lastPieceCoords[11][2] = 0.0;
  lastPieceCoords[11][3] = 0.0;
  lastPieceCoords[12][0] = 0.0;
  lastPieceCoords[12][1] = 0.0;
  lastPieceCoords[12][2] = 0.0;
  lastPieceCoords[12][3] = 0.0;
  lastPieceCoords[13][0] = 0.0;
  lastPieceCoords[13][1] = 0.0;
  lastPieceCoords[13][2] = 0.0;
  lastPieceCoords[13][3] = 0.0;
  lastPieceCoords[14][0] = 0.0;
  lastPieceCoords[14][1] = 0.0;
  lastPieceCoords[14][2] = 0.0;
  lastPieceCoords[14][3] = 0.0;
  lastPieceCoords[15][0] = 0.0;
  lastPieceCoords[15][1] = 0.0;
  lastPieceCoords[15][2] = 0.0;
  lastPieceCoords[15][3] = 0.0;
  lastPieceCoords[16][0] = 0.0;
  lastPieceCoords[16][1] = 0.0;
  lastPieceCoords[16][2] = 0.0;
  lastPieceCoords[16][3] = 0.0;
  lastPieceCoords[17][0] = 0.0;
  lastPieceCoords[17][1] = 0.0;
  lastPieceCoords[17][2] = 0.0;
  lastPieceCoords[17][3] = 0.0;
  lastPieceCoords[18][0] = 0.0;
  lastPieceCoords[18][1] = 0.0;
  lastPieceCoords[18][2] = 0.0;
  lastPieceCoords[18][3] = 0.0;
  lastPieceCoords[19][0] = 0.0;
  lastPieceCoords[19][1] = 0.0;
  lastPieceCoords[19][2] = 0.0;
  lastPieceCoords[19][3] = 0.0;lastPieceLoopPos[0] = snakeHeadPos[static_cast<int>(2) - 1];
  lastPieceLoopPos[1] = snakeHeadPos[static_cast<int>(1) - 1];nearestPartIndex = snakeDir;
  myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection(lastPieceLoopPos[static_cast<int>(1) - 1], lastPieceLoopPos[static_cast<int>(2) - 1], nearestPartIndex);
  if (nearestPartIndex == 0.0) {
    lastPieceLoopPos[static_cast<int>(2) - 1] = lastPieceLoopPos[static_cast<int>(2) - 1] + -1.0;
  }
  if (nearestPartIndex == 1.0) {
    lastPieceLoopPos[static_cast<int>(1) - 1] = lastPieceLoopPos[static_cast<int>(1) - 1] + -1.0;
  }
  if (nearestPartIndex == 2.0) {
    lastPieceLoopPos[static_cast<int>(2) - 1] = lastPieceLoopPos[static_cast<int>(2) - 1] + 1.0;
  }
  if (nearestPartIndex == 3.0) {
    lastPieceLoopPos[static_cast<int>(1) - 1] = lastPieceLoopPos[static_cast<int>(1) - 1] + 1.0;
  }
  Board[static_cast<int>(lastPieceLoopPos[static_cast<int>(1) - 1]) - 1][static_cast<int>(lastPieceLoopPos[static_cast<int>(2) - 1]) - 1] = 2;
  repeat(snakeLength - 1.0) {
    myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection(lastPieceLoopPos[static_cast<int>(1) - 1], lastPieceLoopPos[static_cast<int>(2) - 1], nearestPartIndex);
    if (nearestPartIndex == 0.0) {
      lastPieceLoopPos[static_cast<int>(2) - 1] = lastPieceLoopPos[static_cast<int>(2) - 1] + -1.0;
    }
    if (nearestPartIndex == 1.0) {
      lastPieceLoopPos[static_cast<int>(1) - 1] = lastPieceLoopPos[static_cast<int>(1) - 1] + -1.0;
    }
    if (nearestPartIndex == 2.0) {
      lastPieceLoopPos[static_cast<int>(2) - 1] = lastPieceLoopPos[static_cast<int>(2) - 1] + 1.0;
    }
    if (nearestPartIndex == 3.0) {
      lastPieceLoopPos[static_cast<int>(1) - 1] = lastPieceLoopPos[static_cast<int>(1) - 1] + 1.0;
    }
    wait(20, msec);
  }
  Board[static_cast<int>(lastPieceLoopPos[static_cast<int>(1) - 1]) - 1][static_cast<int>(lastPieceLoopPos[static_cast<int>(2) - 1]) - 1] = 0;
}

// User defined function
void myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection(double myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__x, double myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__y, double myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__lastDirection) {
  // sets nearestPartIndex
  // 0 = up
  // 1 = right
  // 2 = down
  // 3 = left
  lastPieceCoordsUsed = 1.0;
  realLastPieceCoords[0] = 0.0;
  realLastPieceCoords[1] = 0.0;while (!(lastPieceCoordsUsed == 0.0)) {
    if (Board[static_cast<int>(myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__y + 1.0) - 1][static_cast<int>(myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__x) - 1] == 2.0 && !(myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__lastDirection == 2.0)) {
      nearestPartIndex = 0.0;
      realLastPieceCoords[0] = myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__x;
      realLastPieceCoords[1] = myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__y + 1.0;}
    if (Board[static_cast<int>(myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__y) - 1][static_cast<int>(myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__x + 1.0) - 1] == 2.0 && !(myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__lastDirection == 3.0)) {
      nearestPartIndex = 1.0;
      realLastPieceCoords[0] = myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__x + 1.0;
      realLastPieceCoords[1] = myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__y;}
    if (Board[static_cast<int>(myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__y + -1.0) - 1][static_cast<int>(myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__x) - 1] == 2.0 && !(myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__lastDirection == 0.0)) {
      nearestPartIndex = 2.0;
      realLastPieceCoords[0] = myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__x;
      realLastPieceCoords[1] = myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__y + -1.0;}
    if (Board[static_cast<int>(myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__y) - 1][static_cast<int>(myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__x + -1.0) - 1] == 2.0 && !(myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__lastDirection == 1.0)) {
      nearestPartIndex = 3.0;
      realLastPieceCoords[0] = myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__x + -1.0;
      realLastPieceCoords[1] = myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__y;}
    lastPieceCoordsXloop = 1.0;
    lastPieceCoordsYloop = 1.0;
    repeat(40) {
      if (!(lastPieceCoords[static_cast<int>(lastPieceCoordsYloop) - 1][static_cast<int>(lastPieceCoordsXloop) - 1] == realLastPieceCoords[static_cast<int>(1) - 1] && lastPieceCoords[static_cast<int>(lastPieceCoordsYloop) - 1][static_cast<int>(lastPieceCoordsXloop + 1.0) - 1] == realLastPieceCoords[static_cast<int>(2) - 1])) {
        lastPieceCoordsUsed = 0.0;
        break;
      }
      lastPieceCoordsYloop = lastPieceCoordsYloop + 1.0;
      if (lastPieceCoordsYloop == 21.0) {
        lastPieceCoordsYloop = 1.0;
        lastPieceCoordsXloop = lastPieceCoordsXloop + 2.0;
      }
      wait(20, msec);
    }
  wait(20, msec);
  }
  lastPieceCoords[static_cast<int>(renderPosY) - 1][static_cast<int>(renderPosX) - 1] = myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__x;
  lastPieceCoordsX = lastPieceCoordsX + 1.0;
  lastPieceCoords[static_cast<int>(renderPosY) - 1][static_cast<int>(renderPosX) - 1] = myblockfunction_moveSnake_searchForNearestPart_x_y_lastDirection__y;
  lastPieceCoordsX = lastPieceCoordsX + 1.0;
  if (lastPieceCoordsX == 5.0) {
    lastPieceCoordsX = 1.0;
    lastPieceCoordsY = lastPieceCoordsY + 1.0;
  }
}

// User defined function
void myblockfunction_renderBoard() {
  renderPosY = 1.0;
  repeat(5) {
    renderPosX = 1.0;
    repeat(20) {
      Brain.Screen.setCursor(renderPosY, renderPosX);
      if (Board[static_cast<int>(renderPosY) - 1][static_cast<int>(renderPosX) - 1] == 0.0) {
        Brain.Screen.print(" ");
      }
      if (Board[static_cast<int>(renderPosY) - 1][static_cast<int>(renderPosX) - 1] == 1.0) {
        Brain.Screen.print("+");
      }
      if (Board[static_cast<int>(renderPosY) - 1][static_cast<int>(renderPosX) - 1] == 2.0) {
        Brain.Screen.print("*");
      }
      if (Board[static_cast<int>(renderPosY) - 1][static_cast<int>(renderPosX) - 1] == 3.0) {
        Brain.Screen.print("O");
      }
      renderPosX = renderPosX + 1.0;
      wait(20, msec);
    }
    renderPosY = renderPosY + 1.0;
    wait(20, msec);
  }
  myblockfunction_renderBoard_drawScore();
}

// Used to find the format string for printing numbers with the
// desired number of decimal places
const char* printToBrain_numberFormat() {
  // look at the current precision setting to find the format string
  switch(Brain_precision){
    case 0:  return "%.0f"; // 0 decimal places (1)
    case 1:  return "%.1f"; // 1 decimal place  (0.1)
    case 2:  return "%.2f"; // 2 decimal places (0.01)
    case 3:  return "%.3f"; // 3 decimal places (0.001)
    default: return "%f"; // use the print system default for everthing else
  }
}

// User defined function
void myblockfunction_renderBoard_drawScore() {
  scoreIndex = 1.0;
  scoreCalc = score;
  repeat(5) {
    scoreSave = floor(scoreCalc / pow(10, 5.0 - scoreIndex));
    Brain.Screen.setCursor(scoreIndex, 21);
    Brain.Screen.print(printToBrain_numberFormat(), static_cast<float>(scoreSave));
    scoreCalc = scoreCalc + scoreSave * -1.0;
    scoreIndex = scoreIndex + 1.0;
    wait(20, msec);
  }
}

// "when started" hat block
int whenStarted1() {
  // render area = 21 x 5
  // data types:
  // 0 = nothing
  // 1 = snake head
  // 2 = snake body
  // 3 = fruit
  // snake directions:
  // 0 = up
  // 1 = right
  // 2 = down
  // 3 = left
  Board[0][0] = 0.0;
  Board[0][1] = 0.0;
  Board[0][2] = 0.0;
  Board[0][3] = 0.0;
  Board[0][4] = 0.0;
  Board[0][5] = 0.0;
  Board[0][6] = 0.0;
  Board[0][7] = 0.0;
  Board[0][8] = 0.0;
  Board[0][9] = 0.0;
  Board[0][10] = 0.0;
  Board[0][11] = 0.0;
  Board[0][12] = 0.0;
  Board[0][13] = 0.0;
  Board[0][14] = 0.0;
  Board[0][15] = 0.0;
  Board[0][16] = 0.0;
  Board[0][17] = 0.0;
  Board[0][18] = 0.0;
  Board[0][19] = 0.0;
  Board[1][0] = 0.0;
  Board[1][1] = 0.0;
  Board[1][2] = 0.0;
  Board[1][3] = 0.0;
  Board[1][4] = 0.0;
  Board[1][5] = 0.0;
  Board[1][6] = 0.0;
  Board[1][7] = 0.0;
  Board[1][8] = 0.0;
  Board[1][9] = 0.0;
  Board[1][10] = 0.0;
  Board[1][11] = 0.0;
  Board[1][12] = 0.0;
  Board[1][13] = 0.0;
  Board[1][14] = 0.0;
  Board[1][15] = 0.0;
  Board[1][16] = 0.0;
  Board[1][17] = 0.0;
  Board[1][18] = 0.0;
  Board[1][19] = 0.0;
  Board[2][0] = 0.0;
  Board[2][1] = 0.0;
  Board[2][2] = 2.0;
  Board[2][3] = 2.0;
  Board[2][4] = 1.0;
  Board[2][5] = 0.0;
  Board[2][6] = 0.0;
  Board[2][7] = 0.0;
  Board[2][8] = 0.0;
  Board[2][9] = 0.0;
  Board[2][10] = 0.0;
  Board[2][11] = 0.0;
  Board[2][12] = 0.0;
  Board[2][13] = 0.0;
  Board[2][14] = 0.0;
  Board[2][15] = 3.0;
  Board[2][16] = 0.0;
  Board[2][17] = 0.0;
  Board[2][18] = 0.0;
  Board[2][19] = 0.0;
  Board[3][0] = 0.0;
  Board[3][1] = 0.0;
  Board[3][2] = 0.0;
  Board[3][3] = 0.0;
  Board[3][4] = 0.0;
  Board[3][5] = 0.0;
  Board[3][6] = 0.0;
  Board[3][7] = 0.0;
  Board[3][8] = 0.0;
  Board[3][9] = 0.0;
  Board[3][10] = 0.0;
  Board[3][11] = 0.0;
  Board[3][12] = 0.0;
  Board[3][13] = 0.0;
  Board[3][14] = 0.0;
  Board[3][15] = 0.0;
  Board[3][16] = 0.0;
  Board[3][17] = 0.0;
  Board[3][18] = 0.0;
  Board[3][19] = 0.0;
  Board[4][0] = 0.0;
  Board[4][1] = 0.0;
  Board[4][2] = 0.0;
  Board[4][3] = 0.0;
  Board[4][4] = 0.0;
  Board[4][5] = 0.0;
  Board[4][6] = 0.0;
  Board[4][7] = 0.0;
  Board[4][8] = 0.0;
  Board[4][9] = 0.0;
  Board[4][10] = 0.0;
  Board[4][11] = 0.0;
  Board[4][12] = 0.0;
  Board[4][13] = 0.0;
  Board[4][14] = 0.0;
  Board[4][15] = 0.0;
  Board[4][16] = 0.0;
  Board[4][17] = 0.0;
  Board[4][18] = 0.0;
  Board[4][19] = 0.0;snakeLength = 3.0;
  snakeHeadPos[0] = 5.0;
  snakeHeadPos[1] = 3.0;snakeDir = 0.0;
  movementSpeed = 30.0;
  youDied = 0.0;
  score = 0.0;
  while (true) {
    myblockfunction_renderBoard();
    myblockfunction_moveSnake();
    if (youDied == 1.0) {
      break;
    }
    score = score + 1.0;
  wait(20, msec);
  }
  return 0;
}

// "when buttonUp pressed" hat block
void onevent_buttonUp_pressed_0() {
  snakeDir = snakeDir + -1.0;
  if (snakeDir == -1.0) {
    snakeDir = 3.0;
  }
}

// "when buttonDown pressed" hat block
void onevent_buttonDown_pressed_0() {
  snakeDir = snakeDir + 1.0;
  if (snakeDir == 4.0) {
    snakeDir = 0.0;
  }
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // register event handlers
  Brain.buttonUp.pressed(onevent_buttonUp_pressed_0);
  Brain.buttonDown.pressed(onevent_buttonDown_pressed_0);

  wait(15, msec);
  whenStarted1();
}