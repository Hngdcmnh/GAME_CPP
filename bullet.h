#pragma once
#include "lib.h"
#include "animation.h"
#include "entity.h"
class bullet : public entity
{
protected:
	/*sf::Sprite body;*/
	vector <animation> anim;
	int current_bullet;
	bool right;
	bool is_collide;
public:
	bullet();
	void Init();
	void Collide();
	bool Is_Collide();
	void Fire(sf::Vector2f hero_pos,bool face_right);
	void Update(/*sf::Vector2f hero_pos, bool fire, bool change, bool face_right*/);
	void Draw(sf::RenderWindow& window);
	sf::Sprite GetBullet();
	sf::Sprite GetBody();
};

