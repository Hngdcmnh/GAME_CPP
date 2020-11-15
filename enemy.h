#pragma once
#include "lib.h"
#include "animation.h"
#include "entity.h"

class enemy : public entity 
{
protected:
	/*sf::Sprite body;*/
	bool face_right;
	float speed;
	bool is_die; // when enemy collide with bullet or edge of map they die
	vector <animation> anim;
	bool is_shoot; // score only increase when the enemy is chot with gun 
public:
	enemy();
	void Init();
	void Collide(int &score);
	void Update(sf::Vector2f hero_pos); // the enemy is always chasing hero
	void Die(bool is_die);
	bool IsDie();
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition();
	sf::Sprite GetBody();
};

