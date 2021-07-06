#ifndef GAMEFUNCTION_H
#define GAMEFUNCTION_H
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Main.hpp>
#include "Character.h"
#include "Coin.h"
#include "Obstacle.h"
#include "Item.h"

#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }

private:
    int selectedItemIndex;

    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
};

class Game
{
public:
    void levelOne(sf::RenderWindow *window);
    void levelTwo(sf::RenderWindow *window);
    void howToPlay(sf::RenderWindow *window);
    void gameOver(sf::RenderWindow *window, float *score);
    void gameClear(sf::RenderWindow *window);
    void gameClear2(sf::RenderWindow *window);
    void openingGame(sf::RenderWindow *window);
    void outOfCoins(sf::RenderWindow *window);
    void buffering();

private:
    // Gawe Attribute Class e
    sf::RenderWindow *window;
    sf::Font font;
    sf::Event event;

    sf::RectangleShape loadBar;
    sf::RectangleShape bufferBar;

    sf::SoundBuffer buffer;
    sf::Sound sound;
};
#endif