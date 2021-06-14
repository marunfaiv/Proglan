#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>

class Character{
public:

        void init();
        void draw();
        void setWindow(sf::RenderWindow *window);
        void setPosition(float xp,float yp);
        void penggerak();
        float GetX();
        float GetY();
        void hitbox();

private:
        float xp=100,yp=350;
        float radius = 20;
        // float areaX = 20, areaY = 120;
        float xCoin, yCoin;
        sf::CircleShape head, body;
        sf::RenderWindow *window;
};

#endif