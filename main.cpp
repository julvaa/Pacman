#include <iostream>
#include <ctime>
#include "pacmanSFML.h"
using namespace std;

vector<vector<bool>> mapa =
        {
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
                {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
                {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
                {1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1},
                {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
                {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
                {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
                {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                {1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
                {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
                {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };




int main()
{
    sf::Clock c;
    int speed = 500;
    srand(time(NULL));
    MainScreen main;
    GameScreen game(mapa);
    EndScreen end;
    bool pause = false;
    sf::Clock pauseClock;
    main.active = true;
    bool isMove = true;
    bool isMove2 = true;
    int testy = 0;
    sf::RenderWindow window(sf::VideoMode(800, 800), "Title");
    window.setFramerateLimit(60);
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (game.active == true) game.pacman.press(event);

            if (main.active == true)
            {
                if (event.type == sf::Event::MouseButtonPressed && main.button1.body.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    main.active = false;
                    game.active = true;
                }
                if (event.type == sf::Event::MouseButtonPressed && main.button2.body.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                {
                    window.close();
                }

            }
        }
        if (game.active == true)
        {
            bool coun = false;
            for (int i = 0; i < game.sciany.size();i++)
            {
                if (game.pacman.dir == sf::Keyboard::Key::Right)
                {
                    if (game.pacman.glowa.getPosition().x+25 == game.sciany[i].getPosition().x &&
                        game.pacman.glowa.getPosition().y == game.sciany[i].getPosition().y)
                    {
                        isMove = false;
                        coun = true;
                    }
                }
                else if (game.pacman.dir == sf::Keyboard::Key::Left)
                {
                    if (game.pacman.glowa.getPosition().x-25 == game.sciany[i].getPosition().x &&
                        game.pacman.glowa.getPosition().y == game.sciany[i].getPosition().y)
                    {
                        isMove = false;
                        coun = true;
                    }
                }
                else if (game.pacman.dir == sf::Keyboard::Key::Up)
                {
                    if (game.pacman.glowa.getPosition().x == game.sciany[i].getPosition().x &&
                        game.pacman.glowa.getPosition().y-25 == game.sciany[i].getPosition().y)
                    {
                        isMove = false;
                        coun = true;
                    }
                }
                else if (game.pacman.dir == sf::Keyboard::Key::Down)
                {
                    if (game.pacman.glowa.getPosition().x == game.sciany[i].getPosition().x &&
                        game.pacman.glowa.getPosition().y+25 == game.sciany[i].getPosition().y)
                    {
                        isMove = false;
                        coun = true;
                    }
                }

                //przeciwnik
                for(int i = 0; i < 3; i++)
                {
                    if (game.przec[i].dir == sf::Keyboard::Key::Right)
                    {
                        if (game.przec[i].glowa.getPosition().x+25 == game.sciany[i].getPosition().x &&
                            game.przec[i].glowa.getPosition().y == game.sciany[i].getPosition().y)
                        {
                            isMove2 = false;
                            game.przec[i].coun = true;
                        }
                    }
                    else if (game.przec[i].dir == sf::Keyboard::Key::Left)
                    {
                        if (game.przec[i].glowa.getPosition().x-25 == game.sciany[i].getPosition().x &&
                            game.przec[i].glowa.getPosition().y == game.sciany[i].getPosition().y)
                        {
                            isMove2 = false;
                            game.przec[i].coun = true;
                        }
                    }
                    else if (game.przec[i].dir == sf::Keyboard::Key::Up)
                    {
                        if (game.przec[i].glowa.getPosition().x == game.sciany[i].getPosition().x &&
                            game.przec[i].glowa.getPosition().y-25 == game.sciany[i].getPosition().y)
                        {
                            isMove2 = false;
                            game.przec[i].coun = true;
                        }
                    }
                    else if (game.przec[i].dir == sf::Keyboard::Key::Down)
                    {
                        if (game.przec[i].glowa.getPosition().x == game.sciany[i].getPosition().x &&
                            game.przec[i].glowa.getPosition().y+25 == game.sciany[i].getPosition().y)
                        {
                            isMove2 = false;
                            game.przec[i].coun = true;
                        }
                    }
                }
            }
            if (coun == false) isMove = true;
            for(int i = 0; i < 3; i++) if (game.przec[i].coun == false) game.przec[i].isMove = true;
            for(int i = 0; i < game.J.size(); i++) if (game.pacman.glowa.getGlobalBounds().intersects(game.J[i].body.getGlobalBounds()))
                {
                    game.J[i].body.move(1000,0);
                    game.punkty++;
                    testy++;
                }
            if (game.punkty >= game.max)
            {

                game.active = false;
                end.active = true;
            }
        }
        if (end.active == true)
        {
            if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                end.active = false;
                main.active = true;
                end.val.clear();
                end.leaderboard.clear();
            }
        }
        if (pause == true && pauseClock.getElapsedTime().asMilliseconds() > 10000)
        {
            pause = false;
        }
        if(c.getElapsedTime().asMilliseconds() > speed)
        {
            if (game.active == true && isMove == true) game.pacman.move();
            if (game.active == true && pause == false) for(int i = 0; i < 3; i++) game.przec[i].przecMove(game.pacman,game.sciany);


            c.restart();
        }

        for(int j = 0; j<3; j++) if (game.pacman.glowa.getPosition() == game.przec[j].glowa.getPosition())
            {
                game.przec[j].glowa.setPosition(10*25 + j*25, 11*25);
                game.hearts--;
                pause = true;
                pauseClock.restart();
                break;
            }
        if (game.hearts == 0)
        {
            game.active = false;
            end.loadLeaderboard(game.punkty);
            end.active = true;
            game.hearts = 3;
            game.punkty = 0;
            for(auto &v : game.J) if (v.body.getPosition().x > 800) v.body.move(-1000, 0);
            game.przec[0].glowa.setPosition(10*25, 11*25);
            game.przec[1].glowa.setPosition(11*25, 11*25);
            game.przec[2].glowa.setPosition(12*25, 11*25);

        }

        window.clear(sf::Color::Black);

        if (main.active == true) main.drawScreen(window);
        else if (game.active == true) game.drawScreen(window);
        else if (end.active == true) end.drawScreen(window);


        window.display();
    }
    return 0;
}
