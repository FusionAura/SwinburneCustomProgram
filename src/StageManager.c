#include "StageManager.h"
#include "Title.h"
#include "MainMenuState.h"

void _StageManager_init()
{
    currentState = Title;
    _Title_init();
    _MainMenu_init();
}

void _StageManager_update()
{
     // fun_ptr_arr is an array of function pointers
    void (*updatePtr[])(StateType) = {_Title_update,_MainMenu_update };
    (*updatePtr[currentState])(currentState);

    //Attempt to get function pointers working with Game States but ran into errors.
    //Sticking to switch for now.
    
    /*switch(currentState)
    {
        case MainMenu: 
        {
            _MainMenu_update();
            break;
        }
        case Title: 
        {
            _Title_update();
            break;
        }
        case Options: 
        {
            currentState = Options;
            break;
        }
        case Gameplay: 
        {
            currentState = Gameplay;
            break;
        }
        default:
        currentState = MainMenu;
    }*/
}

void _StageManager_render()
{
    void (*renderPtr[])(StateType) = {_Title_render, _MainMenu_render};
    (*renderPtr[currentState])(currentState);
    /*switch(currentState)
    {
        case MainMenu: 
        {
            _MainMenu_render(); 
            break;
        }
        case Title: 
        {
            _Title_render();
            break;
        }
        case Options: 
        {
            currentState = Options;
            break;
        }
        case Gameplay: 
        {
            currentState = Gameplay;
            break;
        }
        default:
        currentState = MainMenu;
    }*/
}