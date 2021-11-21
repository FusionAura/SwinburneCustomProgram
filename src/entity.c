#include <genesis.h>
#include "entity.h"
void killEntity(struct GameObject * e){
	e->active = FALSE;
	SPR_setVisibility(e->sprite,HIDDEN);
}

void reviveEntity(struct GameObject * e){
	e->active = TRUE;
	SPR_setVisibility(e->sprite,VISIBLE);
}


void DestroyEntity(struct GameObject * e){
	e->active = FALSE;
	e->x =0;
	e->y = 0;
	e->w = 0;
	e->h = 0;
	e->velx = 0;
	e->vely = 0;
	e->sprite = NULL;
	SPR_setVisibility(e->sprite,HIDDEN);
	MEM_free(e);
}