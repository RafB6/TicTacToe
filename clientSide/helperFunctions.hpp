#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <math.h>

//VERTICALS
#define TOP 0
#define MIDDLE 1
#define BOTTOM 2

// HORIZONTALS
#define LEFT 0
#define CENTER 1
#define RIGHT 2

#define BOARD_FIELDS_X 3
#define BOARD_FIELDS_Y 3

//FIELD STATE
#define EMPTY 0
#define Xmark 1
#define Omark 2

#define FONT_SIZE 80

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800

sf::RectangleShape createField();
bool clickOntoField(int xclick, int yclick, sf::RectangleShape currField);
sf::Text createTextOnField(int sign, sf::RectangleShape *currField, const sf::Font &font);
