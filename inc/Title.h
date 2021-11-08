#include "State.h"

int timer = 200;
bool Splash = TRUE;
void _Title_init();
void _TitleRender_init();
extern void _Title_update();
extern void _Title_render();
void _TitleControl(u16 joy, u16 changed, u16 state);

