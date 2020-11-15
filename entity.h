#pragma once
#include "lib.h"
class entity // class chung nhat cua 1 object
{
protected:
	sf::Sprite body;
	sf::RectangleShape blood_1;
	sf::RectangleShape blood_2;
	string tag;
public:
	entity();
	void SetPosition(float,float);
	void SetRect(float , float );
	void Scale(float, float);
	sf::Sprite GetBody();
	sf::Vector2f GetPosition();
};

