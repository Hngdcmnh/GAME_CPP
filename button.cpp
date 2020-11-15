#include "button.h"

button::button()
{
	anim.resize(3);
	this->is_push = false;

}

void button::Init(int a)
{
	sf::Texture c0;
	c0.loadFromFile("./texture/state/button_play.png");
	animation d0(c0, 1, 0.1);
	anim[0] = d0;

	sf::Texture c1;
	c1.loadFromFile("./texture/state/buttons_exit.png");
	animation d1(c1, 1, 0.1);
	anim[1] = d1;

	sf::Texture c2;
	c2.loadFromFile("./texture/state/button_info.png");
	animation d2(c2, 1, 0.1);
	anim[2] = d2;

	anim[a].Update(true, 0);
	//this->body.setPosition(sf::Vector2f(390, 200+a * 100));
	this->body.setScale(0.4f, 0.4f);
	anim[a].SetTextureForSprite(body);

}

sf::Sprite* button::GetBody()
{
	return &this->body;
}

void button::Push()
{
	is_push = true;
}

void button::Draw(sf::RenderWindow &window)
{
	window.draw(body);
}


