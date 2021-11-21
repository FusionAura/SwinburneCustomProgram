#include "State.h"
#ifndef _TITLE_H_
#define _TITLE_H_

void _Title_init();
void _TitleRender_init();
extern void _Title_update();
extern void _Title_render();
extern void _TitleControl(u16 joy, u16 changed, u16 state);

#endif