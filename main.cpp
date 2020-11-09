#include "LifeSimulator.hpp"
#include "PatternAcorn.hpp"
#include "PatternBlinker.hpp"
#include "PatternBlock.hpp"
#include "PatternGlider.hpp"
#include "PatternGosperGliderGun.hpp"
#include "RendererConsole.hpp"
#include "rlutil.h"

int main()
{
    PatternAcorn acorn;
    PatternBlinker blinker;
    PatternBlock block;
    PatternGlider glider;
    PatternGosperGliderGun gosperGliderGun;
    LifeSimulator game(rlutil::trows(), rlutil::tcols());
    RendererConsole r;
    game.insertPattern(acorn, 45, 45);
    game.insertPattern(blinker, 5, 35);
    game.insertPattern(block, 15, 35);
    game.insertPattern(glider, 45, 5);
    game.insertPattern(gosperGliderGun, 2, 2);

    for (int i = 0; i < 100; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        r.render(game);
        game.update();
    }
    rlutil::showcursor();
}