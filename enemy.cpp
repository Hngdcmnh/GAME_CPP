#include "enemy.h"

enemy::enemy()
{
	this->anim.resize(4);
	face_right = true;
	this->speed = 0.0005f;
	srand(time(NULL));
	float x = rand() % (2000 - 100 + 1) + 100; //enemy position are generated randomly
	float y = rand() % (1000 - 100 + 1) + 100;
	body.setPosition(x,y);


	this->is_die = false;
	this->is_shoot = false;
	blood_1.setPosition(body.getPosition().x, body.getPosition().y - 30); // blood of enemy consits of red and white bars overlapping
	blood_2.setPosition(body.getPosition().x, body.getPosition().y - 30);

}

void enemy::Init()
{
	sf::Texture a1;
	a1.loadFromFile("./texture/enemy/Skeleton Attack.png");
	animation b1(a1, 18, 0.01);
	anim[0] = b1;
	sf::Texture a2;
	a2.loadFromFile("./texture/enemy/Skeleton Idle.png");
	animation b2(a2, 11, 0.01);
	anim[1] = b2;
	sf::Texture a3;
	a3.loadFromFile("./texture/enemy/Skeleton Walk.png");
	animation b3(a3, 13, 0.01);
	anim[2] = b3;
	sf::Texture a4;
	a3.loadFromFile("./texture/enemy/Skeleton Dead.png");
	animation b4(a4, 15, 0.01);
	anim[3] = b4;
	anim[0].Update(face_right,0);
	body.setScale(1.5f, 1.5f);
	anim[0].SetTextureForSprite(body);
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
	blood_1.setPosition(body.getPosition().x + movement.x, body.getPosition().y-10 + movement.y);
	blood_2.setPosition(body.getPosition().x + movement.x, body.getPosition().y-10 + movement.y);
}

void enemy::Collide(int &score) // Just consider colliding with bullet
{
	this->is_shoot = true;
	if (blood_1.getSize().x > 0)
	{
		blood_1.setSize(sf::Vector2f(blood_1.getSize().x - 0.05, blood_1.getSize().y));
	}
	else
	{
		is_die = true;
		score += 10;
	}
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
	if (this->is_die == false)
	{
		window.draw(blood_2);
		window.draw(blood_1);
		window.draw(body);
	}
}

sf::Vector2f enemy::GetPosition()
{
	return this->body.getPosition();
}

sf::Sprite enemy::GetBody()
{
	return body;
}
