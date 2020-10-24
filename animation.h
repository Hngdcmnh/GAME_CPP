#pragma once
#include"lib.h"
class animation
{
protected:
	sf::Texture texture;
	float current_image;
	int image_count;
	float skill_speed;
	bool is_weapon;
public:
	animation();
	animation(sf::Texture texture, int image_count,float skill_speed);
	void Update(bool face_right,bool is_weapon);
	sf::IntRect rect;
	void SetTextureForSprite(sf::Sprite& s);

};

