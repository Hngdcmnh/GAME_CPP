#pragma once
#include"lib.h"
class animation
{
protected:
	sf::Texture texture;
	float current_image; //the image is a image list, uses current image to represent printed image location  
	int image_count; // how many images in image list
	float skill_speed; // scene velocity
	bool is_weapon; // check is weapon? because weapon have only 1 state
public:
	animation();
	animation(sf::Texture texture, int image_count,float skill_speed);
	void SetCurrentImage();
	void Update(bool face_right,bool is_weapon);
	sf::IntRect rect;
	void SetTextureForSprite(sf::Sprite& s);

};

