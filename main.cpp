#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


int main()
{

    using namespace sf;

    float PlayerMovementSpeed = 0.20;
    sf::RenderWindow window(sf::VideoMode(800,600),"Przygody Gabci");
    int counterwalking = 0;
    sf::Texture texturePlayer;
    if(!texturePlayer.loadFromFile("sprite.png"))
    {
        return EXIT_FAILURE;
    }

    sf::Sprite spritePlayer(texturePlayer);
    spritePlayer.setPosition(window.getSize().x/2,window.getSize().y/2);
    spritePlayer.setTextureRect((sf::IntRect(256,128,64,64)));

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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
           spritePlayer.move(0,-PlayerMovementSpeed);
           spritePlayer.setTextureRect((sf::IntRect(counterwalking *64,64*0,64,64)));

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            spritePlayer.move(0,PlayerMovementSpeed);
            spritePlayer.setTextureRect((sf::IntRect(counterwalking *64,64*2,64,64)));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            spritePlayer.move(PlayerMovementSpeed,0);
            spritePlayer.setTextureRect((sf::IntRect(counterwalking *64,64*3,64,64)));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            spritePlayer.move(-PlayerMovementSpeed,0);
            spritePlayer.setTextureRect((sf::IntRect(counterwalking *64,64*1,64,64)));
        }

        counterwalking++;
        if(counterwalking==9)
        {
            counterwalking=0;
        }

        window.draw(spritePlayer);
        window.display();


    }
    return 0;
}