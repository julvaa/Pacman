
#ifndef PACMAN_PACMANSFML_H
#define PACMAN_PACMANSFML_H

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <algorithm>
#include <vector>
#include "plansza.h"
#include "pacman.h"
using namespace std;

class Button
{
public:
    sf::RectangleShape body;
    sf::Text text;
    sf::Font font;

    Button(int x, int y, string txt);
    Button(int x, int y, string txt, float sizeX, float sizeY);
    void draw(sf::RenderWindow &window);
};

class Screen
{
public:
    bool active = false;
    sf::Text title;
    sf::Font font;

    Screen();
};

class MainScreen : public Screen
{
public:
    Button button1;
    Button button2;

    MainScreen();
    void drawScreen(sf::RenderWindow &window);
};

bool comp(int a, int b);

class GameScreen : public Screen
{
public:
    Pacman pacman;
    vector<Pacman> przec;
    sf::Text punktyText;
    sf::Text zycia;
    vector<Jedzenie> J;
    vector<Sciana> sciany;
    int punkty = 0;
    int max = 0;
    int hearts = 3;

    GameScreen(vector<vector<bool>> mapa);
    void drawScreen(sf::RenderWindow &window);
    void respawn();
};

class EndScreen : public Screen
{
public:
    sf::Text punktyText;
    vector<sf::Text> leaderboard;
    vector<int> val;

    EndScreen();
    void loadLeaderboard(int pkt);
    void saveLeaderboard();
    void drawScreen(sf::RenderWindow &window);
};


#endif //PACMAN_PACMANSFML_H
