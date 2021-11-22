#include "State.h"
#include "resources.h"
#include "entity.h"


#define MAP_WIDTH           320
#define MAP_HEIGHT          224

#define MIN_POSX            FIX32(10L)
#define MAX_POSX            FIX32(MAP_WIDTH - 100)

#define STARTLINE           FIX32(MAP_HEIGHT - 64)
#define FINISHLINE          8
#define MAXCONTESTANTS      8
#define MAXGUARDS           2
s16 MaxContest;
s16 MaxGuards;
bool BroadcastCanMove;
s16 RemainingContest;
s16 Prize;

extern void _GamePlay_init();
extern void _GamePlay_Control_init();
void _GamePlayRender_init();
void _GamePlayControl(u16 joy, u16 changed, u16 state);
extern void _GamePlay_update();
extern void _GamePlay_render();
void BroadcastMove(bool canMoveCall);
GameObject* Guilty;