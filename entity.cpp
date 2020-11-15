#include "entity.h"

entity::entity()
{
	blood_1.setSize(sf::Vector2f(50.0f,10.0f));
	blood_2.setSize(sf::Vector2f(50.0f, 10.0f));
	blood_1.setFillColor(sf::Color::Red);
	blood_2.setFillColor(sf::Color::White);

}

void entity::SetPosition(float x,float y)
{
	this->body.setPosition(x, y);
}

void entity::SetRect(float x, float y)
{
	this->body.setTextureRect(sf::IntRect(x,y,body.getTextureRect().width, body.getTextureRect().height));
}

void entity::Scale(float a, float b)
{
	this->body.scale(a,b);
}

sf::Sprite entity::GetBody()
{
	return body;
}

sf::Vector2f entity::GetPosition()
{
	return this->body.getPosition();
}



