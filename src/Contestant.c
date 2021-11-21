
#include "Contestant.h"
#define ANIM_IDLE 0
#define ANIM_MOVE 1
#define ANIM_STOP 2
#define ANIM_DIE  3

struct GameObject Contestent[MAXCONTESTANTS];
bool Controllable = FALSE;
int speed = 1; //Base speed value


void Contest_Init()
{
    move = TRUE;
    struct GameObject* e = Contestent;
    //MaxContest = MAXCONTESTANTS;
    /*Create all enemy sprites*/
    int x = 0;
    int y = 1;
    for(int i = 0; i < MaxContest; i++)
	{
        e->x = (x *32);
        e->y = 152+ (y*16);
        e->w = 32;
        e->h = 32;
        e->velx = 1;
        e->vely = random()% 2+1;
        e->energy = random()% 5+1;
        e->reaction = random()% 2+1;
        e->active = 1;
        e->Safe = FALSE;
        e->sprite = SPR_addSprite(&GuardChibi,e->x,e->y,TILE_ATTR(PAL2,0,FALSE,FALSE));
        sprintf(e->name, "En%d",i);
        RemainingContest++;
        e++;
        x++;
        if (x > 12)
        {
            y++;
            x = 0;
        }
    }

    
}

void Contest_Init_Render()
{

}

void Contest_Update()
{
    for(int i = 0; i < MaxContest; i++)
    {
        struct GameObject* e = &Contestent[i];
        if (!e->Safe)
        {
            if (move)
            { 
                if(e->active > 0)
                {
                    e->y -= e->vely;
                    SPR_setPosition(e->sprite, e->x, e->y);
                }
            }
            if (e->y < FINISHLINE)
            {
                e->Safe = TRUE;
            }
        }
    }
}

void StopMoving(bool MovingCheck)
{
    int i = 0;
    for(i = 0; i < MaxContest; i++)
    {
        struct GameObject* e = &Contestent[i];
        move = MovingCheck;
    }
}
