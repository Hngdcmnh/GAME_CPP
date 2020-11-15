#include "state_end.h"

state_end::state_end()
{
}

state_end::~state_end()
{
}

void state_end::Init()
{
}

void state_end::Perform(int &score)
{
	sf::Sprite sprite;
	sf::Texture texture_1;
	texture_1.loadFromFile("./texture/map/score board.png");
	sprite.setTexture(texture_1);
	sprite.setPosition(220, 150);
	sprite.scale(1, 0.8);

	sf::Texture texture;
	texture.loadFromFile("./texture/state/background menu.png");
	sf::RectangleShape background(sf::Vector2f(1000, 700));
	background.setTexture(&texture);
	
	sf::Font font;
	font.loadFromFile("./font/font_bold.ttf");
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(80);
	text.setPosition(280.0f, 200.0f);
	/*text.setColor(sf::Color::Red);*/
	
	int a = 10;
	stringstream ss;
	ss << score;
	string s = ss.str();
	string s1 = "YOUR SCORE  " + s;
	text.setString(s1);
	sf::RenderWindow window(sf::VideoMode(1000, 700), "SFML works!", sf::Style::Close | sf::Style::Resize);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.draw(background);
		window.draw(sprite);
		window.draw(text);
		window.display();
	}
}
