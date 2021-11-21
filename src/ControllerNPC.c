#include <ControllerNPC.h>
#define ANIM_FaceN 0
#define ANIM_TurnAround 1
#define ANIM_FaceS 2

bool canMove;

int CountdownTimer = 0;
int CountdownTimerMax = 60;
int CountdownTimerMaxWait = 60;
struct GameObject Controller = {0, 0, 0, 32, 32, 0, 0, 0, NULL};

void ControlNPC_Init()
{
    canMove = TRUE;
    /*Add the player*/
    Controller.x = 144;
    Controller.y = 8;
    Controller.active = 1;
    Controller.sprite = SPR_addSprite(&GuardChibi,Controller.x,Controller.y,TILE_ATTR(PAL2,0,FALSE,FALSE));
}

void ControlNPC_StateChange()
{
    if (!canMove)
    {
        SPR_setAnim(Controller.sprite, ANIM_FaceS);
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