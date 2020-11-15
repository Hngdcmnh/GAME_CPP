#pragma once
#include "lib.h"
#include "animation.h"
#include "entity.h"
class energy_bar : public entity
{
protected:
	vector <animation> anim;
	sf::Sprite energy_bar_3; // the lightning
	sf::RectangleShape energy_bar_1; // the length of the bar_1 is fixed
	sf::RectangleShape energy_bar_2; // the length of the bar_2 is not fixed
									 // bar_2 increases when enemy is shot with gun 
									 // when bar_2 is full, can call tank
	bool plus;
	bool is_full;
public:
	energy_bar();
	void Init();
	void Plus();
	void Update(sf::Vector2f hero_pos);
	void Draw(sf::RenderWindow& window);
	bool IsFull();
};

