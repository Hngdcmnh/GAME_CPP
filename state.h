#pragma once
#include "lib.h"

using namespace std;
class state
{
public:
	state();
	virtual ~state();
	virtual void Init() = 0;
	virtual void Perform(int &score) = 0;



};


















//virtual void Exit() = 0;
//virtual void Pause() = 0;
//virtual void Resume() = 0;