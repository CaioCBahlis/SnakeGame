#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#pragma once


class Game{

private:
    void initializevars();
    void initwindow();
    void initEnemies();
    void initFruits();


    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;

    sf::RectangleShape enemy;
    sf::RectangleShape enemy2;
    sf::RectangleShape enemy3;
    sf::CircleShape fruit;

public:

    Game();
    virtual ~Game();

    void pollEvents();
    void update();
    void render();
    void moveleft(std::vector<sf::RectangleShape*>);
    void moveup(std::vector<sf::RectangleShape*>);
    void movedown(std::vector<sf::RectangleShape*>);
    void moveright(std::vector<sf::RectangleShape*>);
    void initEnemies2();
    void initEnemies3();
    void verify();
    const bool running () const;

};


