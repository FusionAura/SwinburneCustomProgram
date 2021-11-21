
#include "Contestant.h"
#define ANIM_IDLE 0
#define ANIM_MOVE 1
#define ANIM_STOP 2
#define ANIM_DIE  3

struct GameObject Contestent[MAXCONTESTANTS];
bool Controllable = FALSE;
int speed;
int reaction;
int luck;

void Contest_Init()
{
    struct GameObject* e = Contestent;
    /*Create all enemy sprites*/
    int x = 1;
	int y = 1;
    
    for(int i = 0; i < MaxContest; i++)
	{
        e->x = (x *16);
        e->y = (y *16);
        e->w = 16;
        e->h = 16;
        e->velx = 1;
        e->active = 1;
        e->sprite = SPR_addSprite(&GuardChibi,e->x,e->y,TILE_ATTR(PAL2,0,TRUE,FALSE));
        sprintf(e->name, "En%d",i);
        RemainingContest++;
        e++;
        x++;
        if (x >= 10)
        {
            y++;
            x = 1;
        }
        //v = y;
    }
}

void Contest_Init_Render()
{

}

void Contest_Update()
{

}

void Contest_Render()
{

}
