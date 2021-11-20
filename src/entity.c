#include <genesis.h>
#include "entity.h"
void killEntity(struct Entity * e){
	e->active = 0;
	SPR_setVisibility(e->sprite,HIDDEN);
}

void reviveEntity(struct Entity * e){
	e->active = 1;
	SPR_setVisibility(e->sprite,VISIBLE);
}