#include "bullet.h"

bullet::bullet()
{
	anim.resize(2);
	right = true;
	current_bullet = 0;
	is_collide = 0;
}

void bullet::Init()
{
	body.setScale(0.5f, 0.5f);
	sf::Texture c0;
	c0.loadFromFile("b2_10.png");
	animation d0(c0, 1, 0.1);
	anim[0] = d0;
}

void bullet::Collide()
{
	this->is_collide = 1;
}

bool bullet::Is_Collide()
{
	return this->is_collide;
}

void bullet::Fire(sf::Vector2f hero_pos,bool face_right)
{
	this->is_collide = 0;
	right = face_right;
	body.setPosition(hero_pos + sf::Vector2f(0, 50));
	anim[0].Update(right, true);
	anim[0].SetTextureForSprite(body);
}

void bullet::Update(/*sf::Vector2f hero_pos, bool fire, bool change, bool face_right*/)
{
	if (right)
	{
		body.move(1, 0);
	}
	else body.move(-1, 0);
	anim[0].Update(right, true);
	anim[0].SetTextureForSprite(body);
}

void bullet::Draw(sf::RenderWindow& window)
{
	if(this->is_collide==0) window.draw(body);
	//window.draw(body);
}

sf::Sprite bullet::GetBullet()
{
	return this->body;
}

sf::Sprite bullet::GetBody()
{
	return body;
}
