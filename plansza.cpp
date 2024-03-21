#include "plansza.h"

Jedzenie::Jedzenie()
{
    body.setOrigin(-11, -11);
    body.setRadius(2);
    body.setFillColor(sf::Color::Yellow);
}

void Jedzenie::respawn()
{

}

Sciana::Sciana()
{
    setSize({25, 25});
    setFillColor(sf::Color::Red);
}
