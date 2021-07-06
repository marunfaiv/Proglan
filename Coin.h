#ifndef COIN_H
#define COIN_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Coin
{

public:
    void init();
    void draw();
    void setWindow(sf::RenderWindow *window);
    void setPosition(float xp, float yp);
    void penggerak();
    void getScore(float *score);
    void getScoreSliding(float *score);
    void ambilPosisiCharacter(float xpcharacter, float ypcharacter);
    void playSound();
    float getX();
    float getY();

    // Collider getCollision() { return Collider(radius);}

private:
    float radius = 30;
    float areaXChara = 20, areaYChara = 120;
    float xpSliding = 100, ypSliding = 470;
    float areaXSliding = 120, areaYSliding = 20;
    float xpcharacter, ypcharacter;
    float xp, yp;

    sf::CircleShape coin;
    sf::RenderWindow *window;
    sf::SoundBuffer buffer;
    sf::Sound sound;
};

#endif