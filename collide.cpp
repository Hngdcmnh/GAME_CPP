#include "collide.h"

collide::collide()
{

}

void collide::Init()
{
	sf::Texture a2;
	a2.loadFromFile("./texture/weapon/explode_2.png");
	animation b2(a2, 8, 0.009);
	anim = b2;
	/*body.scale(0.07, 0.07);*/
	anim.Update(true, true);
	anim.SetTextureForSprite(body);
	is_exist = false;
}

void collide::SetPosition(sf::Vector2f enemy_pos,bool face_right)
{
	is_exist = true;
	time = 0;
	
	if(face_right) this->body.setPosition(enemy_pos.x+80,enemy_pos.y-40);
	else  this->body.setPosition(enemy_pos.x -80, enemy_pos.y - 40);
}

void collide::Update()
{
	time += 10;
	anim.Update(true, true);
	anim.SetTextureForSprite(body);
	if (time >= 2700) is_exist = false;
}

void collide::Draw(sf::RenderWindow& window)
{
	if(is_exist)window.draw(body);
}
