#pragma once
#include "lib.h"
#include "animation.h"
#include "entity.h"
class button : public entity
{
protected:
	vector <animation> anim;
	bool is_push;
public:
	button();
	void Init(int a);
	sf::Sprite* GetBody();
	void Push();
	void Draw(sf::RenderWindow& window);
};

