#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <math.h>
#include "classes.hpp"

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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            game.updateMoveCount();
            movesMade = game.getMoveCount();

            if (movesMade % 2 == 0) game.setFieldState(i,j,Xmark);
            else game.setFieldState(i,j,Omark);

            std::cout << game.getFieldState(i,j) << "\t";
        }
        std::cout << "\n";
    }
    std::cout << movesMade << std::endl;


    return 0;
}
