#include <genesis.h>
#ifndef _ENTITY_H_
#define _ENTITY_H_

typedef struct GameObject{
	s16 id;
	Sprite* sprite;
	fix16 x;
	fix16 y;
	s16 w;
	s16 h;
	fix16 velx;
	fix16 vely;
	s16 reaction;
	s16 energy;
	bool move;
	bool Safe;
	bool Guilty;
	bool active;
	char name[6];
}GameObject;
void killEntity(struct GameObject * e);
void reviveEntity(struct GameObject* e);
#endif // _ENTITY_H_