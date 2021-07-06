#include "Coin.h"
#include <cstdio>

void Coin::init()
{
    coin.setRadius(radius);
    coin.setFillColor(sf::Color::Yellow);
    coin.setPosition(this->xp, this->yp);
    penggerak();
}

void Coin::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}

void Coin::draw()
{
    Coin::init();
    this->window->draw(coin);
}

void Coin::setPosition(float xp, float yp)
{
    this->xp = xp;
    this->yp = yp;
}

void Coin::ambilPosisiCharacter(float xpcharacter, float ypcharacter)
{
    this->xpcharacter = xpcharacter;
    this->ypcharacter = ypcharacter;
}

void Coin::getScore(float *score)
{
    this->xpcharacter -= this->xp;
    this->ypcharacter -= this->yp;

    xpcharacter = abs(xpcharacter);
    ypcharacter = abs(ypcharacter);

    // xp = xp - 0.1;
    if (xpcharacter < areaXChara && ypcharacter < areaYChara)
    {
        //     // coin.setFillColor(sf::Color::Black);
        Coin::playSound();
        xp = -100;
        *score = *score + 1;
    }
}

void Coin::getScoreSliding(float *score)
{
    this->xpcharacter -= this->xpSliding;
    this->ypcharacter -= this->ypSliding;

    xpcharacter = abs(xpcharacter);
    ypcharacter = abs(ypcharacter);

    if (xpcharacter < areaXSliding && ypcharacter < areaYSliding)
    {
        xp = -100;
        *score = *score + 1;
    }
}

void Coin::playSound()
{
    if (!buffer.loadFromFile("music file/coinSound.wav"))
    {
    }
    sound.setBuffer(buffer);
    sound.setVolume(30);
    sound.play();
}

void Coin::penggerak()
{
    this->xp = xp - 0.3;
}

float Coin::getX()
{
    return this->xp;
}

float Coin::getY()
{
    return this->yp;
}