#pragma once
#include "entity.h"
#include "animation.h"
class add_blood:public entity //trai tim tang mau cho hero khi an
{
private:
	bool is_used;
	vector <animation> anim;
public:
	add_blood();
	~add_blood();
	void Init();  // truyen du lieu
	void New();	  // tao moi
	void Use();	  // su dung
	bool IsUse(); // kiem tra xem da su dung chua
	void Update();//cap nhat trang thai
	sf::Sprite GetBody();
	void Draw(sf::RenderWindow& window);
};

