#include "State.h"
#include "resources.h"
#include "entity.h"


#define MAP_WIDTH           640
#define MAP_HEIGHT          640

#define MIN_POSX            FIX32(10L)
#define MAX_POSX            FIX32(MAP_WIDTH - 100)

#define STARTLINE           FIX32(MAP_HEIGHT - 32)
#define FINISHLINE              FIX32(32)

#define MAXCONTESTANTS      32

int MaxContest;

int RemainingContest;
int Prize;

extern void _GamePlay_init();
extern void _GamePlay_Control_init();
void _GamePlayRender_init();
void _GamePlayControl(u16 joy, u16 changed, u16 state);
extern void _GamePlay_update();
extern void _GamePlay_render();

GameObject* Guilty;