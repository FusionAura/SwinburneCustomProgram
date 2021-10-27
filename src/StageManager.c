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
    switch(currentState)
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
    }
}

void _StageManager_render()
{
    switch(currentState)
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
    }
    
}