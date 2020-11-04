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
    game.insertPattern(acorn, 20, 5);
    game.insertPattern(blinker, 15, 10);
    game.insertPattern(glider, 30, 15);
    game.insertPattern(gosperGliderGun, 30, 15);
    //    game.insertPattern(acorn, 0, 0);
    //    game.insertPattern(blinker, 0, 0);
    //    game.insertPattern(glider, 0, 0);
    //    game.insertPattern(gosperGliderGun, 0, 0);
    for (int i = 0; i < 100; i++)
    {
        r.render(game);
        game.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}