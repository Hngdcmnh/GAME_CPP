#include "hero.h"

hero::hero()
{
	
	this->anim.resize(3);
	face_right = true;
	this->is_collide = false;
	this->is_die = false;
	this->speed =0.5f;
	body.setPosition(300.0f, 300.0f);
	body.setScale(1.5f, 1.5f);
	blood_1.setPosition(body.getPosition().x, body.getPosition().y - 30);
	blood_2.setPosition(body.getPosition().x, body.getPosition().y - 30);
	
	movement.x = 0;
movement.y = 0;
}

void hero::Init()
{
	sf::Texture a1;
	a1.loadFromFile("./texture/hero/Attack (78x58).png");
	animation b1(a1, 3, 0.1);
	anim[0] = b1;
	sf::Texture a2;
	a2.loadFromFile("./texture/hero/Idle (78x58).png");
	animation b2(a2, 11, 0.01);
	anim[1] = b2;
	sf::Texture a3;
	a3.loadFromFile("./texture/hero/Run (78x58).png");
	animation b3(a3, 8, 0.01);
	anim[2] = b3;
	anim[1].Update(face_right, 0);
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
	movement.x += speed;
	anim[2].Update(face_right, 0);
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

void hero::Update(sf::Sprite map,bool bar_is_full)
{
	if (!bar_is_full) // when is man
	{
		body.setPosition(body.getPosition().x + movement.x, body.getPosition().y + movement.y);
		if (body.getGlobalBounds().top > map.getGlobalBounds().top + 30 &&
			body.getGlobalBounds().left > map.getGlobalBounds().left + 20 &&
			body.getGlobalBounds().top + body.getGlobalBounds().height < map.getGlobalBounds().top + map.getGlobalBounds().height - 40 &&
			body.getGlobalBounds().left + body.getGlobalBounds().height < map.getGlobalBounds().left + map.getGlobalBounds().width - 40
			)
		{
			if (movement.x != 0)
			{
				if (movement.x > 0.0f) face_right = true;
				else if (movement.x < 0.0f) face_right = false;
			}
			//body.setPosition(body.getPosition().x + movement.x, body.getPosition().y + movement.y);
			blood_1.setPosition(body.getPosition().x + 30 + movement.x, body.getPosition().y + movement.y);
			blood_2.setPosition(body.getPosition().x + 30 + movement.x, body.getPosition().y + movement.y);
		}
		else
		{
			body.setPosition(body.getPosition().x - movement.x, body.getPosition().y - movement.y);
		}
	}
	else //when is tank
	{
		body.setPosition(body.getPosition().x + movement.x, body.getPosition().y + movement.y);
		if (body.getGlobalBounds().top > map.getGlobalBounds().top + 60 &&
			body.getGlobalBounds().left > map.getGlobalBounds().left + 79 &&
			body.getGlobalBounds().top + body.getGlobalBounds().height < map.getGlobalBounds().top + map.getGlobalBounds().height - 72 &&
			body.getGlobalBounds().left + body.getGlobalBounds().height < map.getGlobalBounds().left + map.getGlobalBounds().width - 150
			)
		{
			if (movement.x != 0)
			{
				if (movement.x > 0.0f) face_right = true;
				else if (movement.x < 0.0f) face_right = false;
			}
			//body.setPosition(body.getPosition().x + movement.x, body.getPosition() .y + movement.y);
			blood_1.setPosition(body.getPosition().x + 30 + movement.x, body.getPosition().y + movement.y);
			blood_2.setPosition(body.getPosition().x + 30 + movement.x, body.getPosition().y + movement.y);
		}
		else
		{
			body.setPosition(body.getPosition().x - movement.x, body.getPosition().y - movement.y);
		}
	}
	

}

void hero::Collide() //collide with enemy
{
	if (blood_1.getSize().x > 0)
	{
		blood_1.setSize(sf::Vector2f(blood_1.getSize().x - 0.005, blood_1.getSize().y));
	}
	else is_die = true;
}

void hero::CollideBlood()
{
		blood_1.setSize(sf::Vector2f(blood_2.getSize().x +0.1, blood_1.getSize().y));
}

bool hero::IsDie()
{
	return this->is_die;
}


void hero::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	window.draw(blood_2);
	window.draw(blood_1);

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



