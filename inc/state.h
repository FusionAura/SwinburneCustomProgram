#include <genesis.h>
#pragma once
//Code based on example code from Tutor
#ifndef _GAMESTATE_
#define _GAMESTATE_

typedef enum gameState
{ 
	NoState,
    Title,
	MainMenu, 
    Options,
    Gameplay
}StateType;
#endif

