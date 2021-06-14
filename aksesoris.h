#ifndef AKSESORIS_H
#define AKSESORIS_H
#include <SFML/Graphics.hpp>

class Aksesoris{

public:

    void init();
    void draw();
    void setWindow(sf::RenderWindow *window);
    void setPosition(float xp,float yp);
    void penggerak();
    void getScore(float *score);
    void ambilPosisiCharacter(float xpcharacter, float ypcharacter);
    float getX();
    float getY();

private:

    float radius = 30;
    float areaXChara = 20, areaYChara = 120;
    float xpcharacter, ypcharacter;
    float xp = 500, yp = 400;
    sf::CircleShape coin;
    sf::RenderWindow *window;

};

#endif