#include "GameFunction.h"
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1200, 600), "Runman Adventure");
    Event event;
    Game start;
    Menu menu(window.getSize().x, window.getSize().y);
    sf::SoundBuffer buffer;
    sf::Sound sound;

    if(!buffer.loadFromFile("music file/mainMenuMusic.wav")){

    }

    sound.setBuffer(buffer);
    sound.setVolume(30);
    sound.play();
    sound.setLoop(true);
    
    start.openingGame(&window);

    while (window.isOpen())
    {

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    menu.MoveDown();
                    break;

                case sf::Keyboard::Return:
                    switch (menu.GetPressedItem())
                    {
                    case 0:
                        sound.stop();
                        start.levelOne(&window);
                        break;
                    case 1:
                        start.howToPlay(&window);
                        break;
                    case 2:
                        sound.stop();
                        window.close();
                        break;
                    }
                }
            }
        }

        window.clear();
        menu.draw(window);
        window.display();
    }

    return 0;
}