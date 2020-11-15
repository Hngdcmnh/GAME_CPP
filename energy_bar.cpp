#include "energy_bar.h"

energy_bar::energy_bar()
{
	energy_bar_1.setSize(sf::Vector2f(250.0f, 25.0f));
	energy_bar_2.setSize(sf::Vector2f(0.0f, 25.0f));
	energy_bar_1.setFillColor(sf::Color::White);
	energy_bar_2.setFillColor(sf::Color(252,223,9));
	anim.resize(3);
	this->plus = false;
	this->is_full = false;
}

void energy_bar::Init()
{

	sf::Texture a0;
	a0.loadFromFile("./texture/map/lightning.png");
	animation b0(a0, 1, 0.1);
	anim[0] = b0;
	body.scale(0.07, 0.07);
	anim[0].Update(true, false);
	anim[0].SetTextureForSprite(body);

	sf::Texture a1;
	a1.loadFromFile("./texture/map/energy_bar.png");
	animation b1(a1, 1, 0.1);
	anim[1] = b1;
	energy_bar_3.scale(0.76, 1);
	anim[1].Update(true, false);
	anim[1].SetTextureForSprite(energy_bar_3);

}

void energy_bar::Plus()
{
	if(!is_full && energy_bar_2.getSize().x + 0.05 <= energy_bar_1.getSize().x)
	{
		energy_bar_2.setSize(sf::Vector2f(energy_bar_2.getSize().x + 0.05, energy_bar_2.getSize().y));
	}
	
	
}

void energy_bar::Update(sf::Vector2f hero_pos)
{
	if (energy_bar_2.getSize().x <= 0.05) // the use of the tank will run out when bar_2 is over
	{
		is_full = false;
		energy_bar_2.setFillColor(sf::Color(252, 223, 9));

	}
	if (energy_bar_2.getSize().x >= energy_bar_1.getSize().x-0.05) // when bar_2 is full, you can call a tank
	{
		is_full = true;
		energy_bar_2.setFillColor(sf::Color::Cyan);

	}
	if (is_full && energy_bar_2.getSize().x >= 0.01) // after full, bar_2 start down , this time you can call tank
	{
		energy_bar_2.setSize(sf::Vector2f(energy_bar_2.getSize().x - 0.01, energy_bar_2.getSize().y));
	}
	energy_bar_1.setPosition(hero_pos.x + 190, hero_pos.y - 245);
	energy_bar_2.setPosition(hero_pos.x + 190, hero_pos.y - 245);
	energy_bar_3.setPosition(hero_pos.x + 190, hero_pos.y - 253);
	body.setPosition(hero_pos.x + 175, hero_pos.y - 290);
}

void energy_bar::Draw(sf::RenderWindow& window)
{
	
	window.draw(energy_bar_1);
	window.draw(energy_bar_3);
	window.draw(energy_bar_2);
	window.draw(body);
	
}

bool energy_bar::IsFull()
{
	return this->is_full;
}
