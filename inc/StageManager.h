#pragma once
#ifndef _STAGEMAMAGER_H_
#define _STAGEMAMAGER_H_
#include "State.h"
#include "StageManager.h"
#include "MainMenuState.h"

StateType currentState;
void _StageManager_init();
void _StageManager_update();
void _StageManager_render();
#endif