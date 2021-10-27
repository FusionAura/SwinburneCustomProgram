#include "MainMenuState.h"
#include <resources.h>

int score = 0;
char str_score[10] = "0";

void _MainMenu_init()
{
    //Run any init code here.
}

void _MainMenu_update()
{
    score  ++;
    if (score >10)
    score  = 0;
}

void _MainMenu_render()
{
    VDP_loadTileSet(bgtile.tileset,1,DMA);
    VDP_setPalette(PAL1, bgtile.palette->data);
    VDP_fillTileMapRect(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),0,0,40,30);
    
    sprintf(str_score,"%d",score);
	VDP_clearText(1,2,3);
	VDP_drawText("Main Menu",1,2); 

    VDP_drawText("Start Demo",1,10);
    VDP_drawText("Options",1,12);
}
