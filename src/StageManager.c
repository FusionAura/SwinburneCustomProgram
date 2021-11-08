#include "StageManager.h"
#include "Title.h"
#include "MainMenuState.h"
#include "OptionState.h"
#include "GamePlayState.h"
void _StageManager_init()
{
    currentState = Title;
    _Title_init();
    _TitleRender_init();
}

void _StageManager_update()
{
     // fun_ptr_arr is an array of function pointers
    void (*updatePtr[])(StateType) = {_Title_update,_MainMenu_update, _GamePlay_update, _Option_update };
    (*updatePtr[currentState])(currentState);
}

void _StageManager_render()
{
    void (*renderPtr[])(StateType) = {_Title_render, _MainMenu_render, _GamePlay_render, _Option_render};
    (*renderPtr[currentState])(currentState);
}