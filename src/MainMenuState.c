#include "MainMenuState.h"
#include <resources.h>

int score = 0;
char str_score[10] = "0";
Sprite* guardMenu;

u16* CharTest = CharacterProfile;

void _MainMenu_init()
{
    //Run any init code here.
}

void _MainMenu_update()
{
    
}

void _MainMenu_render()
{
    VDP_loadTileSet(bgtile.tileset,1,DMA);
    VDP_setPalette(PAL1, bgtile.palette->data);
    VDP_setPalette(PAL2, GuardMenu.palette->data);
    VDP_fillTileMapRect(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),0,0,40,30);
    
	VDP_clearText(1,2,3);
	VDP_drawText("Main Menu",1,2); 

    VDP_drawText("Start Demo",1,10);
    VDP_drawText("Options",1,12);

    sprintf(str_score,"%d",CharacterProfile);
    VDP_drawText(str_score,1,13);
    
    guardMenu = SPR_addSprite(&GuardMenu,100,64,TILE_ATTR(PAL2,0, FALSE, FALSE));
}
