#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "Core/Game.h"
#include "Core/GameState.h"
#include "Core/Graphics.h"
#include "Core/Image.h"
#include "Core/Input.h"
#include "Core/Music.h"

#include "Button.h"
#include "RunState.h"
#include "CreditsState.h"

class MainMenuState : public GameState
{
private:
    const static int BUTTON_X = 100;
    const static int BUTTON_Y = 400;
    const static int BUTTON_SPACING = 75;

    bool canDrawDifficulty = false;
    int screenWidth;
    int screenHeight;

    Button startButton;
    Button creditsButton;
    Button exitButton;
    Button easyButton;
    Button mediumButton;
    Button hardButton;
    Game* game;
    Image background;
    Image startButtonImage;
    Image creditsButtonImage;
    Image exitButtonImage;
    Image easyButtonImage;
    Image mediumButtonImage;
    Image hardButtonImage;
    Image difficultyImage;
    Music song;
    Audio* audio;
    Input* input;
    RunState* runState;
    CreditsState creditsState;
public:
    bool init(Input* i, Audio* a, Game* g, RunState* r);
    void free();
    void update();
    void draw(Graphics* g);
    void openDifficultyMenu();
    void hideDifficultyMenu();
};

#endif
