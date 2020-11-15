#pragma once
#include "button.h"
#include "state.h"
class state_menu : public state
{
protected:
	button play;
	button exit;
	button info;
public:
	state_menu();
	~state_menu();
	void Init();
	void Perform(int &score);
};

