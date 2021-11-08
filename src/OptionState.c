#include <genesis.h>
#include <resources.h>
#include "OptionState.h"

void _Option_init()
{
    JOY_setEventHandler(&_OptionControl);
    _OptionRender_init();
}

void _OptionRender_init()
{
    VDP_clearText(1,2,3);

    VDP_loadTileSet(bgtile.tileset,1,DMA);
    VDP_setPalette(PAL1, bgtile.palette->data);
    VDP_setPalette(PAL2, GuardMenu.palette->data);
    VDP_fillTileMapRect(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),0,0,40,30);
    
	
	VDP_drawText("Test Option",1,2); 
}

void _OptionControl(u16 joy, u16 changed, u16 state)
{

}
void _Option_update()
{
    //
}
void _Option_render()
{

}