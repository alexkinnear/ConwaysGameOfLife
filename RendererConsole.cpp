#include "RendererConsole.hpp"

#include "rlutil.h"

void RendererConsole::render(const LifeSimulator& simulation)
{
    rlutil::cls();
    rlutil::hidecursor();
    for (uint8_t i = 0; i < simulation.getSizeX(); i++)
    {
        for (uint8_t j = 0; j < simulation.getSizeY(); j++)
        {
            if (simulation.getCell(i, j))
            {
                rlutil::locate(j, i);
                rlutil::setChar('*');
            }
        }
    }
    //    rlutil::showcursor();
    std::cout << std::flush;
}
