#include "pacmanSFML.h"

Button::Button(int x, int y, string txt)
{
    body.setSize({200, 75});
    body.setPosition(x, y);
    font.loadFromFile("../arialmt.ttf");
    text.setCharacterSize(30);
    text.setPosition(x+5, y+5);
    text.setFont(font);
    text.setString(txt);
    text.setFillColor(sf::Color::Black);
}

Button::Button(int x, int y, string txt, float sizeX, float sizeY)
{
    body.setSize({sizeX, sizeY});
    body.setPosition(x, y);
    font.loadFromFile("../arialmt.ttf");
    text.setCharacterSize(30);
    text.setPosition(x+3, y-5);
    text.setFont(font);
    text.setString(txt);
    text.setFillColor(sf::Color::Black);
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(body);
    window.draw(text);
}

Screen::Screen()
{
    font.loadFromFile("../arialmt.ttf");
    title.setCharacterSize(30);
    title.setFont(font);
    title.setString("title");
    title.setPosition(350, 0);
}

MainScreen::MainScreen() : button1(300, 300, "Play"), button2(300, 400, "Exit")
{
    title.setString("Pacman");
}

void MainScreen::drawScreen(sf::RenderWindow &window)
{
    button1.draw(window);
    button2.draw(window);
    window.draw(title);
}
bool comp(int a, int b)
{
    if (a < b) return false;
    else return true;
}

GameScreen::GameScreen(vector<vector<bool>> mapa)
{
    pacman.glowa.setPosition(300, 325);
    title.setString("Gra");
    punktyText.setCharacterSize(30);
    punktyText.setFont(font);
    punktyText.setString("punkty:");
    zycia.setCharacterSize(30);
    zycia.setFont(font);
    zycia.setString("zycia: 3");
    zycia.setPosition(600, 0);
    for(int i = 0; i < mapa.size(); i++)
    {
        for(int j = 0; j < mapa[i].size(); j++)
        {
            if (mapa[i][j] == true)
            {
                Sciana tmp;
                tmp.setPosition(50+j*25, 50 + 25*i);
                sciany.emplace_back(tmp);
            }
            else
            {
                Jedzenie tmp;
                tmp.body.setPosition(50+j*25, 50 + 25*i);
                max++;
                J.emplace_back(tmp);
            }
        }
    }
    for(int i = 0; i < 3;i++)
    {
        Pacman tmp;
        przec.emplace_back(tmp);
    }
    przec[0].glowa.setFillColor(sf::Color::Cyan);
    przec[1].glowa.setFillColor(sf::Color::Blue);
    przec[2].glowa.setFillColor(sf::Color::Magenta);
    przec[0].glowa.setPosition(10*25, 11*25);
    przec[1].glowa.setPosition(11*25, 11*25);
    przec[2].glowa.setPosition(12*25, 11*25);
}

void GameScreen::drawScreen(sf::RenderWindow &window)
{
    punktyText.setString("punkty: " + to_string(punkty));
    window.draw(punktyText);
    zycia.setString("Zycia: " + to_string(hearts));
    window.draw(zycia);
    for(auto &v : J) window.draw(v.body);
    window.draw(pacman.glowa);
    for(int i = 0; i < 3; i++) window.draw(przec[i].glowa);
    for(auto &v : sciany) window.draw(v);
    window.draw(title);
}

void GameScreen::respawn()
{
    bool tmp = false;
    do
    {
        tmp = false;
        int respX = (rand() % 24)*50;
        int respY = (rand() % 14)*50;
        for(int i = 0; i < sciany.size(); i++)
        {
            if (sciany[i].getPosition().x == respX && sciany[i].getPosition().y == respY) tmp = true;
        }
    }while (tmp == true);
}

EndScreen::EndScreen()
{
    title.setString("Koniec Gry");
    punktyText.setCharacterSize(30);
    punktyText.setFont(font);
    punktyText.setString("punkty: NAN");
    punktyText.setPosition(500, 100);
}


void EndScreen::loadLeaderboard(int pkt)
{
    punktyText.setString("punkty: " + to_string(pkt));
    fstream file;
    file.open("plik.txt", std::ios::in);
    if (file.is_open())
    {
        cout << "open" << endl;
        string line;
        while(getline(file, line))
        {
            val.emplace_back(stoi(line));
        }
    }
    file.close();
    bool ist = 0;
    for(auto &v : val)
    {
        if (pkt == v) ist = true;
    }
    if (ist != true) val.emplace_back(pkt);
    sort(val.begin(), val.end(), comp);
    if (val.size() > 10)
    {
        val.erase(val.begin()+val.size()-1);
    }
    for(int i = 0; i < val.size(); i++)
    {
        sf::Text t;
        t.setCharacterSize(30);
        t.setFont(font);
        t.setPosition(500, 150 + 40*i);
        t.setString("");
        t.setString(to_string(val[i]));
        leaderboard.emplace_back(t);
    }
    saveLeaderboard();
}

void EndScreen::saveLeaderboard()
{
    sort(val.begin(), val.end(), comp);

    fstream file;
    file.open("plik.txt", std::ios::out);
    if (file.is_open())
    {
        cout << "open" << endl;
        for(auto &v : val)
        {
            file << v << endl;
        }
    }
    file.close();
}

void EndScreen::drawScreen(sf::RenderWindow &window)
{
    window.draw(punktyText);
    window.draw(title);
    for(auto &v : leaderboard) window.draw(v);
}
