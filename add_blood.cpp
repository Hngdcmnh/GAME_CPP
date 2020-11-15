#include "add_blood.h"

add_blood::add_blood()
{
    this->is_used = true;
    anim.resize(2);
}

add_blood::~add_blood()
{
}

void add_blood::Init()
{
    body.setScale(2,2);
    sf::Texture a1;
    a1.loadFromFile("./texture/map/Big Heart Idle (18x14).png");
    animation b1(a1, 8, 0.008);
    anim[0] = b1;
    anim[0].Update(true, 0);
    anim[0].SetTextureForSprite(body);
}

void add_blood::Use()
{
    this->is_used = true;
}

bool add_blood::IsUse()
{
    return this->is_used;
}

void add_blood::New()
{
    float x = rand() % (1000 - 100 + 1) + 100;
    float y = rand() % (1000 - 100 + 1) + 100;
    body.setPosition(x, y);
    this->is_used = false;
}


void add_blood::Update()
{
    anim[0].Update(true, 0);
    anim[0].SetTextureForSprite(body);
}

sf::Sprite add_blood::GetBody()
{
    return this->body;
}

void add_blood::Draw(sf::RenderWindow& window)
{
    if (is_used == false)window.draw(body);
}
