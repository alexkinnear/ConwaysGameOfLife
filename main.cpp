#include "LifeSimulator.hpp"
#include "PatternAcorn.hpp"
#include "PatternBlinker.hpp"
#include "PatternGlider.hpp"
#include "PatternGosperGliderGun.hpp"
#include "RendererConsole.hpp"
#include "rlutil.h"

int main()
{
    PatternAcorn acorn;
    PatternBlinker blinker;
    PatternGlider glider;
    PatternGosperGliderGun gosperGliderGun;
    LifeSimulator game(rlutil::trows(), rlutil::tcols());
    RendererConsole r;
    game.insertPattern(acorn, 10, 10);
    game.insertPattern(blinker, 45, 5);
    game.insertPattern(glider, 25, 5);
    game.insertPattern(gosperGliderGun, 20, 25);

    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        r.render(game);
        game.update();
    }
    rlutil::showcursor();
}