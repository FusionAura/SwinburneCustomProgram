#include "State.h"
#include <string.h>

#ifndef _MAINMENUSTATE_H_
#define _MAINMENUSTATE_H_
#pragma once

Sprite* guardMenu;
int Menu = 0;
void _MenuControl(u16 joy, u16 changed, u16 state);
void _MainMenu_init();
void _MainMenuRenderInit();
extern void _MainMenu_render();
extern void _MainMenu_update();

#endif
