#include "aksesoris.h"
#include <cstdio>

void Aksesoris::init(){
    coin.setRadius(radius);
    coin.setPosition(this->xp, this->yp);
    penggerak();
}

void Aksesoris::setWindow(sf::RenderWindow *window){
    this->window = window;
}

void Aksesoris::draw(){
    Aksesoris::init();
    this->window->draw(coin);
}

void Aksesoris::setPosition(float xp, float yp){
    this->xp = xp;
    this->yp = yp;
}

void Aksesoris::ambilPosisiCharacter(float xpcharacter, float ypcharacter){
    this->xpcharacter=xpcharacter;
    this->ypcharacter=ypcharacter;
}

void Aksesoris::getScore(float *score){
    this->xpcharacter -= this->xp;
    this->ypcharacter -= this->yp;

        xpcharacter =   abs(xpcharacter);
        ypcharacter =  abs(ypcharacter);

        // xp = xp - 0.1;
    if(xpcharacter < areaXChara && ypcharacter < areaYChara){
        xp = 1200;
        // coin.setFillColor(sf::Color::Black);
        *score = *score + 1;
    }
}

void Aksesoris::penggerak(){
    this->xp = xp - 0.1;
    if(xp < 0){
        xp = 1200;
    }
}

float Aksesoris::getX(){
    return this->xp;
}

float Aksesoris::getY(){
    return this->yp;
}