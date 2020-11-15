#pragma once
#include "SFML/Graphics.hpp"
#include "animation.h"
#include "entity.h"
class nade : public entity //grenade of hero
{
protected:
	vector <animation> anim;
	bool is_exist;
	float time_exist;
	bool is_explode;
	float ground;
	bool face_right;
	sf::Vector2f movement;
public:
	nade();
	void Init();
	bool IsExplode();
	void SetPosition(sf::Vector2f hero_pos,bool face_right);
	void Update();
	void Draw(sf::RenderWindow& window);
};

