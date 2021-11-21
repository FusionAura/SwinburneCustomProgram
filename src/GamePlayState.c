#include <genesis.h>
#include "StageManager.h"
#include "resources.h"
#include "GamePlayState.h"
#include "ControllerNPC.h"

// absolute camera position (pixel)

void _GamePlay_init(int mode)
{
    MaxContest = MAXCONTESTANTS;
    currentState = Gameplay;
    JOY_setEventHandler(&_GamePlayControl);
    _GamePlayRender_init();

    //Call Controller Init to instaniate it
    ControlNPC_Init();

    //Call Guard Init to instaniate them

    //Call Contestent Init to instaniate them
    Contest_Init();
}
void _GamePlay_Control_init()
{
    currentState = Gameplay;
    MaxContest = MAXCONTESTANTS;
    JOY_setEventHandler(&_GamePlayControl);
    _GamePlayRender_init();
    ControlNPC_Init();
}
void _GamePlayRender_init()
{
    VDP_clearText(1,2,3);


    VDP_loadTileSet(bgtile.tileset,1,DMA);
    VDP_setPalette(PAL1, bgtile.palette->data);
    VDP_fillTileMapRect(BG_A,TILE_ATTR_FULL(PAL1,0,FALSE,FALSE,1),0,0,40,30);

    VDP_loadTileSet(bgFinish.tileset,2,DMA);
    VDP_setPalette(PAL2, bgFinish.palette->data);
    VDP_fillTileMapRect(BG_A,TILE_ATTR_FULL(PAL2,0,FALSE,FALSE,2),0,4,40,4);
    
}

void _GamePlayControl(u16 joy, u16 changed, u16 state)
{

}
void _GamePlay_update()
{
    ControlNPC_Update();
}
void _GamePlay_render()
{
   ControlNPC_Render();
}