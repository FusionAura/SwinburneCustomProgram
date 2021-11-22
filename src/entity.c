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