#include "MainMenuState.h"

bool MainMenuState::init(Input* i, Audio* a, Game* g, RunState* r)
{
    audio = a;
    input = i;
    game = g;
    runState = r;

    if(!background.load("graphics/menus/main/background.bmp"))
    {
        return false;
    }

    if(!startButtonImage.load("graphics/menus/main/start_game_button.bmp"))
    {
        return false;
    }

    if(!creditsButtonImage.load("graphics/menus/main/credits_button.bmp"))
    {
        return false;
    }

    if(!exitButtonImage.load("graphics/menus/main/exit_button.bmp"))
    {
        return false;
    }

     if(!easyButtonImage.load("graphics/menus/main/easy_button.bmp"))
    {
        return false;
    }

     if(!mediumButtonImage.load("graphics/menus/main/medium_button.bmp"))
    {
        return false;
    }

     if(!hardButtonImage.load("graphics/menus/main/hard_button.bmp"))
    {
        return false;
    }

    if(!song.load("audio/music/menu.mp3"))
    {
        return false;
    }

    if(!difficultyImage.load("graphics/menus/main/difficulty.bmp")) {
        return false;
    }

    startButton.setImage(&startButtonImage);
    creditsButton.setImage(&creditsButtonImage);
    exitButton.setImage(&exitButtonImage);
    easyButton.setImage(&easyButtonImage);
    mediumButton.setImage(&mediumButtonImage);
    hardButton.setImage(&hardButtonImage);

    startButton.setPos(BUTTON_X, BUTTON_Y);
    creditsButton.setPos(BUTTON_X, BUTTON_Y+BUTTON_SPACING);
    exitButton.setPos(BUTTON_X, BUTTON_Y+BUTTON_SPACING*2);
    easyButton.setPos(-100, -100);
    mediumButton.setPos(-100, -100);
    hardButton.setPos(-100, -100);

    screenWidth = game->getGraphics()->getWidth();
    screenHeight = game->getGraphics()->getHeight();

    return true;
}

void MainMenuState::openDifficultyMenu()
{
    startButton.setPos(-100, -100);
    creditsButton.setPos(-100, -100);
    exitButton.setPos(-100, -100);

    easyButton.setPos(BUTTON_X, BUTTON_Y+BUTTON_SPACING);
    mediumButton.setPos(BUTTON_X, BUTTON_Y+BUTTON_SPACING*2);
    hardButton.setPos(BUTTON_X, BUTTON_Y+BUTTON_SPACING*3);

    canDrawDifficulty = true;
}

void MainMenuState::hideDifficultyMenu()
{
    startButton.setPos(BUTTON_X, BUTTON_Y);
    creditsButton.setPos(BUTTON_X, BUTTON_Y+BUTTON_SPACING);
    exitButton.setPos(BUTTON_X, BUTTON_Y+BUTTON_SPACING*2);

    easyButton.setPos(-100, -100);
    mediumButton.setPos(100, -100);
    hardButton.setPos(100, -100);

    canDrawDifficulty = false;
}


void MainMenuState::free()
{
    audio->stopMusic();
    song.free();
    startButtonImage.free();
    creditsButtonImage.free();
    exitButtonImage.free();
    background.free();
    creditsState.free();
    easyButtonImage.free();
    mediumButtonImage.free();
    hardButtonImage.free();
}

void MainMenuState::update()
{
    startButton.update(input);
    creditsButton.update(input);
    exitButton.update(input);
    easyButton.update(input);
    mediumButton.update(input);
    hardButton.update(input);

    if(!audio->musicPlaying())
    {
        song.play(-1);
    }

    if(startButton.fired())
    {
        openDifficultyMenu();
    }

    if(creditsButton.fired())
    {
        if(!creditsState.init(input))
        {
            return;
        }

        getManager()->addState(&creditsState);
    }

    if(exitButton.fired())
    {
        game->end();
    }

     if(easyButton.fired())
    {
        if(!runState->init(input, audio, screenWidth, screenHeight))
        {
            runState->free();
            game->end();
        }

        runState->setDifficulty(1);
        getManager()->addState(runState);
        hideDifficultyMenu();
    }

     if(mediumButton.fired())
    {
        if(!runState->init(input, audio, screenWidth, screenHeight))
        {
            runState->free();
            game->end();
        }

        runState->setDifficulty(2);
        getManager()->addState(runState);
        hideDifficultyMenu();
    }

     if(hardButton.fired())
    {
        if(!runState->init(input, audio, screenWidth, screenHeight))
        {
            runState->free();
            game->end();
        }

        runState->setDifficulty(3);
        getManager()->addState(runState);
        hideDifficultyMenu();
    }
}

void MainMenuState::draw(Graphics* g)
{
    background.draw(0,0,g);
    startButton.draw(g);
    creditsButton.draw(g);
    exitButton.draw(g);
    easyButton.draw(g);
    mediumButton.draw(g);
    hardButton.draw(g);

    if(canDrawDifficulty) {
        difficultyImage.draw(BUTTON_X, BUTTON_Y, g);
    }
}
