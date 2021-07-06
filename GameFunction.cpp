#include "GameFunction.h"
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;
/* Menu Function */

Menu::Menu(float width, float height)
{
    if (!font.loadFromFile("font file/times new roman.ttf"))
    {
        //hand error
    }
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("How to Play");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

    selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

/* Gameplay Function */

void Game::gameOver(sf::RenderWindow *window, float *score)
{
    sf::Font font;
    sf::SoundBuffer buffer;
    sf::Sound sound;

    std::stringstream highscore;
    sf::Text text, text2, highscorelbl;
    sf::Event event;

    if (!font.loadFromFile("font file/times new roman.ttf"))
    {
    }

    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setString("GAME OVER!");
    text.setPosition(sf::Vector2f(450, 200));
    text.setCharacterSize(50);

    text2.setFont(font);
    text2.setFillColor(sf::Color::Red);
    text2.setString("Press Escape to Exit");
    text2.setPosition(sf::Vector2f(450, 250));
    text2.setCharacterSize(50);

    highscorelbl.setCharacterSize(50);
    highscorelbl.setPosition(450, 350);
    highscorelbl.setFont(font);
    highscorelbl.setFillColor(sf::Color::Yellow);
    highscorelbl.setString(highscore.str());

    if (!buffer.loadFromFile("music file/gameOverSound.wav"))
    {
    }

    sound.setBuffer(buffer);
    sound.setVolume(30);
    sound.play();
    sound.setLoop(true);

    while (true)
    {
        while (window->pollEvent(event))
        {

            switch (event.type)
            {

            case sf::Event::Closed:
                window->close();
                break;
            }
        }

        window->clear();

        highscore.str("");
        highscore << "HIGH SCORE : " << *score;
        highscorelbl.setString(highscore.str());

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            return window->close();
        }

        window->draw(text);
        window->draw(text2);
        window->draw(highscorelbl);

        window->display();
    }
}

void Game::gameClear(sf::RenderWindow *window)
{
    sf::Font font;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::Text text1, text2, text3;
    sf::Event event;

    if (!font.loadFromFile("font file/times new roman.ttf"))
    {
    }

    if (!buffer.loadFromFile("music file/gameClear1Sound.wav"))
    {
    }

    text1.setFont(font);
    text1.setFillColor(sf::Color::Yellow);
    text1.setString("GAME CLEAR!");
    text1.setPosition(sf::Vector2f(450, 200));
    text1.setCharacterSize(50);

    text2.setFont(font);
    text2.setFillColor(sf::Color::Blue);
    text2.setString("Press Escape to Exit \nPress C to Continue");
    text2.setPosition(sf::Vector2f(450, 250));
    text2.setCharacterSize(50);

    sound.setBuffer(buffer);
    sound.setVolume(30);
    sound.play();
    sound.setLoop(true);

    while (true)
    {
        while (window->pollEvent(event))
        {

            switch (event.type)
            {

            case sf::Event::Closed:
                window->close();
                break;
            }
        }

        window->clear();

        window->draw(text1);
        window->draw(text2);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return window->close();
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            sound.stop();
            Game::levelTwo(window);
        }

        window->display();
    }
}

void Game::gameClear2(sf::RenderWindow *window)
{
    sf::Font font;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    sf::Text text1, text2, text3;
    sf::Event event;

    if (!font.loadFromFile("font file/times new roman.ttf"))
    {
    }

    if (!buffer.loadFromFile("music file/gameClear2Sound.wav"))
    {
    }

    text1.setFont(font);
    text1.setFillColor(sf::Color::Yellow);
    text1.setString("GAME CLEAR!");
    text1.setPosition(sf::Vector2f(450, 200));
    text1.setCharacterSize(50);

    text2.setFont(font);
    text2.setFillColor(sf::Color::Blue);
    text2.setString("You Cleared All Levels \nStay tuned for the Next Update");
    text2.setPosition(sf::Vector2f(400, 250));
    text2.setCharacterSize(50);

    text3.setFont(font);
    text3.setFillColor(sf::Color::White);
    text3.setString("Press Escape to Exit");
    text3.setPosition(sf::Vector2f(450, 400));
    text3.setCharacterSize(50);

    sound.setBuffer(buffer);
    sound.setVolume(30);
    sound.play();
    sound.setLoop(true);

    while (true)
    {
        while (window->pollEvent(event))
        {

            switch (event.type)
            {

            case sf::Event::Closed:
                window->close();
                break;
            }
        }

        window->clear();

        window->draw(text1);
        window->draw(text2);
        window->draw(text3);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            return window->close();

        window->display();
    }
}

void Game::openingGame(sf::RenderWindow *window)
{
    this->window = window;

    int loadVal = 0;
    int counter = 1;
    sf::Text judulGame, nama, nrp, departemen;

    font.loadFromFile("font file/times new roman.ttf");
    judulGame.setFont(font);
    judulGame.setFillColor(sf::Color::Magenta);
    judulGame.setString("RUNMAN ADVENTURE");
    judulGame.setPosition(sf::Vector2f(250, 100));
    judulGame.setCharacterSize(60);

    nama.setFont(font);
    nama.setFillColor(sf::Color::Yellow);
    nama.setString("ARYA ABDUL AZIS");
    nama.setPosition(sf::Vector2f(450, 450));
    nama.setCharacterSize(30);

    nrp.setFont(font);
    nrp.setFillColor(sf::Color::Yellow);
    nrp.setString("5024201069");
    nrp.setPosition(sf::Vector2f(520, 500));
    nrp.setCharacterSize(30);

    departemen.setFont(font);
    departemen.setFillColor(sf::Color::Yellow);
    departemen.setString("TEKNIK KOMPUTER");
    departemen.setPosition(sf::Vector2f(450, 550));
    departemen.setCharacterSize(30);

    loadBar.setPosition(sf::Vector2f(100, 350));
    loadBar.setSize(sf::Vector2f(loadVal, 50));
    loadBar.setFillColor(sf::Color::Green);

    while (true)
    {

        while (window->pollEvent(event))
        {

            switch (event.type)
            {

            case sf::Event::Closed:
                window->close();
                break;
            }
        }
        window->clear();

        loadBar.setSize(sf::Vector2f(loadVal, 50));

        window->draw(judulGame);
        window->draw(nama);
        window->draw(nrp);
        window->draw(departemen);

        window->draw(loadBar);

        window->display();

        if (counter % 90)
            if (loadVal <= 900)
                loadVal++;
            else
                break;
    }
}

void Game::howToPlay(sf::RenderWindow *window)
{
    sf::Event event;
    sf::Text text1, text2, text3, text4, text5;

    if (!font.loadFromFile("font file/times new roman.ttf"))
    {
    }

    text1.setFont(font);
    text1.setFillColor(sf::Color::Blue);
    text1.setString("Press Space to Jump");
    text1.setPosition(sf::Vector2f(10, 10));
    text1.setCharacterSize(30);

    text2.setFont(font);
    text2.setFillColor(sf::Color::Blue);
    text2.setString("Down Arrow to Slide");
    text2.setPosition(sf::Vector2f(10, 50));
    text2.setCharacterSize(30);

    text3.setFont(font);
    text3.setFillColor(sf::Color::White);
    text3.setString("Objective: Evade all the Obstacle and Collect Coins\nTo Unlock New Levels");
    text3.setPosition(sf::Vector2f(10, 100));
    text3.setCharacterSize(30);

    text4.setFont(font);
    text4.setFillColor(sf::Color::Yellow);
    text4.setString("Press Escape to Return");
    text4.setPosition(sf::Vector2f(10, 550));
    text4.setCharacterSize(30);

    text5.setFont(font);
    text5.setFillColor(sf::Color::Red);
    text5.setString("Note: Slide makes you invicible");
    text5.setPosition(sf::Vector2f(800, 10));
    text5.setCharacterSize(30);

    //Character Object
    Character player;
    player.setWindow(window);
    player.setPosition(600, 350);

    //Movement Logic
    bool isJumping = false;
    const int groundHeight = 380;
    const float gravity = 1;

    while (true)
    {
        const float moveSpeed = 2;

        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window->close();
                break;

            case sf::Event::KeyReleased:
                player.setSlide(false);
                isJumping = false;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            player.setSlide(true);
            player.ModelSliding();
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Down))
        {
            player.setSlide(false);
        }
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            player.setPosition(player.GetX(), player.GetY() - moveSpeed);
            isJumping = true;
        }
        if (player.GetY() < groundHeight && isJumping == false)
        {
            player.setPosition(player.GetX(), player.GetY() + gravity);
        }

        window->clear();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            return;
        }

        player.draw();
        window->draw(text1);
        window->draw(text2);
        window->draw(text3);
        window->draw(text4);
        window->draw(text5);

        window->display();
    }
}

void Game::levelOne(sf::RenderWindow *window)
{
    Event event;
    Font TNR;
    TNR.loadFromFile("font file/times new roman.ttf");

    //Main Menu Object
    Menu menu(window->getSize().x, window->getSize().y);
    //Others Object
    RectangleShape lantai;

    lantai.setSize(Vector2f(1200, 100));
    lantai.setPosition(0, 500);
    //Coin Object
    Coin koin1[5];
    Coin koin2[5];

    for (int i = 0; i < 5; i++)
    {
        koin1[i].setWindow(window);
        koin1[i].setPosition((i)*700, 400);
        koin2[i].setWindow(window);
        koin2[i].setPosition(((i)*900), 400);
    }
    //Health Object
    // Item getih;
    // getih.setWindow(window);

    //Obstacle Object
    Obstacle tembok1[5];
    Obstacle tembok2[5];
    for (int i = 0; i < 5; i++)
    {
        tembok1[i].setWindow(window);
        tembok1[i].setPosition(i * 500, 400);
        tembok2[i].setWindow(window);
        tembok2[i].setPosition(i * 1000, 400);
    }

    //Character Object
    Character player;
    player.setWindow(window);
    player.setPosition(100, 350);

    //Jumping system
    bool isJumping = false;
    const int groundHeight = 380;
    const float gravity = 1;

    //Life system
    float NyawaPlayer = 1;
    std::stringstream ssLife;
    Text lblLife;
    lblLife.setCharacterSize(20);
    lblLife.setPosition(10, 10);
    lblLife.setFont(TNR);
    lblLife.setString(ssLife.str());

    //Score System
    float score = 0;
    std::stringstream s;
    Text lblScore;
    lblScore.setCharacterSize(20);
    lblScore.setPosition(30, 30);
    lblScore.setFont(TNR);
    lblScore.setString(s.str());

    //Objective Strings
    std::stringstream objective;
    Text objlbl;
    objlbl.setCharacterSize(20);
    objlbl.setPosition(1000, 10);
    objlbl.setFont(TNR);
    objlbl.setFillColor(sf::Color::Red);
    objlbl.setString(objective.str());

    Game::buffering();

    if (!buffer.loadFromFile("music file/mainMenuMusic.wav"))
    {
    }
    sound.setBuffer(buffer);
    sound.setVolume(30);
    sound.play();
    sound.setLoop(true);

    while (window->isOpen())
    {
        const float moveSpeed = 2;

        // cout << player.GetX() << endl;
        // cout << player.GetY() << endl;

        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window->close();
            case sf::Event::KeyReleased:
                player.setSlide(false);
                isJumping = false;
                break;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && score == 3)
        {
            player.setSlide(true);
            player.ModelSliding();
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Down))
        {
            player.setSlide(false);
        }
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            player.setPosition(player.GetX(), player.GetY() - moveSpeed);
            isJumping = true;
        }
        if (player.GetY() < groundHeight && isJumping == false)
        {
            player.setPosition(player.GetX(), player.GetY() + gravity);
        }

        window->clear();

        //Object summon system
        for (int i = 0; i < 5; i++)
        {
            koin1[i].ambilPosisiCharacter(player.GetX(), player.GetY());
            koin2[i].ambilPosisiCharacter(player.GetX(), player.GetY());
            tembok1[i].ambilPosisiCharacter(player.GetX(), player.GetY());
            tembok2[i].ambilPosisiCharacter(player.GetX(), player.GetY());

            if (player.isSlide())
            {
                koin1[i].getScoreSliding(&score);
                koin2[i].getScoreSliding(&score);
                tembok1[i].slidingCollision(&NyawaPlayer);
                tembok2[i].slidingCollision(&NyawaPlayer);
            }
            else
            {
                tembok1[i].Collision(&NyawaPlayer);
                tembok2[i].Collision(&NyawaPlayer);
                koin1[i].getScore(&score);
                koin2[i].getScore(&score);
            }
            tembok1[i].draw();
            tembok2[i].draw();
            koin1[i].draw();
            koin2[i].draw();
        }

        s.str("");
        s << "COINS : " << score;
        lblScore.setString(s.str());

        ssLife.str("");
        ssLife << "HEALTH POINT : " << NyawaPlayer;
        lblLife.setString(ssLife.str());

        objective.str("");
        objective << "OBJECTIVE: \nCOLLECT 5 COINS" << endl;
        objlbl.setString(objective.str());

        //Health summon system
        // getih.ambilPosisiCharacter(player.GetX(), player.GetY());
        // getih.draw();

        //Game Clear Summoning
        if (score >= 5)
        {
            sound.stop();
            Game::gameClear(window);
        }

        //Game Over Summoning
        if (NyawaPlayer <= 0)
        {
            sound.stop();
            Game::gameOver(window, &score);
        }

        player.draw();
        window->draw(lantai);
        window->draw(lblScore);
        window->draw(lblLife);
        window->draw(objlbl);

        window->display();
    }
}

void Game::levelTwo(sf::RenderWindow *window)
{
    Event event;
    Font TNR;
    TNR.loadFromFile("font file/times new roman.ttf");
    //Main Menu Object
    Menu menu(window->getSize().x, window->getSize().y);
    //Others Object
    RectangleShape lantai;
    lantai.setSize(Vector2f(1200, 100));
    lantai.setPosition(0, 500);

    float counter = 0;

    //Coin Object
    Coin koin1[5];
    Coin koin2[5];
    Coin koin3[5];

    for (int i = 0; i < 5; i++)
    {
        koin1[i].setWindow(window);
        koin1[i].setPosition((i)*700, 400);
        koin2[i].setWindow(window);
        koin2[i].setPosition(((i)*900), 400);
        koin3[i].setWindow(window);
        koin3[i].setPosition(i * 1100, 400);
    }
    //Health Object
    // Item getih;
    // getih.setWindow(window);

    //Obstacle Object
    Obstacle tembok1[5];
    Obstacle tembok2[5];
    Obstacle tembokTerbang[5];
    Obstacle tembokTerbang2[5];
    Obstacle tembokTerbang3[5];

    for (int i = 0; i < 5; i++)
    {
        tembok1[i].setWindow(window);
        tembok1[i].setPosition(i * 500, 430);
        tembok2[i].setWindow(window);
        tembok2[i].setPosition(i * 1000, 430);

        tembokTerbang[i].setWindow(window);
        tembokTerbang[i].setPosition(i * 300, 100);
        tembokTerbang2[i].setWindow(window);
        tembokTerbang2[i].setPosition(i * 600, 100);
        tembokTerbang3[i].setWindow(window);
        tembokTerbang3[i].setPosition(i * 800, 100);
    }

    //Character Object
    Character player;
    player.setWindow(window);
    player.setPosition(100, 350);

    //Jumping system
    bool isJumping = false;
    const int groundHeight = 380;
    const float gravity = 1;

    //Life system
    float NyawaPlayer = 3;
    std::stringstream ssLife;
    Text lblLife;
    lblLife.setCharacterSize(20);
    lblLife.setPosition(10, 10);
    lblLife.setFont(TNR);
    lblLife.setString(ssLife.str());

    //Score System
    float score = 0;
    std::stringstream s;
    Text lblScore;
    lblScore.setCharacterSize(20);
    lblScore.setPosition(30, 30);
    lblScore.setFont(TNR);
    lblScore.setString(s.str());

    //Objective Strings
    std::stringstream objective;
    Text objlbl;
    objlbl.setCharacterSize(20);
    objlbl.setPosition(1000, 10);
    objlbl.setFont(TNR);
    objlbl.setFillColor(sf::Color::Red);
    objlbl.setString(objective.str());

    Game::buffering();

    if (!buffer.loadFromFile("music file/mainMenuMusic.wav"))
    {
    }
    sound.setBuffer(buffer);
    sound.setVolume(30);
    sound.play();
    sound.setLoop(true);

    while (window->isOpen())
    {
        const float moveSpeed = 2;

        while (window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::KeyReleased:
                player.setSlide(false);
                isJumping = false;
                break;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            player.setSlide(true);
            player.ModelSliding();
        }
        else if (!Keyboard::isKeyPressed(Keyboard::Down) && score == 3)
        {
            player.setSlide(false);
        }
        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            player.setPosition(player.GetX(), player.GetY() - moveSpeed);
            isJumping = true;
        }
        if (player.GetY() < groundHeight && isJumping == false)
        {
            player.setPosition(player.GetX(), player.GetY() + gravity);
        }

        window->clear();

        //Object summon system
        for (int i = 0; i < 5; i++)
        {
            koin1[i].ambilPosisiCharacter(player.GetX(), player.GetY());
            koin2[i].ambilPosisiCharacter(player.GetX(), player.GetY());
            koin3[i].ambilPosisiCharacter(player.GetX(), player.GetY());
            tembok1[i].ambilPosisiCharacter(player.GetX(), player.GetY());
            tembok2[i].ambilPosisiCharacter(player.GetX(), player.GetY());
            tembokTerbang[i].ambilPosisiCharacter(player.GetX(), player.GetY());
            tembokTerbang2[i].ambilPosisiCharacter(player.GetX(), player.GetY());
            tembokTerbang3[i].ambilPosisiCharacter(player.GetX(), player.GetY());

            if (player.isSlide())
            {

                koin1[i].getScoreSliding(&score);
                koin2[i].getScoreSliding(&score);
                koin3[i].getScoreSliding(&score);
                tembok1[i].slidingCollision(&NyawaPlayer);
                tembok2[i].slidingCollision(&NyawaPlayer);
                tembokTerbang[i].slidingCollision(&NyawaPlayer);
                tembokTerbang2[i].slidingCollision(&NyawaPlayer);
                tembokTerbang3[i].slidingCollision(&NyawaPlayer);
            }
            else
            {
                tembok2[i].Collision(&NyawaPlayer);
                tembok1[i].Collision(&NyawaPlayer);
                tembokTerbang[i].Collision(&NyawaPlayer);
                tembokTerbang2[i].Collision(&NyawaPlayer);
                tembokTerbang3[i].Collision(&NyawaPlayer);
                koin1[i].getScore(&score);
                koin2[i].getScore(&score);
                koin3[i].getScore(&score);
            }
            tembokTerbang[i].draw();
            tembokTerbang2[i].draw();
            tembokTerbang3[i].draw();
            tembok1[i].draw();
            tembok2[i].draw();
            koin1[i].draw();
            koin2[i].draw();
            koin3[i].draw();
        }

        s.str("");
        s << "COINS : " << score;
        lblScore.setString(s.str());

        ssLife.str("");
        ssLife << "HEALTH POINT : " << NyawaPlayer;
        lblLife.setString(ssLife.str());

        objective.str("");
        objective << "OBJECTIVE: \nCOLLECT 10 COINS" << endl;
        objlbl.setString(objective.str());

        //Health summon system
        // getih.ambilPosisiCharacter(player.GetX(), player.GetY());
        // getih.draw();

        //Game Clear Summoning
        if (score >= 10)
        {
            sound.stop();
            Game::gameClear2(window);
        }

        //Game Over Summoning
        if (NyawaPlayer <= 0)
        {
            sound.stop();
            Game::gameOver(window, &score);
        }

        player.draw();
        window->draw(lantai);
        window->draw(lblScore);
        window->draw(lblLife);
        window->draw(objlbl);

        window->display();
    }
}

void Game::buffering()
{
    int loadVal = 0;
    int counter = 1;

    loadBar.setPosition(sf::Vector2f(100, 400));
    loadBar.setSize(sf::Vector2f(loadVal, 50));
    loadBar.setFillColor(sf::Color::Green);

    while (true)
    {

        while (window->pollEvent(event))
        {

            switch (event.type)
            {

            case sf::Event::Closed:
                window->close();
                break;
            }
        }
        window->clear();

        loadBar.setSize(sf::Vector2f(loadVal, 50));

        window->draw(loadBar);

        window->display();

        if (counter % 10)
            if (loadVal <= 900)
                loadVal++;
            else
                break;
    }
}