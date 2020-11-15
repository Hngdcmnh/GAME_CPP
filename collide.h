#pragma once
#include "lib.h"
#include "animation.h"
#include "entity.h"
class collide : public entity // animation (explosion) for collision when bullet collide with enemy
{                             //(Collide() of bullet.h just make the bullet disappear )
protected:
	animation anim;
	bool is_exist;
	int time ;
public:
	collide();
	void Init();
	void SetPosition(sf::Vector2f enemy_pos,bool face_right);
	void Update();
	void Draw(sf::RenderWindow& window);
};

