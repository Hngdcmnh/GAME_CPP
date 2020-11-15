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
	void Collide(); // Handle collision when bullet collide with enemy
					// Just make the bullet disappear
	bool Is_Collide();
	void Fire(sf::Vector2f hero_pos,bool face_right); //Print bullet at location and direction of hero
	void Update();
	void Draw(sf::RenderWindow& window);
	sf::Sprite GetBullet(); // get sprite body
};

