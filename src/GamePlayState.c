#include <genesis.h>
#include <resources.h>
#include "GamePlayState.h"

void _GamePlay_init(int mode)
{
    JOY_setEventHandler(&_GamePlayControl);
    _GamePlayRender_init();
}
void _GamePlay_Control_init()
{
    JOY_setEventHandler(&_GamePlayControl);
    _GamePlayRender_init();
}
void _GamePlayRender_init()
{
    VDP_clearText(1,2,3);

    VDP_loadTileSet(bgtile.tileset,1,DMA);
    VDP_setPalette(PAL1, bgtile.palette->data);
    VDP_setPalette(PAL2, GuardMenu.palette->data);
    VDP_fillTileMapRect(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),0,0,40,30);
	VDP_drawText("Test Game Start",1,2); 
}

void _GamePlayControl(u16 joy, u16 changed, u16 state)
{

}
void _GamePlay_update()
{
    //
}
void _GamePlay_render()
{

}