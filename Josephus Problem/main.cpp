#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Resources/josephus.cpp"
using namespace std;
void display(sf::RenderWindow &window, int *array, int size)
{
    sf::Texture t;
    sf::Sprite s(t);
    for (int i = 0; i < size; i++)
    {
        int w = 25;
        int j = 0;
        if (array[i] == -5)
        {
            s.setTextureRect(sf::IntRect(0, 0, w, w));
            s.setColor(sf::Color::Green);
            s.setPosition(i * (w + 10) + 50, j * (w + 10) + 100);
            window.draw(s);
        }
        else
        {
            s.setTextureRect(sf::IntRect(0, 0, w, w));
            s.setColor(sf::Color::Red);
            s.setPosition(i * (w + 10) + 50, j * (w + 10) + 100);
            window.draw(s);
        }
    }
}
int option_selector(int x, int y)
{
    if (x >= 298 && x <= 750 && y >= 472 && y <= 548)
        return 1;
    if (x >= 306 && x <= 730 && y >= 556 && y <= 624)
        return 2;
    return 0;
}
int main()
{
    //=========================================================
    //
    //               ####  ######    ###    #####    ######
    //              ##       ##     ## ##   ##  ##     ##
    //               ###     ##    ##   ##  #####      ##
    //                 ##    ##    #######  ##  ##     ##
    //              ####     ##    ##   ##  ##   ##    ##
    //
    //=========================================================

    // TODO Start Screen
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Josephus Problem");

    sf::Texture background_texture;
    background_texture.loadFromFile("/Users/moeezali/Documents/VS/SEMESTER#3/Assignment 3/Josephus Problem/Josephus Problem/wallpaper.jpeg");

    sf::Sprite background;
    background.setTexture(background_texture);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
                if (option_selector(mouse_position.x, mouse_position.y) == 2)
                {
                    window.close();
                }
                else if (option_selector(mouse_position.x, mouse_position.y) == 1)
                {
                    window.close();
                    cout << "Enter the number of people: ";
                    int people;
                    cin >> people;
                    cout << "Enter the skips: ";
                    int skips;
                    cin >> skips;
                    int *array = new int[people];
                    for (int i = 0; i < people; i++)
                        array[i] = i + 1;

                    ////=========================================
                    //
                    //   ####      ###    ###    ###  #####
                    //  ##        ## ##   ## #  # ##  ##
                    //  ##  ###  ##   ##  ##  ##  ##  #####
                    //  ##   ##  #######  ##      ##  ##
                    //   ####    ##   ##  ##      ##  #####
                    //
                    //=========================================

                    sf::RenderWindow game_screen(sf::VideoMode(1200, 628), "Rat in Maze but Queue", sf::Style::Close);
                    while (game_screen.isOpen())
                    {
                        sf::Event event2;
                        while (game_screen.pollEvent(event2))
                        {
                            game_screen.clear(sf::Color::White);
                            display(game_screen, array, people);
                            game_screen.display();

                            if (event2.type == sf::Event::Closed)
                            {
                                game_screen.close();
                                break;
                            }

                            if (event2.type == sf::Event::KeyPressed && event2.key.code == sf::Keyboard::Enter)
                            {
                                int temporary = josephus_sort(array, people, skips);
                                cout << temporary << endl;
                                array[temporary] = -5;
                            }
                        }
                    }
                }
            }
        }

        window.clear();
        window.display();
    }
}
