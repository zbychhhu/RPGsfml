#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "player.h"
#include "entity.h"


int main()
{

    using namespace sf;


    sf::RenderWindow window(sf::VideoMode(800,600),"Przygody Gabci");

    player Player1("sprite.png");

    while (window.isOpen())
    {


        window.clear(sf::Color::Black);
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    std::cout << "the escape key was pressed" << std::endl;
                    window.close();
                }
            }
        }

        window.clear(sf::Color::Black);

        Player1.update();
        Player1.updatemovement();
        window.draw(Player1);

        window.display();


    }
    return 0;
}