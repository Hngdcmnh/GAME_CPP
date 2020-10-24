#pragma once
#include "SFML/Graphics.hpp"
#include "animation.h"
class weapon
{
protected:
	sf::Sprite body;
	vector <animation> anim;
	int current_weapon;
	bool fire;
 public:
	weapon();
	void Init();
	void Change();
	void Update(sf::Vector2f hero_pos,bool face_right);
	void Draw(sf::RenderWindow& window);
	sf::Sprite GetGun();
};

