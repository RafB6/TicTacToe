#include <SFML/Graphics.hpp>
#include <iostream>

sf::RectangleShape createField();
bool clickOntoField(int xclick, int yclick, sf::RectangleShape currField);
sf::Text createTextOnField(int sign, sf::RectangleShape *currField, const sf::Font &font);
sf::Text createEndMessage(int winner, sf::RectangleShape *messageBackground, const sf::Font &font);
sf::RectangleShape createMessageBackground();
std::vector<std::vector<sf::Text>> updateExistingFields(std::vector<std::vector<sf::Text>> Symbols, TicTacToe currGame);
sf::Text createScoreboardText(TicTacToe currGame, const sf::Font &font, sf::RectangleShape background);
sf::RectangleShape createScoreboardBackground();
std::string intToStr(int number);