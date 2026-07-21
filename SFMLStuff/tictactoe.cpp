#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <math.h>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

const float FIELD_HEIGHT = 200.f;
const float FIELD_WIDTH = 200.f;

sf::RectangleShape createField();



int main(void) {
    
    //window render
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "TIC TAC TOE");
    
    //Frame limit
    window.setFramerateLimit(10);
    
    //Cursor, why not
    sf::Cursor cursor;
    if (cursor.loadFromSystem(sf::Cursor::Hand)) window.setMouseCursor(cursor);
    
    //OBJECTS
    
    //Board
    sf::RectangleShape Board({600.f, 600.f});
    Board.setFillColor(sf::Color::Blue);
    
    // NINE FIELDS


    sf::RectangleShape topLeft = createField();

    sf::RectangleShape topCenter = createField();
    topCenter.setPosition(FIELD_WIDTH, 0);

    sf::RectangleShape topRight = createField();
    topRight.setPosition(FIELD_WIDTH * 2, 0);

    sf::RectangleShape middleLeft = createField();
    middleLeft.setPosition(0, FIELD_HEIGHT);

    sf::RectangleShape middleCenter = createField();
    middleCenter.setPosition(FIELD_WIDTH, FIELD_HEIGHT);

    sf::RectangleShape middleRight = createField();
    middleRight.setPosition(2 * FIELD_WIDTH, FIELD_HEIGHT);

    sf::RectangleShape bottomLeft = createField();
    bottomLeft.setPosition(0, 2 * FIELD_HEIGHT);

    sf::RectangleShape bottomCenter = createField();
    bottomCenter.setPosition(FIELD_WIDTH, 2 * FIELD_HEIGHT);

    sf::RectangleShape bottomRight = createField();
    bottomRight.setPosition(2 * FIELD_WIDTH, 2 * FIELD_HEIGHT);
    //TO BE SEPARATED TO A DIFFERENT FILE 


    std::vector<std::vector<int>> logicBoard;




    //THE LOOP
    while (window.isOpen()) {
        sf::Event event;

        // EVENT LOOP
        while(window.pollEvent(event)) {

            //handling of closing the game
            if (event.type == sf::Event::Closed) window.close();

            

        }

        window.clear(sf::Color::White);
        window.draw(Board);
        window.draw(topLeft);
        window.draw(topCenter);
        window.draw(topRight);
        window.draw(middleLeft);
        window.draw(middleCenter);
        window.draw(middleRight);
        window.draw(bottomLeft);
        window.draw(bottomCenter);
        window.draw(bottomRight);
        window.display();
    }
}


sf::RectangleShape createField() {
    sf::RectangleShape field({FIELD_HEIGHT, FIELD_WIDTH});
    field.setOutlineColor(sf::Color::Black);
    field.setOutlineThickness(1.f);
    field.setFillColor(sf::Color::Magenta);

    return field;
}