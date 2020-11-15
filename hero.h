#pragma once
#include "lib.h"
#include "animation.h"
#include "entity.h"
class hero : public entity
{
protected:
	bool is_collide;  
	bool is_die; 
	bool face_right;
	float speed;
	vector <animation> anim;// 0.fight 1.idle 2.run 
	sf::Vector2f movement;
public:
	hero();
	void Init();
	void Idle();
	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();
	void Fight(); // the skill aren't used 
	void Update(sf::Sprite map,bool bar_is_full); // check collide with map
	void Collide(); // handle collision with the enemy
	void CollideBlood(); // add blood 
	bool IsDie();
	/*void IsCollison(entity* a);*/
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition();
	sf::Vector2f GetOrigin();
	sf::Sprite GetBody();

};