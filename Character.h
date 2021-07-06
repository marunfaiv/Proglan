#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include <cmath>

class Character
{
public:
        void init();
        void ModelOne();
        void ModelSliding();
        void setWindow(sf::RenderWindow *window);
        void draw();
        void setPosition(float xp, float yp);
        void setSlide(bool isSliding);

        bool isSlide();

        float GetX();
        float GetY();

private:
        float radius = 20;
        float xp, yp;
        sf::CircleShape head, body;
        sf::RenderWindow *window;
        bool isSliding;
};

#endif