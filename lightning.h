#pragma once
#include "SFML/Graphics.hpp"
#include "animation.h"
#include "entity.h"
class lightning : public entity
{
protected:
	animation anim;
	bool is_exist;
public:
	lightning();
	void Init();
	void SetPosition(sf::Vector2f enemy_pos);
	void Update(sf::Vector2f hero_pos);
	void Draw(sf::RenderWindow& window);
};

