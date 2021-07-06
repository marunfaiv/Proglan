#include "Character.h"

void Character::init()
{
    if (isSliding)
        Character::ModelSliding();
    else
        Character::ModelOne();
}

void Character::ModelOne()
{
    head.setRadius(radius);
    head.setPosition(this->xp, this->yp);
    body.setRadius(radius);
    body.setPosition(this->xp, this->yp + 40);
    body.setScale(1, 2);
}

void Character::ModelSliding()
{
    head.setRadius(radius);
    head.setPosition(this->xp, this->yp + 80);
    body.setRadius(radius);
    body.setPosition(this->xp + 40, this->yp + 80);
    body.setScale(2, 1);
}

void Character::setWindow(sf::RenderWindow *window)
{
    this->window = window;
}

void Character::draw()
{
    Character::init();
    this->window->draw(head);
    this->window->draw(body);
}

void Character::setPosition(float xp, float yp)
{
    this->xp = xp;
    this->yp = yp;
}

void Character::setSlide(bool isSliding)
{
    this->isSliding = isSliding;
}

float Character::GetX()
{
    return this->xp;
}
float Character::GetY()
{
    return this->yp;
}

bool Character::isSlide()
{
    return this->isSliding;
}