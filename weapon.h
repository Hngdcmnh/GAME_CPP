#pragma once
#include "SFML/Graphics.hpp"
#include "entity.h"
#include "animation.h"
class weapon : public entity //weapon of hero (gun/ tank)
{
protected:
	vector <animation> anim;
	int current_weapon;
	bool fire;
 public:
	weapon();
	void Init();
	void Change(); // when bar_2 is full or is decreasing, you can call tank
	int CurrentWeapon();
	void Default(); // return gun
	void Update(sf::Vector2f hero_pos,bool face_right);
	void Draw(sf::RenderWindow& window);
	sf::Sprite GetBody();
};

