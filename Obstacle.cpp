#include "Obstacle.h"

void Obstacle::init()
{
    Obstacle::tembokBesar();
    Obstacle::gerakan();
}

void Obstacle::tembokBesar()
{
    tembok.setPosition(sf::Vector2f(this->xp, this->yp));
    tembok.setSize(sf::Vector2f(100, 100));
    tembok.setFillColor(sf::Color::Green);
}

void Obstacle::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}

void Obstacle::draw()
{
    Obstacle::init();
    this->window->draw(tembok);
}

void Obstacle::ambilPosisiCharacter(float xpCharacter, float ypCharacter)
{
    this->xpCharacter = xpCharacter;
    this->ypCharacter = ypCharacter;
}

void Obstacle::ambilPosisiSlide(float xpSliding, float ypSiding)
{
    this->xpSliding = xpSliding;
    this->ypSliding = ypSliding;
}

void Obstacle::setPosition(float xp, float yp)
{
    this->xp = xp;
    this->yp = yp;
}

void Obstacle::Collision(float *NyawaPlayer)
{
    this->xpCharacter -= this->xp;
    this->ypCharacter -= this->yp;

    xpCharacter = abs(xpCharacter);
    ypCharacter = abs(ypCharacter);

    if (xpCharacter < areaXChara && ypCharacter < areaYChara)
    {
        Obstacle::playSound();
        xp = -100;
        *NyawaPlayer = *NyawaPlayer - 1;
    }
}

void Obstacle::slidingCollision(float *nyawaPlayer)
{
    this->xpCharacter -= this->xpSliding;
    this->ypCharacter -= this->ypSliding;

    xpCharacter = abs(xpCharacter);
    ypCharacter = abs(ypCharacter);

    if (xpCharacter < areaXSliding && ypCharacter < areaYSliding)
    {
        Obstacle::playSound();
        xp = -100;
        // *nyawaPlayer = *nyawaPlayer - 1;
    }
}

void Obstacle::playSound()
{
    if (!buffer.loadFromFile("music file/oof.wav"))
    {
    }

    sound.setBuffer(buffer);
    sound.setVolume(30);
    sound.play();
}

void Obstacle::gerakan()
{
    this->xp = xp - 0.3;
}

float Obstacle::getX()
{
    return this->xp;
}

float Obstacle::getY()
{
    return this->yp;
}