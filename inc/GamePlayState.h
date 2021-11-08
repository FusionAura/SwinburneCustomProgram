#include "State.h"
extern void _GamePlay_init();
extern void _GamePlay_Control_init();
void _GamePlayRender_init();
void _GamePlayControl(u16 joy, u16 changed, u16 state);
extern void _GamePlay_update();
extern void _GamePlay_render();