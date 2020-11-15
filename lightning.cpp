#include "lightning.h"

lightning::lightning()
{
}
//. / texture / map /
void lightning::Init()
{
	sf::Texture a2;
	a2.loadFromFile("./texture/map/lightning.png");
	animation b2(a2, 1, 0.01);
	anim = b2;
	body.scale(0.07, 0.07);
	anim.Update(true, true);
	anim.SetTextureForSprite(body);
	is_exist = false;
}

void lightning::SetPosition(sf::Vector2f enemy_pos)
{
	this->body.setPosition(enemy_pos);
	is_exist = true;
}

void lightning::Update(sf::Vector2f hero_pos)
{
	if(is_exist) body.move((hero_pos.x +175 - body.getPosition().x)*0.01, (hero_pos.y -290 - body.getPosition().y)*0.01);
	if (body.getPosition().x >= hero_pos.x + 190 || body.getPosition().y <= hero_pos.y - 280)
	{
		is_exist = false;
	}
}

void lightning::Draw(sf::RenderWindow& window)
{
	if(is_exist) window.draw(body);
}

