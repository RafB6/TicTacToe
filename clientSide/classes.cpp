#include <vector>
#include <iostream>
#include "classes.hpp"

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
    this->logicBoard[x][y] = newState;
}
int TicTacToe::getMoveCount() {
    return moveCount;
}
