#include <ControllerNPC.h>
#define ANIM_FaceN 0
#define ANIM_TurnAround 1
#define ANIM_FaceS 2

#define GO 65
#define STOP 66
bool canMove;

s16 CountdownTimer = 0;
s16 CountdownTimerMax = 60;
s16 CountdownTimerMaxWait = 60;
struct GameObject Controller = {0, 0, 0, 32, 32, 0, 0, 0, NULL};

void ControlNPC_Init()
{
    canMove = TRUE;
    /*Add the player*/
    Controller.x = 144;
    Controller.y = 9;
    Controller.active = 1;
    Controller.sprite = SPR_addSprite(&GuardChibi,Controller.x,Controller.y,TILE_ATTR(PAL2,0,FALSE,FALSE));

    XGM_setPCM(GO, GoSound, sizeof(GoSound));
    XGM_setPCM(STOP, StopSound, sizeof(StopSound));
}

void ControlNPC_StateChange()
{
    if (!canMove)
    {
        SPR_setAnim(Controller.sprite, ANIM_FaceS);
        XGM_startPlayPCM(GO, 1, SOUND_PCM_CH1);
    }
    else 
        SPR_setAnim(Controller.sprite, ANIM_FaceN);
        BroadcastMove(canMove);
}

void ControlNPC_Update()
{
    if (canMove)
    {
        if ( CountdownTimer < (CountdownTimerMax))
            CountdownTimer +=1;
        else 
        {
            CountdownTimer = 0;
            canMove = FALSE;
            ControlNPC_StateChange();
        }
    }
    else
    {
        if ( CountdownTimer < (CountdownTimerMaxWait))
            CountdownTimer +=1;
        else 
        {
            CountdownTimer = 0;
            canMove = TRUE;
            ControlNPC_StateChange();
        }
    }

}