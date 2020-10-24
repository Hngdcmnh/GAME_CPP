#include "weapon.h"

weapon::weapon()
{
	anim.resize(2);
	this->current_weapon = 0;
}

void weapon::Init()
{
	sf::Texture a1;
	a1.loadFromFile("gun_2.png");
	animation b1(a1, 1, 0.1);
	anim[0] = b1;

	sf::Texture a2;
	a2.loadFromFile("gun_4.png");
	animation b2(a2, 1, 0.1);
	anim[1] = b2;

	anim[0].Update(true,true);
	anim[0].SetTextureForSprite(body);
}

void weapon::Change()
{
	if (current_weapon == 0) current_weapon = 1;
	else if (current_weapon == 1) current_weapon = 0;

}

void weapon::Update(sf::Vector2f hero_pos,bool face_right)
{
	body.setPosition(hero_pos + sf::Vector2f(40, 50));
	anim[current_weapon].Update(face_right,true);
	anim[current_weapon].SetTextureForSprite(body);
}

void weapon::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

sf::Sprite weapon::GetGun()
{
	return this->body;

}

