#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
#include "gameClass.hpp"
#include "definitions.cpp"

const float FIELD_HEIGHT = 200.f;
const float FIELD_WIDTH = 200.f;


sf::RectangleShape createField() {
    sf::RectangleShape field({FIELD_HEIGHT, FIELD_WIDTH});
    field.setOutlineColor(sf::Color::Blue);
    field.setOutlineThickness(5.f);
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

sf::RectangleShape createMessageBackground() {
    sf::RectangleShape messageBackground = sf::RectangleShape({500.f,500.f});
    messageBackground.setFillColor(sf::Color::Black);
    messageBackground.setOutlineColor(sf::Color::Blue);
    messageBackground.setOutlineThickness(1.f);
    sf::FloatRect messageBackgroundBounds = messageBackground.getGlobalBounds();
    messageBackground.setPosition((FIELD_WIDTH * 0.75f), (FIELD_HEIGHT * 0.75f));
    return messageBackground;
}

sf::Text createEndMessage(int winner, sf::RectangleShape *messageBackground, const sf::Font &font) {
    
    std::string winnerMessageContent;
    if (winner == Xmark) winnerMessageContent = "Winner: X\n(right-click for new game)";
    else if (winner == Omark) winnerMessageContent = "Winner: O\n(right-click for new game)";
    else if (winner == TIE) winnerMessageContent = "TIE\n(right-click for new game)";
    else winnerMessageContent = "";
    
    sf::Text winnerMessage(winnerMessageContent, font, END_FONT_SIZE);
    sf::FloatRect winnerMessageTextBounds = winnerMessage.getLocalBounds();
    winnerMessage.setOrigin(winnerMessageTextBounds.left + (winnerMessageTextBounds.width / 2.f), winnerMessageTextBounds.top + (winnerMessageTextBounds.height / 2.f));

    sf::FloatRect backgroundBounds = messageBackground->getGlobalBounds();
    winnerMessage.setPosition(backgroundBounds.left + (backgroundBounds.width / 2.f), backgroundBounds.top + (backgroundBounds.height / 2.f));
    winnerMessage.setFillColor(sf::Color::Blue);
    return winnerMessage;
}

std::vector<std::vector<sf::Text>> updateExistingFields(std::vector<std::vector<sf::Text>> Symbols, TicTacToe currGame) {
    for (int i = 0; i < BOARD_FIELDS_X; i++) {
        for (int j = 0; j < BOARD_FIELDS_Y; j++) {
            if (currGame.getFieldState(i,j) == EMPTY) Symbols[i][j].setString("");
            if (currGame.getFieldState(i,j) == Xmark) Symbols[i][j].setString("X");
            if (currGame.getFieldState(i,j) == Omark) Symbols[i][j].setString("O"); 
        }
    }
    return Symbols;
}

sf::RectangleShape createScoreboardBackground() {
    sf::RectangleShape scoreBoardBG = sf::RectangleShape({WINDOW_WIDTH, 150.f});
    scoreBoardBG.setFillColor(sf::Color::Black);
    scoreBoardBG.setOutlineColor(sf::Color::Blue);
    scoreBoardBG.setOutlineThickness(1.f);
    sf::FloatRect scoreBoardBounds = scoreBoardBG.getGlobalBounds();
    scoreBoardBG.setPosition({0.f, WINDOW_HEIGHT - scoreBoardBounds.height});

    return scoreBoardBG;
}

std::string intToStr(int number) {
    std::string output;
    std::stringstream converter;
    converter << number;
    converter >> output;
    return output;
}

sf::Text createScoreboardText(TicTacToe currGame, const sf::Font &font, sf::RectangleShape background) {
    int Owins = currGame.getOwins();
    int Xwins = currGame.getXwins();
    
    std::string strXwins = intToStr(Xwins);
    std::string strOwins = intToStr(Owins);

    std::string finalContent = "X: " + strXwins + "\t\t\t\tO: " + strOwins;

    sf::Text scoreboardText(finalContent, font, int(FONT_SIZE * 0.75));

    sf::FloatRect backgroundBounds = background.getGlobalBounds();
    sf::FloatRect scoreboardTextBounds = scoreboardText.getGlobalBounds();

    scoreboardText.setOrigin({scoreboardTextBounds.left + (scoreboardTextBounds.width / 2.f), scoreboardTextBounds.top + (scoreboardTextBounds.height / 2.f)});
    scoreboardText.setPosition({backgroundBounds.left + (backgroundBounds.width / 2.f), backgroundBounds.top + (backgroundBounds.height / 2.f)});

    scoreboardText.setFillColor(sf::Color::Blue);
    scoreboardText.setOutlineColor(sf::Color::Blue);
    scoreboardText.setOutlineThickness(1.f);

    return scoreboardText;
}
