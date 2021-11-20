#include <genesis.h>

#ifndef _ENTITY_H_
#define _ENTITY_H_

typedef struct Entity{
	int x;
	int y;
	int w;
	int h;
	int velx;
	int vely;
	int active;
	Sprite* sprite;
	char name[6];
}Entity;
void killEntity(struct Entity* e);
void reviveEntity(struct Entity* e);
#endif // _ENTITY_H_