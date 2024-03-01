#include "Game.h"
#include <iostream>
#include <unistd.h>


int score = 0;
int dir;
int increment = 50;
float lastx;
float lasty;
float buffx;
float buffy;



Game::Game() {
    this -> initializevars();
    this -> initwindow();
    this -> initEnemies();
    this -> initFruits();

}

void Game::verify(){
    if(((this -> enemy.getPosition().x >= this -> fruit.getPosition().x -25) && (this ->enemy.getPosition().x <= this -> fruit.getPosition().x + 25)) && (this -> enemy.getPosition().y >= this -> fruit.getPosition().y -25 && this ->enemy.getPosition().y <= this -> fruit.getPosition().y + 25)){
        initFruits();
        score++;
        if(score == 1){
            initEnemies2();
            std:: cout << "initialized";
        }else if (score == 2){
            initEnemies3();
        }
    }


}

Game::~Game() {
    delete this-> window;
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        verify();
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                    break;
                } else if (ev.key.code == sf::Keyboard::Right) {
                    dir = 1;
                    break;
                } else if (ev.key.code == sf::Keyboard::Up) {
                    dir = -1;
                    break;
                } else if (ev.key.code == sf::Keyboard::Down) {
                    dir = -10;
                    break;
                } else if (ev.key.code == sf::Keyboard::Left) {
                    dir = 10;
                    break;
                }
        }
    }
        std::vector<sf::RectangleShape*> MyObjects = {&enemy2, &enemy3}; // Use vector instead of list
            switch (dir) {
                case 1:
                    moveright(MyObjects);
                    verify();
                    usleep(250000);
                    break;
                case 10:
                    moveleft(MyObjects);
                    verify();
                    usleep(250000);
                    break;
                case -1:
                    moveup(MyObjects);
                    verify();
                    usleep(250000);
                    break;
                case -10:
                    movedown(MyObjects);
                    verify();
                    usleep(250000);
                    break;
            }

}


void Game::update() {
    this -> pollEvents();
}

void Game::render(){
    this -> window -> clear(sf::Color(50,50,80));
    this -> window -> draw(this->enemy);
    this -> window -> draw(this-> fruit);
    this -> window -> draw(this->enemy2);
    this -> window -> draw(this->enemy3);
    this -> window -> display();

}

void Game::initializevars(){
    this->window = nullptr;

}

void Game::initFruits(){
    srand((unsigned) time(NULL));
    float seedx = (rand() % 425);
    float seedy = (rand() % 425);
    this -> fruit.setRadius(15);
    this -> fruit.setPosition(sf::Vector2f(seedx,seedy));
    this -> fruit.setFillColor(sf::Color::Red);

}


void Game::initEnemies() {
    this -> enemy.setSize(sf::Vector2f(50.f, 50.f));
    this -> enemy.setFillColor(sf::Color::Blue);
    this -> enemy.setOutlineColor(sf::Color::Black);
    this -> enemy.setOutlineThickness(1.5);
    this -> enemy.setPosition(100.f,100.f);

}

void Game::initEnemies2() {
    this -> enemy2.setSize(sf::Vector2f(50.f, 50.f));
    this -> enemy2.setFillColor(sf::Color::Yellow);
    this -> enemy2.setOutlineColor(sf::Color::Black);
    this -> enemy2.setOutlineThickness(1.5);


}

void Game::initEnemies3() {
    this -> enemy3.setSize(sf::Vector2f(50.f, 50.f));
    this -> enemy3.setFillColor(sf::Color::Green);
    this -> enemy3.setOutlineColor(sf::Color::Black);
    this -> enemy3.setOutlineThickness(1.5);
}

    void Game::moveleft(std::vector<sf::RectangleShape*> myobj){
        lastx =  enemy.getPosition().x;
        lasty =  enemy.getPosition().y;
        enemy.setPosition(lastx - increment, lasty);
        for(auto& i: myobj){
            buffx = i->getPosition().x;
            buffy = i->getPosition().y;
            i->setPosition(lastx, lasty);
            lastx = buffx;
            lasty =  buffy;



        }
    };

    void Game::movedown(std::vector<sf::RectangleShape*> myobj) {
        lastx = enemy.getPosition().x;
        lasty =  enemy.getPosition().y;
        enemy.setPosition(lastx, lasty + increment);
        for(auto& i: myobj){
            buffx = i->getPosition().x;
            buffy = i->getPosition().y;
            i->setPosition(lastx, lasty);
            lastx = buffx;
            lasty =  buffy;
        }
    };

    void Game::moveup(std::vector<sf::RectangleShape*> myobj) {
        lastx = enemy.getPosition().x,
        lasty =  enemy.getPosition().y;
        enemy.setPosition(lastx, lasty - increment);
        for(auto& i: myobj){
            buffx = i->getPosition().x;
            buffy = i->getPosition().y;
            i->setPosition(lastx, lasty);
            lastx = buffx;
            lasty =  buffy;



        }
    };

    void Game::moveright(std::vector<sf::RectangleShape*> myobj) {
        lastx = enemy.getPosition().x;
        lasty =  enemy.getPosition().y;
        enemy.setPosition(lastx + increment, lasty + 0);
        for(auto& i: myobj){
            buffx = i->getPosition().x;
            buffy = i->getPosition().y;
            i->setPosition(lastx, lasty);
            lastx = buffx;
            lasty =  buffy;



        }
    };


    void Game::initwindow() {
        this->videoMode.height = 450;
        this->videoMode.width = 450;
        this->window = new sf::RenderWindow(sf::RenderWindow(sf::VideoMode(450, 450), "Window", sf::Style::Titlebar | sf::Style::Close));
        this->window->setFramerateLimit(60);
    }

    const bool Game::running() const {
        return this->window->isOpen();
    }
