#include "hero.h"

hero::hero(float speed)
{
	
	this->anim.resize(3);
	face_right = true;
	this->speed = speed;
	body.setPosition(206.0f, 206.0f);
	body.setScale(1.5f, 1.5f);


	movement.x = 0;
	movement.y = 0;
}

void hero::Init()
{
	sf::Texture a1;
	a1.loadFromFile("Attack (78x58).png");
	animation b1(a1, 3,0.1);
	anim[0] = b1;
	sf::Texture a2;
	a2.loadFromFile("Idle (78x58).png");
	animation b2(a2, 11,0.01);
	anim[1] = b2;
	sf::Texture a3;
	a3.loadFromFile("Run (78x58).png");
	animation b3(a3, 8,0.01);
	anim[2] = b3;
	anim[1].Update(face_right,0);
	anim[1].SetTextureForSprite(body);
}

void hero::Idle()
{
	movement.x = 0;
	movement.y = 0;
	anim[1].Update(face_right, 0);
	anim[1].SetTextureForSprite(body);
}

void hero::MoveRight()
{
	movement.x += speed ;
	anim[2].Update(face_right,0);
	anim[2].SetTextureForSprite(body);
}

void hero::MoveLeft()
{
	movement.x -= speed;
	anim[2].Update(face_right, 0);
	anim[2].SetTextureForSprite(body);
}

void hero::MoveUp()
{
	movement.y -= speed;
	anim[2].Update(face_right, 0);
	anim[2].SetTextureForSprite(body);
}

void hero::MoveDown()
{
	movement.y += speed;
	anim[2].Update(face_right, 0);
	anim[2].SetTextureForSprite(body);
}

void hero::Fight()
{
	anim[0].Update(face_right, 0);
	anim[0].SetTextureForSprite(body);
}

void hero::Update()
{
	if (movement.x != 0)
	{
		if (movement.x > 0.0f) face_right = true;
		else if (movement.x < 0.0f) face_right = false;
	}
	body.setPosition(body.getPosition().x+movement.x, body.getPosition().y + movement.y);
}

//void hero::IsCollison(entity* other)
//{
//	if (this->body.getGlobalBounds().intersects(other->body.getGlobalBounds()))
//	{
//		cout << "hay qua";
//	}
//}

void hero::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

sf::Vector2f hero::GetPosition()
{
	return body.getPosition();
}

sf::Vector2f hero::GetOrigin()
{
	return body.getOrigin();
}

sf::Sprite hero::GetBody()
{
	return body;
}



