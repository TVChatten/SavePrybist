#ifndef DIFFICULTYMENUSTATE_H
#define DIFFICULTYMENUSTATE_H

#include "Core/GameState.h"
#include "Core/Image.h"
#include "Core/Input.h"
#include "Button.h"

class DifficultyMenuState : public GameState
{
private:
    Image backgroundImage;
    Input* input;

    const static int BUTTON_X = 100;
    const static int BUTTON_Y = 400;
    const static int BUTTON_SPACING = 75;

    Button easyButton;
    Button mediumButton;
    Button hardButton;
    Image easyButtonImage;
    Image mediumButtonImage;
    Image hardButtonImage;
public:
    bool init(Input* i);
    void free();
    void update();
    void draw(Graphics* g);
};

#endif

