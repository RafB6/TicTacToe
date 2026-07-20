#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <string>



#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800


int main()
{
    //window render
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Display window");
    float WindowHeight = float(WINDOW_HEIGHT);
    float WindowWidth = float(WINDOW_WIDTH);
    
    //Circle object
    sf::CircleShape testCircle(100.f, 200);
    testCircle.setFillColor(sf::Color::Black);
    testCircle.setOutlineColor(sf::Color::White);
    testCircle.setOutlineThickness(10.f);
    testCircle.setPosition(0.f,0.f);
    sf::Vector2f changeInPosition(200.f, 10.f);
    testCircle.move(changeInPosition);
    
    //Square object
    sf::RectangleShape centerSquare({100.f, 100.f});
    centerSquare.setFillColor(sf::Color::Red);
    centerSquare.setOutlineColor(sf::Color::Green);
    sf::Vector2f centerPoint = {(WINDOW_HEIGHT / 2) - (centerSquare.getSize().y / 2), (WINDOW_WIDTH / 2) - centerSquare.getSize().x / 2};
    centerSquare.setPosition(centerPoint);
    sf::Vector2f centerSquareSize = centerSquare.getSize();
    centerSquare.rotate(0.f);

    //Cursour
    sf::Cursor cursor;
    if (cursor.loadFromSystem(sf::Cursor::Hand)) window.setMouseCursor(cursor);
    
    //Frame limit
    window.setFramerateLimit(5);

    float changeInX = 20.f;
    float changeInY = 20.f;

    //event loop
    while (window.isOpen()) {
        sf::Event event;
        //close event
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) window.close();

            sf::Vector2f currentCenterSquarePosition = centerSquare.getPosition();
            
            //check if button pressed
            if (event.type == sf::Event::MouseButtonPressed) {
                //check which button was pressed
                if (event.mouseButton.button == sf::Mouse::Left) {

                    
                    centerSquare.move(changeInX, changeInY);
                    
                    if (currentCenterSquarePosition.x + changeInX < 0) {
                        centerSquare.setPosition(0, currentCenterSquarePosition.y + changeInY);
                        changeInX *= -1;
                    } else if (currentCenterSquarePosition.x + centerSquareSize.x + changeInX > WindowWidth) {
                        centerSquare.setPosition(WindowWidth - centerSquareSize.x, currentCenterSquarePosition.y + changeInY);
                        changeInX *= -1;
                    } if (currentCenterSquarePosition.y + changeInY < 0) {
                        centerSquare.setPosition(currentCenterSquarePosition.x + changeInX, 0);
                        changeInY *= -1;
                    } else if (currentCenterSquarePosition.y + centerSquareSize.y + changeInY > WindowHeight) {
                        centerSquare.setPosition(currentCenterSquarePosition.x + changeInX, WindowHeight - centerSquareSize.y);
                        changeInY *= -1;
                    }
                }
            }
        }


        window.clear(sf::Color::Black);
        window.draw(testCircle);
        window.draw(centerSquare);
        window.display();
    }
    return 0;
}