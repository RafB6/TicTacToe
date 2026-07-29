#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <math.h>
#include "gameClass.hpp"
#include "helperFunctions.hpp"
#include "definitions.cpp"

const float FIELD_HEIGHT = 200.f;
const float FIELD_WIDTH = 200.f;


int main(void) {
    
    //window render
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "TIC TAC TOE", sf::Style::Titlebar | sf::Style::Close);
    
    sf::Font font;
    font.loadFromFile("Arial.ttf");
    
    //Frame limit
    window.setFramerateLimit(10);
    
    //Cursor, why not
    sf::Cursor cursor;
    if (cursor.loadFromSystem(sf::Cursor::Hand)) window.setMouseCursor(cursor);
    
    //Board
    sf::RectangleShape Board({WINDOW_WIDTH, WINDOW_HEIGHT});
    Board.setFillColor(sf::Color::Black);

    //GAME
    TicTacToe GAME;

    
    //OBJECTS
    // NINE FIELDS
    sf::RectangleShape topLeft = createField();
    topLeft.setPosition(FIELD_WIDTH * 0.5, FIELD_HEIGHT * 0.5);

    sf::RectangleShape topCenter = createField();
    topCenter.setPosition(FIELD_WIDTH * 1.5, FIELD_HEIGHT * 0.5);

    sf::RectangleShape topRight = createField();
    topRight.setPosition(FIELD_WIDTH * 2.5, FIELD_HEIGHT * 0.5);

    sf::RectangleShape middleLeft = createField();
    middleLeft.setPosition(FIELD_WIDTH * 0.5, FIELD_HEIGHT * 1.5);

    sf::RectangleShape middleCenter = createField();
    middleCenter.setPosition(FIELD_WIDTH * 1.5, FIELD_HEIGHT * 1.5);

    sf::RectangleShape middleRight = createField();
    middleRight.setPosition(2.5 * FIELD_WIDTH, FIELD_HEIGHT * 1.5);

    sf::RectangleShape bottomLeft = createField();
    bottomLeft.setPosition(FIELD_WIDTH * 0.5, 2.5 * FIELD_HEIGHT);

    sf::RectangleShape bottomCenter = createField();
    bottomCenter.setPosition(FIELD_WIDTH * 1.5, 2.5 * FIELD_HEIGHT);

    sf::RectangleShape bottomRight = createField();
    bottomRight.setPosition(2.5 * FIELD_WIDTH, 2.5 * FIELD_HEIGHT);

    //OBJECT ARRAY
    std::vector<std::vector<sf::RectangleShape>> Fields(BOARD_FIELDS_X, std::vector<sf::RectangleShape>(BOARD_FIELDS_Y));
    Fields[TOP][LEFT] = topLeft;
    Fields[TOP][CENTER] = topCenter;
    Fields[TOP][RIGHT] = topRight;
    Fields[MIDDLE][LEFT] = middleLeft;
    Fields[MIDDLE][CENTER] = middleCenter;
    Fields[MIDDLE][RIGHT] = middleRight;
    Fields[BOTTOM][LEFT] = bottomLeft;
    Fields[BOTTOM][CENTER] = bottomCenter;
    Fields[BOTTOM][RIGHT] = bottomRight;

    //TEXT OBJECT ARRAY
    std::vector<std::vector<sf::Text>> Symbols(3, std::vector<sf::Text>(3));
    
    sf::Text winnerDeclarationMessage;
    sf::RectangleShape winnerDeclarationBackground;
    sf::RectangleShape scoreboardBG;
    sf::Text scoreboardText;

    //THE LOOP
    while (window.isOpen()) {
        sf::Event event;

        // EVENT LOOP
        while(window.pollEvent(event)) {

            //handling of closing the game
            if (event.type == sf::Event::Closed) window.close();

            //handling of Mouse Clicks
            if (event.type == sf::Event::MouseButtonPressed) {
                //handling of LMB
                if(event.mouseButton.button == sf::Mouse::Left) {
                    int xClick = event.mouseButton.x;
                    int yClick = event.mouseButton.y;
                    std::cout << "\t Mouse LEFT pressed: X: " << xClick << "\t"<< yClick << "\n";
                    
                    for (int x = 0; x < BOARD_FIELDS_X; x++) {
                        for (int y = 0; y < BOARD_FIELDS_Y; y++) {
                            
                            sf::RectangleShape *currField = &Fields[x][y];
                            
                            if (clickOntoField(xClick, yClick, *currField)) {
                                
                                std::cout << "CLICKED ONTO:\tx:" << x <<"\ty:" << y << std::endl;
                                
                                if (GAME.makeMove(x,y)) {

                                    std::cout << "\tMOVE MADE!!!" << std::endl;

                                    int nextSymbol = (GAME.getMoveCount() % 2) ? Xmark : Omark;

                                    Symbols[x][y] = createTextOnField(nextSymbol, currField, font);
                                    
                                    
                                } else std::cout << "Clicked onto non-empty FIELD" << std::endl;
                            }
                        }    
                    }
                    //HANDLING OF THE END OF THE GAME
                    int winner = GAME.hasWinner();
                    if (winner) {                        
                        if (winner == Xmark) GAME.updateXwins();
                        else if (winner == Omark) GAME.updateOwins();
                        winnerDeclarationBackground = createMessageBackground();
                        winnerDeclarationMessage = createEndMessage(winner, &winnerDeclarationBackground, font);
                    } else {
                        winnerDeclarationBackground = sf::RectangleShape({0.f, 0.f});
                        winnerDeclarationMessage = createEndMessage(EMPTY, &winnerDeclarationBackground, font);
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Right) {
                    std::cout << "New game" << std::endl;
                    GAME.clearBoard();
                    winnerDeclarationMessage.setString("");
                }
                Symbols = updateExistingFields(Symbols, &GAME);
            }
            scoreboardBG = createScoreboardBackground();
            scoreboardText = createScoreboardText(GAME, font, scoreboardBG);
        }
        
        window.clear(sf::Color::Black);
        window.draw(Board);
        for (int hori = 0; hori < BOARD_FIELDS_X; hori++) {
            for (int vert = 0; vert < BOARD_FIELDS_Y; vert++) {
                window.draw(Fields[hori][vert]);
                window.draw(Symbols[hori][vert]);
            }
        }
        if (winnerDeclarationMessage.getString() != "") {
            window.draw(winnerDeclarationBackground);
            window.draw(winnerDeclarationMessage);
        }
        window.draw(scoreboardBG);
        window.draw(scoreboardText);
        window.display();
    }
}