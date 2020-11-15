#include "state_menu.h"

state_menu::state_menu()
{

}

state_menu::~state_menu()
{

}

void state_menu::Init()
{
	play.Init(0);
	exit.Init(1);
	info.Init(2);
    play.SetPosition(370.0f, 200.0f);
    exit.SetPosition(370.0f, 320.0f);
    info.SetPosition(370.0f, 440.0f);
}


void state_menu::Perform(int &score)
{
	sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!", sf::Style::Close | sf::Style::Resize);

    sf::Texture texture;
    texture.loadFromFile("./texture/state/background 1.png");
    sf::RectangleShape background(sf::Vector2f(1000, 700));
    background.setTexture(&texture);

    sf::Texture texture_2;
    texture_2.loadFromFile("./texture/state/key board.png");
    sf::Sprite key_board;
    key_board.setTexture(texture_2);
    key_board.scale(0.5, 0.5);
    key_board.setPosition(250.0f, 100.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        { 
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        
        sf::FloatRect rectMouse((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y, 0.0001f, 0.0001f);
        if (play.GetBody()->getGlobalBounds().intersects(rectMouse))
        {
            play.SetPosition(370.0f, 190.0f);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                window.close();
            }
        }
        else play.SetPosition(370.0f, 200.0f);
        
        if (exit.GetBody()->getGlobalBounds().intersects(rectMouse))
        {
            exit.SetPosition(370.0f, 310.0f);
            
        }
        else exit.SetPosition(370.0f, 320.0f);
        int check = 0;
        if (info.GetBody()->getGlobalBounds().intersects(rectMouse))
        {
            info.SetPosition(370.0f, 430.0f);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                check = 1;
            }
            
        }
        else info.SetPosition(370.0f, 440.0f);


        
        /*window.draw(sprite);*/
        window.draw(background);
        play.Draw(window);
        exit.Draw(window);
        info.Draw(window);
        if (check == 1) window.draw(key_board);
        window.display();
    }
}



