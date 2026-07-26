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

#define BOARD_FIELDS_X 3
#define BOARD_FIELDS_Y 3

//FIELD STATE
#define EMPTY 0
#define Xmark 1
#define Omark 2

#define FONT_SIZE 80

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800

const float FIELD_HEIGHT = 200.f;
const float FIELD_WIDTH = 200.f;


sf::RectangleShape createField() {
    sf::RectangleShape field({FIELD_HEIGHT, FIELD_WIDTH});
    field.setOutlineColor(sf::Color::Blue);
    field.setOutlineThickness(1.f);
    field.setFillColor(sf::Color::Black);
    
    return field;
}


bool clickOntoField(int xclick, int yclick, sf::RectangleShape currField) {
    return (xclick >= currField.getPosition().x && xclick <= currField.getPosition().x + FIELD_WIDTH && yclick >= currField.getPosition().y && yclick <= currField.getPosition().y + FIELD_HEIGHT);
}

sf::Text createTextOnField(int sign, sf::RectangleShape *currField, const sf::Font &font) {
    char symbol;
    if (sign == Xmark) symbol = 'X'; 
    else symbol = 'O';
    sf::Text newText(symbol, font, FONT_SIZE);
    sf::FloatRect textBounds = newText.getLocalBounds();
    newText.setOrigin(textBounds.left + (textBounds.width / 2.f), (textBounds.top + textBounds.height / 2.f));
    
    sf::FloatRect fieldBounds = currField->getGlobalBounds();
    newText.setPosition(fieldBounds.left + (fieldBounds.width / 2.f), fieldBounds.top + (fieldBounds.height / 2.f));

    newText.setFillColor(sf::Color::Blue);

    return newText;
}
