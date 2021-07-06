#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Obstacle
{
public:
    void draw();
    void init();
    void tembokBesar();
    void gerakan();
    void setPosition(float xp, float yp);
    void setWindow(sf::RenderWindow *window);
    void slidingCollision(float *nyawaPlayer);
    void Collision(float *nyawaPlayer);
    void ambilPosisiCharacter(float xpCharacter, float ypCharacter);
    void ambilPosisiSlide(float xpSliding, float ypSliding);
    void playSound();
    float getX();
    float getY();

private:
    float xp, yp;
    float areaXChara = 20, areaYChara = 120;
    float areaXSliding = 120, areaYSliding = 20;
    float xpSliding, ypSliding;
    float xpCharacter, ypCharacter;
    float rad = 20;

    sf::RectangleShape tembok;
    sf::CircleShape misil;
    sf::CircleShape buntutMisil;
    sf::RenderWindow *window;

    sf::SoundBuffer buffer;
    sf::Sound sound;
};
#endif