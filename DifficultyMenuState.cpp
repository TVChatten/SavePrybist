#include "DifficultyMenuState.h"

bool DifficultyMenuState::init(Input* i)
{
    input = i;

    if(!backgroundImage.load("graphics/menus/credits/background.bmp"))
        return false;

    return true;
}

void DifficultyMenuState::free()
{
    backgroundImage.free();
}

void DifficultyMenuState::update()
{
    if(input->keyDown(SDLK_SPACE))
    {
        free();
        getManager()->popState();
    }
}

void DifficultyMenuState::draw(Graphics* g)
{
    backgroundImage.draw(0,0,g);
}


