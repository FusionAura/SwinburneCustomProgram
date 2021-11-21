#include <genesis.h>
#ifndef _ENTITY_H_
#define _ENTITY_H_

typedef struct GameObject{
	int id;
	Sprite* sprite;
	int x;
	int y;
	int w;
	int h;
	int velx;
	int vely;
	int reaction;
	int energy;
	bool Safe;
	bool active;
	char name[6];
}GameObject;


void killEntity(struct GameObject* e);
void reviveEntity(struct GameObject* e);
#endif // _ENTITY_H_