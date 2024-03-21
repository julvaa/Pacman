#include "pacman.h"

Pacman::Pacman()
{
    glowa.setPosition(200, 200);
    glowa.setSize({25, 25});
    glowa.setFillColor(sf::Color::Green);
}

void Pacman::recMove()
{
    sf::Vector2f p = pos;
}

void Pacman::move()
{
    pos = sf::Vector2f(glowa.getPosition().x, glowa.getPosition().y);
    if (pos.x == 500 && pos.y == 275 && dir == sf::Keyboard::Key::Right)
    {
        glowa.setPosition(50, 275);
    }
    else if(pos.x == 50 && pos.y == 275 && dir == sf::Keyboard::Key::Left)
    {
        glowa.setPosition(500, 275);
    }
    else
    {
        if (dir == sf::Keyboard::Key::Up)
        {
            glowa.move(0, -speed);
        }
        else if (dir == sf::Keyboard::Key::Right)
        {
            glowa.move(speed, 0);
        }
        else if (dir == sf::Keyboard::Key::Down)
        {
            glowa.move(0, speed);
        }
        else
        {
            glowa.move(-speed, 0);
        }
        recMove();
    }
}

void Pacman::przecMove(Pacman &gracz, vector<Sciana> &sciany)
{
    vector<sf::Keyboard::Key> pozycje;
    bool left = true;
    bool right = true;
    bool up = true;
    bool down = true;

    for(int i = 0; i < sciany.size(); i++)
    {
        if (glowa.getPosition().x+25 == sciany[i].getPosition().x && glowa.getPosition().y == sciany[i].getPosition().y)
        {
            right = false;
        }
        else if (glowa.getPosition().x-25 == sciany[i].getPosition().x && glowa.getPosition().y == sciany[i].getPosition().y)
        {
            left = false;
        }
        else if (glowa.getPosition().x == sciany[i].getPosition().x && glowa.getPosition().y+25 == sciany[i].getPosition().y)
        {
            down = false;
        }
        else if (glowa.getPosition().x == sciany[i].getPosition().x && glowa.getPosition().y-25 == sciany[i].getPosition().y)
        {
            up = false;
        }
    }

    if (left && dir != sf::Keyboard::Key::Right) pozycje.emplace_back(sf::Keyboard::Key::Left);
    if (right && dir != sf::Keyboard::Key::Left) pozycje.emplace_back(sf::Keyboard::Key::Right);
    if (up && dir != sf::Keyboard::Key::Down) pozycje.emplace_back(sf::Keyboard::Key::Up);
    if (down && dir != sf::Keyboard::Key::Up) pozycje.emplace_back(sf::Keyboard::Key::Down);
    if (pozycje.size() == 0)
    {
        if (left) pozycje.emplace_back(sf::Keyboard::Key::Left);
        if (right) pozycje.emplace_back(sf::Keyboard::Key::Right);
        if (up) pozycje.emplace_back(sf::Keyboard::Key::Up);
        if (down) pozycje.emplace_back(sf::Keyboard::Key::Down);
    }

    sf::Keyboard::Key wybor;
    sf::Vector2f posnowy = {glowa.getPosition().x+25, glowa.getPosition().y};
    for(auto &v : pozycje)
    {
        sf::Vector2f posn;

        if (v == sf::Keyboard::Key::Right)
        {
            posn = {glowa.getPosition().x+25, glowa.getPosition().y};
            if (abs(posn.x-gracz.glowa.getPosition().x) <= abs(posnowy.x-gracz.glowa.getPosition().x) || abs(posn.y-gracz.glowa.getPosition().y) <= abs(posnowy.y-gracz.glowa.getPosition().y))
            {
                posnowy = posn;
                wybor = sf::Keyboard::Key::Right;

            }
        }
        else if (v == sf::Keyboard::Key::Left)
        {
            posn = {glowa.getPosition().x-25, glowa.getPosition().y};
            if (abs(posn.x-gracz.glowa.getPosition().x) <= abs(posnowy.x-gracz.glowa.getPosition().x) || abs(posn.y-gracz.glowa.getPosition().y) <= abs(posnowy.y-gracz.glowa.getPosition().y))
            {
                posnowy = posn;
                wybor = sf::Keyboard::Key::Left;

            }
        }
        else if (v == sf::Keyboard::Key::Up)
        {
            posn = {glowa.getPosition().x, glowa.getPosition().y-25};
            if (abs(posn.x-gracz.glowa.getPosition().x) < abs(posnowy.x-gracz.glowa.getPosition().x) || abs(posn.y-gracz.glowa.getPosition().y) < abs(posnowy.y-gracz.glowa.getPosition().y))
            {
                posnowy = posn;
                wybor = sf::Keyboard::Key::Up;

            }
        }
        else if (v == sf::Keyboard::Key::Down)
        {
            posn = {glowa.getPosition().x, glowa.getPosition().y+25};
            if (abs(posn.x-gracz.glowa.getPosition().x) < abs(posnowy.x-gracz.glowa.getPosition().x) || abs(posn.y-gracz.glowa.getPosition().y) < abs(posnowy.y-gracz.glowa.getPosition().y))
            {
                posnowy = posn;
                wybor = sf::Keyboard::Key::Down;

            }
        }

    }

    dir = wybor;
    bool isScianaHelp = false;
    for(auto &b : sciany) if (b.getPosition().x == glowa.getPosition().x && b.getPosition().y == glowa.getPosition().y) isScianaHelp = true;

    if (wybor != 0)move();

}

void Pacman::press(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        if (dir != sf::Keyboard::Key::Down) dir = sf::Keyboard::Key::Up;
    }
    else if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    {
        if (dir != sf::Keyboard::Key::Up) dir = sf::Keyboard::Key::Down;
    }
    else if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        if (dir != sf::Keyboard::Key::Right) dir = sf::Keyboard::Key::Left;
    }
    else if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        if (dir != sf::Keyboard::Key::Left) dir = sf::Keyboard::Key::Right;
    }
}
