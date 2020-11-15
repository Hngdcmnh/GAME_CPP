#include "weapon.h"

weapon::weapon()
{
	anim.resize(2);
	this->current_weapon = 0;
	
}

void weapon::Init()
{
	sf::Texture a1;
	a1.loadFromFile("./texture/weapon/gun_2.png");
	animation b1(a1, 1, 0.1);
	anim[0] = b1;

	sf::Texture a2;
	a2.loadFromFile("./texture/weapon/tank.png");
	animation b2(a2, 6, 0.01);
	anim[1] = b2;

	anim[0].Update(true,true);
	anim[0].SetTextureForSprite(body);
}


void weapon::Change()
{
	if (current_weapon == 0)
	{
		current_weapon = 1;
		body.scale(0.25, 0.25);
	}
	else if (current_weapon == 1)
	{
		body.scale(4, 4);
		current_weapon = 0;
	}
}

int weapon::CurrentWeapon()
{
	return this->current_weapon;
}

void weapon::Default()
{
	if (current_weapon == 1)
	{
		body.scale(4, 4);
		current_weapon = 0;
	}
}

void weapon::Update(sf::Vector2f hero_pos,bool face_right)
{
	

	if (current_weapon == 0)
	{
		body.setPosition(hero_pos + sf::Vector2f(40, 50));
		anim[current_weapon].Update(face_right, true);
		anim[current_weapon].SetTextureForSprite(body);
	}
	else if (current_weapon == 1)
	{
		body.setPosition(hero_pos - sf::Vector2f(40, 30));
		anim[current_weapon].Update(face_right, true);
		anim[current_weapon].SetTextureForSprite(body);
	}
	
}

void weapon::Draw(sf::RenderWindow& window)
{
	window.draw(body);

}

sf::Sprite weapon::GetBody()
{
	return this->body;

}

