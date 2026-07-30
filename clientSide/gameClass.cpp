#include <vector>
#include <iostream>
#include "gameClass.hpp"
#include "definitions.cpp"

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
bool TicTacToe::makeMove(int x, int y) {
    int movesBefore = this->getMoveCount();
    int stateBefore = this->getFieldState(x,y);
    this->updateMoveCount();
    int movesMade = this->getMoveCount();
    int symbol = ((movesMade % 2)) ? Xmark : Omark;
    this->setFieldState(x, y, symbol);
    return (movesBefore != this->getMoveCount() && stateBefore != this->getFieldState(x,y));
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
    
    for (int i = 0; i < BOARD_FIELDS_X; i++) {
        for (int j = 0; j < BOARD_FIELDS_Y; j++) {
            if (this->logicBoard[i][j] == EMPTY) return 0;
        }
    }
    return TIE;
}

void TicTacToe::setWinner(char newWinner) {
    if(this->winner == 'n') this->winner = newWinner;
}

char TicTacToe::getWinner() {
    return this->winner;
}

void TicTacToe::updateOwins() {
    this->Owins++;
}

void TicTacToe::updateXwins() {
    this->Xwins++;
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

int TicTacToe::getOwins() {
    return this->Owins;
}

int TicTacToe::getXwins() {
    return this->Xwins;
}

void TicTacToe::clearBoard() {
    std::vector<std::vector<int>> newLogicBoard(3, std::vector<int>(3,0));
    this->logicBoard = newLogicBoard;
}