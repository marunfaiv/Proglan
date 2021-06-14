#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Main.hpp>
#include "character.h"
#include "aksesoris.h"


using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1200, 600), "Runman Adventure");
    Event event;
    RectangleShape lantai;
    lantai.setSize(Vector2f(1200,100));
    lantai.setPosition(0,400);
    Aksesoris koin1[5];
    for(int i = 0; i < 5;i++){
    koin1[i].setWindow(&window);
    koin1[i].setPosition(i*100, 400);
    }
    Character char1;
    char1.setWindow(&window);

    float score = 0;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        if(Keyboard::isKeyPressed(Keyboard::Space)){
            char1.setPosition(char1.GetX(), char1.GetY()-0.9);
        }

        if(char1.GetY() < 350){
            char1.setPosition(char1.GetX(), char1.GetY()+0.5);
        }

        window.clear();
        for(int i = 0; i < 5; i++){
        koin1[i].ambilPosisiCharacter(char1.GetX(), char1.GetY());
        koin1[i].getScore(&score);
        koin1[i].draw();
        }

        char1.draw();
        window.draw(lantai);


        window.display();
    }

    return 0;
}