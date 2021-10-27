#include <genesis.h>
#include <resources.h>
#include "Title.h"
#include "StageManager.h"

void _Title_init()
{
    JOY_setEventHandler(&MenuControl);
}
void MenuControl(u16 joy, u16 changed, u16 state)
{
	if (state & BUTTON_START)
	{
        currentState = MainMenu;
    }
}
void _Title_update()
{
    
}
void _Title_render()
{
    VDP_drawText("Press Start to begin Demonstration", 3,27);
    VDP_drawText("COS30031 - Games Programming", 5,16);
    VDP_drawText("Custom Project", 5,18);
    VDP_setPalette(PAL1, imgLogo.palette->data);
    VDP_loadTileSet(imgLogo.tileset,1,DMA);
    VDP_drawImageEx(BG_A, &imgLogo, TILE_ATTR_FULL(PAL1, 0, 0, 0, 1), 4, 0, 0, DMA);
}