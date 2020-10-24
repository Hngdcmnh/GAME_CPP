#include "enemy.h"

enemy::enemy(float speed)
{
	this->anim.resize(4);
	face_right = true;
	this->speed = speed;
	body.setPosition(206.0f, 206.0f);
	body.setScale(1.5f, 1.5f);
	this->is_die = false;
}

void enemy::Init()
{
	sf::Texture a1;
	a1.loadFromFile("Skeleton Attack.png");
	animation b1(a1, 18, 0.01);
	anim[0] = b1;
	sf::Texture a2;
	a2.loadFromFile("Skeleton Idle.png");
	animation b2(a2, 11, 0.01);
	anim[1] = b2;
	sf::Texture a3;
	a3.loadFromFile("Skeleton Walk.png");
	animation b3(a3, 13, 0.01);
	anim[2] = b3;
	sf::Texture a4;
	a3.loadFromFile("Skeleton Dead.png");
	animation b4(a4, 15, 0.01);
	anim[3] = b4;
	anim[1].Update(face_right,0);
	anim[1].SetTextureForSprite(body);
}

void enemy::Update(sf::Vector2f hero_pos)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (sqrt(pow((hero_pos.x+35 - body.getPosition().x), 2) + pow((hero_pos.y+10 - body.getPosition().y), 2)) >40)
	{
		movement.x = (hero_pos.x+35  - body.getPosition().x) * speed;
		movement.y = (hero_pos.y+10  - body.getPosition().y) * speed;
		anim[2].Update(face_right,0);
		anim[2].SetTextureForSprite(body);
	}
	if(sqrt(pow((hero_pos.x+35 - body.getPosition().x), 2) + pow((hero_pos.y+10 - body.getPosition().y), 2)) <40)
	{
		movement.x = (hero_pos.x+35 - body.getPosition().x) * speed;
		movement.y = (hero_pos.y+10 - body.getPosition().y) * speed;
		anim[0].Update(face_right,0);
		anim[0].SetTextureForSprite(body);
	}

	if (movement.x != 0)
	{
		if (movement.x > 0.0f) face_right = true;
		else if (movement.x < 0.0f) face_right = false;
	}
	body.setPosition(body.getPosition().x + movement.x, body.getPosition().y + movement.y);

}

 void enemy::Die(bool is_die)
{
	 this->is_die = is_die;
}

 bool enemy::IsDie()
 {
	 return this->is_die;
 }

void enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

sf::Sprite enemy::GetBody()
{
	return body;
}
