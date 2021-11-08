#include "MainMenuState.h"
#include "GamePlayState.h"
#include "OptionState.h"
#include <resources.h>

#define ANIM_UP 0
#define ANIM_MIDDLE 1
#define ANIM_DOWN 2


u16* CharTest = CharacterProfile;

void _MainMenu_init()
{
    JOY_setEventHandler(&_MenuControl);

}

void _MainMenuRenderInit()
{
    VDP_clearText(1,2,3);
    guardMenu = SPR_addSprite(&GuardMenu,30,128,TILE_ATTR(PAL2,0, FALSE, FALSE));
    SPR_setHFlip(guardMenu,TRUE);

    VDP_loadTileSet(bgtile.tileset,1,DMA);
    VDP_setPalette(PAL1, bgtile.palette->data);
    VDP_setPalette(PAL2, GuardMenu.palette->data);
    VDP_fillTileMapRect(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),0,0,40,30);
    
	
	VDP_drawText("Main Menu",1,2); 

    VDP_drawText("Start Demo",12,16);
    VDP_drawText("Playable Demo",12,19);
    VDP_drawText("Options",12,22);

    
}

void _MenuControl(u16 joy, u16 changed, u16 state)
{
	if (state & BUTTON_UP )
	{
        Menu --;
        if (Menu < 0)
            Menu +=3;
    }
    else if (state & BUTTON_DOWN)
	{
        Menu ++;
        if (Menu > 2)
            Menu -=3;
    }
    else if (state && BUTTON_START)
    {
        // fun_ptr_arr is an array of function pointers
        void (*initPtr[])(int) = {_GamePlay_init, _GamePlay_Control_init, _Option_init};
        (*initPtr[Menu])(Menu); 
    }
}
void _MainMenu_update()
{
    
}

void _MainMenu_render()
{
    SPR_setFrame(guardMenu,Menu);
}
