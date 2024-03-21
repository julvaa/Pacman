
#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "plansza.h"
#include <iostream>
#include <cmath>
using namespace std;

class Pacman
{
public:;
    sf::RectangleShape glowa;
    sf::Vector2f pos;
    sf::Keyboard::Key dir = sf::Keyboard::Key::Right;
    float speed = 25;
    bool coun = false;
    bool isMove = false;

    Pacman();
    void recMove();
    void move();
    void przecMove(Pacman &gracz, vector<Sciana> &sciany);
    void press(sf::Event &event);
};

#endif //PACMAN_PACMAN_H

