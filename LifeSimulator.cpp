#include "LifeSimulator.hpp"

LifeSimulator::LifeSimulator(std::uint8_t sizeX, std::uint8_t sizeY)
{
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    for (int i = 0; i < sizeX; i++)
    {
        grid.emplace_back();
        grid2.emplace_back();
        for (int j = 0; j < this->sizeY; j++)
        {
            grid[i].push_back(false);
            grid2[i].push_back(false);
        }
    }
}

std::uint8_t LifeSimulator::getSizeX() const
{
    return this->sizeX;
}

std::uint8_t LifeSimulator::getSizeY() const
{
    return this->sizeY;
}

bool LifeSimulator::getCell(std::uint8_t x, std::uint8_t y) const
{
    if (x < this->getSizeX() && y < this->getSizeY())
    {
        return grid[x][y];
    }
    else
    {
        return false;
    }
}

void LifeSimulator::insertPattern(const Pattern& pattern, std::uint8_t startX, std::uint8_t startY)
{
    for (uint8_t i = 0; i < pattern.getSizeY(); i++)
    {
        for (uint8_t j = 0; j < pattern.getSizeX(); j++)
        {
            grid[startY + i][startX + j] = pattern.getCell(i, j);
        }
    }
}

void LifeSimulator::update()
{
    for (uint8_t i = 0; i < this->getSizeX(); i++)
    {
        for (uint8_t j = 0; j < this->getSizeY(); j++)
        {
            int neighbors = 0;
            if (i != 0)
            {
                if (grid[i - 1][j])
                {
                    neighbors++;
                }
            }
            if (i != getSizeX() - 1)
            {
                if (grid[i + 1][j])
                {
                    neighbors++;
                }
            }
            if (i != 0 && j != 0)
            {
                if (grid[i - 1][j - 1])
                {
                    neighbors++;
                }
            }
            if (i != 0 && j != getSizeY() - 1)
            {
                if (grid[i - 1][j + 1])
                {
                    neighbors++;
                }
            }
            if (i != getSizeX() - 1 && j != 0)
            {
                if (grid[i + 1][j - 1])
                {
                    neighbors++;
                }
            }
            if (i != getSizeX() - 1 && j != getSizeY() - 1)
            {
                if (grid[i + 1][j + 1])
                {
                    neighbors++;
                }
            }
            if (j != getSizeY() - 1)
            {
                if (grid[i][j + 1])
                {
                    neighbors++;
                }
            }
            if (j != 0)
            {
                if (grid[i][j - 1])
                {
                    neighbors++;
                }
            }
            if (neighbors < 2 && grid[i][j])
            {
                grid2[i][j] = false;
            }
            else if ((neighbors == 2 || neighbors == 3) && grid[i][j])
            {
                grid2[i][j] = true;
            }
            else if (neighbors > 3 && grid[i][j])
            {
                grid2[i][j] = false;
            }
            else if (!grid[i][j] && neighbors == 3)
            {
                grid2[i][j] = true;
            }
        }
    }
    grid = grid2;
}