#pragma once
#include "lib.h"
#include "state.h"
#include "hero.h"
#include "enemy.h"
#include "weapon.h"
#include "bullet.h"
#include "add_blood.h"
#include "energy_bar.h"
#include "lightning.h"
#include "collide.h"
#include "nade.h"
class state_game : public state
{
protected:
	vector <enemy> vector_enemy;
	enemy enemy_1;
	hero hero_1;
	weapon gun;
	vector <bullet> vector_bullet;
	bullet bullet_1;
	bullet bullet_2;
	energy_bar bar;
	/*lightning light_1;
	lightning light_2;*/

	nade nade_1;

	collide collide_1;
	
	add_blood add_1;
	bool face_right;
	int time;
	int current_bullet;

public:
	state_game();
	~state_game();
	void Init();
	void Perform(int &score);
};

