#include "nade.h"

nade::nade()
{
	anim.resize(2);
}

void nade::Init()
{
	sf::Texture a1;
	a1.loadFromFile("./texture/weapon/nade_3.png");
	animation b1(a1, 1, 0.09);
	anim[0] = b1;
	/*body.scale(0.1, 0.1);*/

	sf::Texture a2;
	a2.loadFromFile("./texture/weapon/explode_3.png");
	animation b2(a2, 7, 0.009);
	anim[1] = b2;

	anim[0].Update(true, true);
	anim[0].SetTextureForSprite(body);
	is_exist = false;
	is_explode = false;
}

bool nade::IsExplode()
{
	return this->is_explode;
}

void nade::SetPosition(sf::Vector2f hero_pos,bool face_right)
{
	
	body.setPosition(hero_pos + sf::Vector2f(0, -20));
	/*body.setOrigin(sf::Vector2f(0, 50));*/
	anim[0].Update(true, true);
	anim[0].SetTextureForSprite(body);
	is_exist = true;
	is_explode = false;
	time_exist = 0;
	ground = hero_pos.y;
	this->face_right = face_right;
	if (face_right) movement.x = 0.3;
	else movement.x = -0.3;
	movement.y = -0.3;
}

void nade::Update()
{
	movement.y += 0.001; // gravity
	time_exist+=1;
	//body.setPosition(body.getPosition().x + movement.x, body.getPosition().y + movement.y);
	if (is_explode == false && is_exist == true)
	{
		body.setPosition(body.getPosition().x + movement.x, body.getPosition().y + movement.y);
		if (body.getPosition().y >= ground)
		{
			is_explode = true;
			anim[1].SetCurrentImage();
		}
	}
	if (is_explode == true)
	{
		
		anim[1].Update(true, true);
		anim[1].SetTextureForSprite(body);
	}
	if (time_exist >= 1300 && is_exist == true)
	{
		is_exist = false;
		is_explode = false;
		/*body.scale(1 / 20, 1 / 20);*/
	}
}

void nade::Draw(sf::RenderWindow& window)
{
	if (is_exist == true) window.draw(body);
}
