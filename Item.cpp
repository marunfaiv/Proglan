#include "Item.h"

void Item::init(){
    hp.setRadius(radius);
    hp.setFillColor(sf::Color::Magenta);
    hp.setPosition(this->xp,this->yp);
    Item::penggerak();

}

void Item::setWindow(sf::RenderWindow *window){
    this->window=window;
}

void Item::draw(){
    Item::init();
    this->window->draw(hp);
}

void Item::setPosition(float xp, float yp){
    this->xp = xp;
    this->yp = yp;
}

void Item::ambilPosisiCharacter(float xpCharacter, float ypCharacter){
    this->xpCharacter = xpCharacter;
    this->ypCharacter = ypCharacter;
}

void Item::getHealth(float *NyawaPlayer){
    this->xpCharacter -= this->xp;
    this->ypCharacter -= this->yp;

    xpCharacter = abs(xpCharacter);
    ypCharacter = abs(ypCharacter);

    if(xpCharacter < areaXChara && ypCharacter < areaYChara){
        xp = -100;
        *NyawaPlayer = *NyawaPlayer + 1;
    }
}

void Item::getHealthSliding(float *NyawaPlayer){
    this->xpCharacter -= this->xpSliding;
    this->ypCharacter -= this->ypSliding;

    xpCharacter = abs(xpCharacter);
    ypCharacter = abs(ypCharacter);

    if(xpCharacter < areaXSliding && ypCharacter < areaYSliding){
        xp = -100;
        *NyawaPlayer = *NyawaPlayer + 1;
    }
}

void Item::penggerak(){
    this->xp = xp - 0.3;
}

float Item::getX(){
    return this->xp;
}

float Item::getY(){
    return this->yp;
}