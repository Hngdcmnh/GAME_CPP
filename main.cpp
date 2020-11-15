#include <SFML/Graphics.hpp>
#include "hero.h"
#include "enemy.h"
#include "bullet.h"
#include "weapon.h"
#include "state_game.h"
#include "state_menu.h"
#include "state_end.h"
using namespace std;
int main()
{
	int score = 0;
	bool game_start = 0;
	state_menu menu_1; // menu
	menu_1.Init();
	menu_1.Perform(score);
	
	state_game game_1; //game play
	game_1.Init();
	game_1.Perform(score);

	state_end end_1; //end game
	end_1.Init();
	end_1.Perform(score);

}