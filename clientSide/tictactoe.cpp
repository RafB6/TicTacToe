#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <math.h>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800
#define FIELD_HEIGHT 200
#define FIELD_WIDTH 200

int main(void) {

    //window render
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "TIC TAC TOE");
    
    //Frame limit
    window.setFramerateLimit(10);

    //OBJECTS
    //Board
    sf::RectangleShape Board({600.f, 600.f});
    Board.setFillColor(sf::Color::Blue);
    
    // NINE SUBFIELDS
    sf::RectangleShape topLeft({FIELD_HEIGHT, FIELD_WIDTH});

    sf::RectangleShape topCenter({FIELD_HEIGHT, FIELD_WIDTH});
    sf::RectangleShape topRight({FIELD_HEIGHT, FIELD_WIDTH});
    sf::RectangleShape middleRight({FIELD_HEIGHT, FIELD_WIDTH});
    sf::RectangleShape middleCenter({FIELD_HEIGHT, FIELD_WIDTH});
    sf::RectangleShape middleLeft({FIELD_HEIGHT, FIELD_WIDTH});
    sf::RectangleShape bottomRight({FIELD_HEIGHT, FIELD_WIDTH});
    sf::RectangleShape bottomCenter({FIELD_HEIGHT, FIELD_WIDTH});
    sf::RectangleShape bottomLeft({FIELD_HEIGHT, FIELD_WIDTH});
    //TO BE SEPARATED TO A DIFFERENT FILE 
    
    //Cursor, why not
    sf::Cursor cursor;
    if (cursor.loadFromSystem(sf::Cursor::Hand)) window.setMouseCursor(cursor);
    

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
        window.display();
    }
}


sf::RectangleShape createField() {
    sf::RectangleShape field({FIELD_HEIGHT, FIELD_WIDTH});
    field.setOutlineColor(sf::Color::Black);
}