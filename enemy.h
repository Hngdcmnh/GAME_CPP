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
	bool is_die;
	vector <animation> anim;
public:
	enemy(float speed);
	void Init();
	void Update(sf::Vector2f hero_pos);
	void Die(bool is_die);
	bool IsDie();
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition();
	sf::Sprite GetBody();
};

