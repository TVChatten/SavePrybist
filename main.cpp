#include "PrybistGame.h"

int main(int argc, char *argv[])
{
    PrybistGame game;

    if(!game.init())
    {
        game.free();
        return 0;
    }

    game.run();

    return 0;
}
