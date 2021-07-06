#ifndef ITEM_H
#define ITEM_H
#include <SFML/Graphics.hpp>

class Item{

public:

    void init();
    void draw();
    void setWindow(sf::RenderWindow *window);
    void setPosition(float xp, float yp);
    void getHealth(float *NyawaPlayer);
    void getHealthSliding(float *NyawaPlayer);
    void ambilPosisiCharacter(float xpCharacter, float ypCharacter);
    void penggerak();
    float getX();
    float getY();

private:

    float radius = 30;
    float areaXChara = 20, areaYChara = 120;
    float areaXSliding = 120, areaYSliding = 20;
    float xpCharacter, ypCharacter;
    float xp = 2000, yp = 400;
    float xpSliding = 100, ypSliding = 470;

    sf::CircleShape hp;
    sf::RenderWindow *window;
};

#endif