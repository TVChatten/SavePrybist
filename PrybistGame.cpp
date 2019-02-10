#include "PrybistGame.h"

bool PrybistGame::init()
{
    if(!initSystem("Save Prybist", SCREEN_WIDTH, SCREEN_HEIGHT, false))
    {
        return false;
    }

    if(!mainMenuState.init(getInput(), getAudio(), this, &runState))
    {
        return false;
    }

    setFPS(60);

    stateManager.addState(&mainMenuState);

    return true;
}

void PrybistGame::free()
{
    mainMenuState.free();
    freeSystem();
}

void PrybistGame::update()
{
    stateManager.update();
}

void PrybistGame::draw(Graphics* g)
{
    stateManager.draw(g);
}
