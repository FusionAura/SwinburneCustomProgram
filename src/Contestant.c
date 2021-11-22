
#include "Contestant.h"
#define ANIM_IDLE 0
#define ANIM_MOVE 1
#define ANIM_STOP 2
#define ANIM_DIE  3

struct GameObject Contestent[MAXCONTESTANTS];
bool Controllable = FALSE;
fix16 speed = 10; //Base speed value

s16 reactionwait = 0;
s16 reactionwaitMax = 15;
void Contest_Init()
{
    u16 rand = random() % (2 - 1 + 1);
    
    struct GameObject* e = Contestent;
    //MaxContest = MAXCONTESTANTS;
    /*Create all enemy sprites*/
    fix16 x = 0;
    fix16 y = 1;
    for(s16 i = 0; i < MaxContest; i++)
	{
        fix16 randomSpd = FIX16(rand + 1);
        e->x = 32+(x *32);
        e->y = FIX16(152+ (y*16));
        e->w = 32;
        e->h = 32;
        e->velx = 1;
        e->vely = random()% 10 + speed;
        e->energy = random()% 5+1;
        e->reaction = random()% 100;
        e->active = 1;
        e->Safe = FALSE;
        e->Guilty = FALSE;
        e->sprite = SPR_addSprite(&GuardChibi,e->x,e->y,TILE_ATTR(PAL2,0,FALSE,FALSE));
        sprintf(e->name, "En%d",i);
        RemainingContest++;
        e->move = TRUE;

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
    for(s16 i = 0; i < MaxContest; i++)
    {
        struct GameObject* e = &Contestent[i];
        if (!e->Safe)
        {
            if (e->y < FINISHLINE)
                e->Safe = TRUE;
            else if (e->move)
            { 
                if(e->active > 0)
                {
                    e->y = fix16Sub(e->y,e->vely);
                    SPR_setPosition(e->sprite, e->x, fix16ToInt(e->y));
                }
            }
        }            
    }
}

void CheckReaction(bool MovingCheck)
{
    GlobalMove = MovingCheck;
    for(s16 i = 0; i < MaxContest; i++)
    {
        struct GameObject* e = &Contestent[i];
        if (!GlobalMove)
            StopMoving(e,GlobalMove);
        else
             e->move = MovingCheck;
    }
}

void StopMoving( struct GameObject* e, bool MovingCheck)
{
    e->reaction = random()% 100;
    if (e->reaction < 75)
        e->move = MovingCheck;
    else
    {
        e->Guilty = TRUE;
        CaughtMoving(e);
        
    }
}
