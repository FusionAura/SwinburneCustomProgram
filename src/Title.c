#include <genesis.h>
#include <resources.h>
#include "Title.h"
#include "StageManager.h"


int Timer = 500;
bool Splash = TRUE;

void _Title_init()
{
    JOY_setEventHandler(&_TitleControl);
}

void _TitleRender_init()
{
    if (!Splash)
    {
        VDP_loadTileSet(bgtile.tileset,1,DMA);
        VDP_setPalette(PAL1, bgtile.palette->data);
        VDP_setPalette(PAL2, GuardMenu.palette->data);
        VDP_fillTileMapRect(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),0,0,40,30);

        VDP_drawText("Press Start to begin Demonstration", 3,27);
        VDP_drawText("COS30031 - Games Programming", 5,16);
        VDP_drawText("Custom Project", 5,18);
        VDP_setPalette(PAL1, imgLogo.palette->data);
        VDP_loadTileSet(imgLogo.tileset,1,DMA);
        VDP_drawImageEx(BG_A, &imgLogo, TILE_ATTR_FULL(PAL1, 0, 0, 0, 1), 4, 0, 0, DMA);
    }
    else
    {
        VDP_drawText("This Rom is a student project", 3,12);
        VDP_drawText("for the Games Programming Unit", 3,14);
        VDP_drawText("Unit Code: COS30031", 3,16);
        VDP_drawText("at Swinburne University, Hawthorn", 3,18);
        VDP_drawText("The SGDK by stef is Open Source", 3,20);
        VDP_drawText("& being used for Eductional purposes", 3,22);
        VDP_drawText("Press Start to continue to Start Screen", 0,26);
    }
}

void _TitleControl(u16 joy, u16 changed, u16 state)
{
	if (state & BUTTON_START)
	{
        if (!Splash)
        {
            currentState = MainMenu;
            _MainMenu_init();
            _MainMenuRenderInit();
        }
        else
        Timer = -1;
    }
}
void _Title_update()
{
    if (Splash)
    {
        Timer -=1;
        if (Timer < 0)
        {
            Splash = FALSE;
            VDP_clearText(1,2,3);
            _TitleRender_init();
        }
    }
}
void _Title_render()
{

}