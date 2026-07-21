#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <math.h>
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

int main(void) {

    TicTacToe game;
    int movesMade;


    while (!game.hasWinner()){

        //REGISTER NEW MOVE
        game.updateMoveCount();
        movesMade = game.getMoveCount();
        int newVertical;
        int newHorizontal;
        //FILL THE FIELD
        std::cout << "SELECT FIELD [0 = TOP, 1 = MIDDLE, 2 = BOTTOM][0 = LEFT, 1 = CENTER, 2 = RIGHT]" << "\t";
        
        // VALIDATE INPUT
        while (!(std::cin >> newVertical) || !(std::cin >> newHorizontal) || newVertical < 0 || newVertical > 2 || newHorizontal < 0 || newHorizontal > 2) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong input, try again: ";
        }

        //MAKE MOVE
        if (movesMade % 2 == 0) game.setFieldState(newHorizontal,newVertical,Xmark);
        else game.setFieldState(newHorizontal,newVertical,Omark);
        
        //PRINT BOARD
        game.printBoard();

        //CHECK WINNER
        char currField = game.getFieldState(newHorizontal,newVertical) == Xmark ? 'X': 'O';
        if (game.hasWinner()) game.setWinner(currField);
    
        std::cout << "\n";
    }    
    std::cout << "Moves made in this match: " << movesMade << std::endl;
    std::cout << "The winner is: " << game.getWinner() << std::endl;
    
    return 0;
}