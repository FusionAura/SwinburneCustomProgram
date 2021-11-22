#include <genesis.h>
#include "entity.h"
#include "GamePlayState.h"
#include "resources.h"
bool GlobalMove;

void Contest_Init();
void Contest_Init_Render();

void Contest_Update();

void Contest_Render();

void CheckReaction(bool MovingCheck);
void StopMoving( struct GameObject* e, bool MovingCheck);