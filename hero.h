#pragma once
#include "lib.h"
#include "animation.h"
#include "entity.h"
class hero : public entity
{
protected:
	/*sf::Sprite body;*/
	bool face_right;
	float speed;
	vector <animation> anim;// 0.fight 1.idle 2.run 
	sf::Vector2f movement;
public:
	hero(float speed);
	void Init();
	void Idle();
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void Fight();
	void Update();
	/*void IsCollison(entity* a);*/
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition();
	sf::Vector2f GetOrigin();
	sf::Sprite GetBody();

};