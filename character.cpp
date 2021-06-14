#include "character.h"

void Character::init(){
    head.setRadius(radius);
    head.setPosition(this->xp,this->yp);
    // body.setPosition(this->xp+5, this->yp+60);
    body.setRadius(radius);
    body.setPosition(this->xp, this->yp+40);
    body.setScale(1,2);
    // bunder.setOrigin(30,30);
    // bunder.rotate(90);
    // bunder.setFillColor(sf::Color(255,0,0,255));
    // penggerak();
}

void Character::setWindow(sf::RenderWindow *window){
    this->window = window;
}

void Character::draw(){
    Character::init();
    this->window->draw(head);
    this->window->draw(body);
}

void Character::setPosition(float xp, float yp){
    this->xp = xp;
    this->yp = yp;
}

void Character::penggerak(){
    this->xp = xp+0.01;
}

float Character::GetX(){
    return this->xp;
}

float Character::GetY(){
    return this->yp;
}

