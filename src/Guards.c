#include "Guards.h"
#define ANIM_FaceS 2
struct GameObject Guards[MAXGUARDS];

void Guards_Init()
{
    struct GameObject* g = Guards;
    fix16 x = 0;
    fix16 y = 1;
    for(s16 i = 0; i < MaxGuards; i++)
	{
        g->x = 16+(x *254);
        g->y = (8);
        g->w = 32;
        g->h = 32;
        g->velx = 0;
        g->vely = 0;
        g->sprite = SPR_addSprite(&GuardChibi,g->x,g->y,TILE_ATTR(PAL2,0,FALSE,FALSE));
        SPR_setAnim(g->sprite, ANIM_FaceS);
        g++;
        x++;
    }
}

void Shoot(struct GameObject* e)
{
    for (s16 i = 0; i<RemainingContest;i++)
    {
        if (!e->Safe && e->Guilty && e->active)
        {
            killEntity(e);
            RemainingContest --;
        }
    }
}

void Guards_Update(GameObject* e)
{
   
}