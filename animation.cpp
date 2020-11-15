#include "animation.h"


animation::animation()
{
}

animation::animation(sf::Texture texture, int image_count,float skill_speed)
{
	this->skill_speed = skill_speed;
	this->texture = texture;
	this->image_count = image_count;
	rect.width = texture.getSize().x / image_count; // use rect to print 1 of many images
	rect.height = texture.getSize().y ;             // in the images list
	current_image = 0;
	rect.top = 0;
}

void animation::SetCurrentImage()
{
	this->current_image = 0;
}



void animation::Update(bool face_right,bool is_weapon)
{

	/*if (!is_weapon)
	{*/
		if (current_image >= image_count)  // Browse each image in the image list
		{
			current_image = 0;
		}
		else current_image += skill_speed;
	/*}
	else current_image = 0;*/
	
	rect.top = 0 * rect.height;

	//turn left - turn right
	if (face_right)
	{
		rect.left = (int)current_image * rect.width;
		rect.width = abs(rect.width);
	}
	else
	{
		rect.left = (int)(current_image + 1) * abs(rect.width);
		rect.width = -abs(rect.width);
	}
}

void animation::SetTextureForSprite(sf::Sprite& s)
{
	s.setTexture(texture); 
	s.setTextureRect(rect);
}




