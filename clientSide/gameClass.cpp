#include <vector>
#include <iostream>
#include "gameClass.hpp"

//VERTICALS
#define TOP 0
#define MIDDLE 1
#define BOTTOM 2

// HORIZONTALS
#define LEFT 0
#define CENTER 1
#define RIGHT 2

//FIELD STATE
#define EMPTY 0
#define Xmark 1
#define Omark 2

TicTacToe::TicTacToe() {
    std::vector<std::vector<int>> newLogicBoard(3, std::vector<int>(3,0));
    this->logicBoard = newLogicBoard;        
}
void TicTacToe::updateMoveCount() {
    this->moveCount++;
}
int TicTacToe::getFieldState(int x, int y) {
    return this->logicBoard[x][y];
}
void TicTacToe::setFieldState(int x, int y, int newState) {
    if (this->logicBoard[x][y] == EMPTY) this->logicBoard[x][y] = newState;
}
int TicTacToe::getMoveCount() {
    return moveCount;
}
void TicTacToe::makeMove(int x, int y) {
    int movesMade = this->getMoveCount();
    int symbol = ((movesMade % 2)) ? Xmark : Omark;
    this->setFieldState(x, y, symbol);
}
int TicTacToe::hasWinner() {
    if(this->logicBoard[TOP][LEFT] == Xmark && this->logicBoard[TOP][CENTER] == Xmark && this->logicBoard[TOP][RIGHT] == Xmark) return Xmark;
    if(this->logicBoard[MIDDLE][LEFT] == Xmark && this->logicBoard[MIDDLE][CENTER] == Xmark && this->logicBoard[MIDDLE][RIGHT] == Xmark) return Xmark;
    if(this->logicBoard[BOTTOM][LEFT] == Xmark && this->logicBoard[BOTTOM][CENTER] == Xmark && this->logicBoard[BOTTOM][RIGHT] == Xmark) return Xmark;
    if(this->logicBoard[TOP][LEFT] == Xmark && this->logicBoard[MIDDLE][LEFT] == Xmark && this->logicBoard[BOTTOM][LEFT] == Xmark) return Xmark;
    if(this->logicBoard[TOP][CENTER] == Xmark && this->logicBoard[MIDDLE][CENTER] == Xmark && this->logicBoard[BOTTOM][CENTER] == Xmark) return Xmark;
    if(this->logicBoard[TOP][RIGHT] == Xmark && this->logicBoard[MIDDLE][RIGHT] == Xmark && this->logicBoard[BOTTOM][RIGHT] == Xmark) return Xmark;
    if(this->logicBoard[TOP][LEFT] == Xmark && this->logicBoard[MIDDLE][CENTER] == Xmark && this->logicBoard[BOTTOM][RIGHT] == Xmark) return Xmark;
    if(this->logicBoard[TOP][RIGHT] == Xmark && this->logicBoard[MIDDLE][CENTER] == Xmark && this->logicBoard[BOTTOM][LEFT] == Xmark) return Xmark;

    if(this->logicBoard[TOP][LEFT] == Omark && this->logicBoard[TOP][CENTER] == Omark && this->logicBoard[TOP][RIGHT] == Omark) return Omark;
    if(this->logicBoard[MIDDLE][LEFT] == Omark && this->logicBoard[MIDDLE][CENTER] == Omark && this->logicBoard[MIDDLE][RIGHT] == Omark) return Omark;
    if(this->logicBoard[BOTTOM][LEFT] == Omark && this->logicBoard[BOTTOM][CENTER] == Omark && this->logicBoard[BOTTOM][RIGHT] == Omark) return Omark;
    if(this->logicBoard[TOP][LEFT] == Omark && this->logicBoard[MIDDLE][LEFT] == Omark && this->logicBoard[BOTTOM][LEFT] == Omark) return Omark;
    if(this->logicBoard[TOP][CENTER] == Omark && this->logicBoard[MIDDLE][CENTER] == Omark && this->logicBoard[BOTTOM][CENTER] == Omark) return Omark;
    if(this->logicBoard[TOP][RIGHT] == Omark && this->logicBoard[MIDDLE][RIGHT] == Omark && this->logicBoard[BOTTOM][RIGHT] == Omark) return Omark;
    if(this->logicBoard[TOP][LEFT] == Omark && this->logicBoard[MIDDLE][CENTER] == Omark && this->logicBoard[BOTTOM][RIGHT] == Omark) return Omark;
    if(this->logicBoard[TOP][RIGHT] == Omark && this->logicBoard[MIDDLE][CENTER] == Omark && this->logicBoard[BOTTOM][LEFT] == Omark) return Omark;    
    return 0;
}

void TicTacToe::setWinner(char newWinner) {
    if(this->winner == 'n') this->winner = newWinner;
}

char TicTacToe::getWinner() {
    return this->winner;
}

void TicTacToe::printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int currState = this->getFieldState(i,j);
            char symbol;
            if (currState == EMPTY) symbol = '_';
            else if (currState == Xmark) symbol = 'X';
            else if (currState == Omark) symbol = 'O';
            std::cout << symbol << "\t";
        }
        std::cout << std::endl;
    }
}