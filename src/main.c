#include <genesis.h>
#include "StageManager.h"

int main()
{
    JOY_init();
	
	SYS_disableInts();	
	VDP_setScreenWidth320();
	VDP_setScreenHeight224();
	SPR_init();
    
    VDP_setTextPlane(BG_A);

    //No OO unfortunately so need to find alternative ways of running the other scripts
    _StageManager_init();
    
    while(1)
    {
        _StageManager_render();
        SPR_update();
        
        //For versions prior to SGDK 1.60 use VDP_waitVSync instead.
        SYS_doVBlankProcess();
        _StageManager_update();
    }
    return (0);
}
