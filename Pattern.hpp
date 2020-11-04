#pragma once
#include <cstdint>
#include <iostream>
#include <vector>

class Pattern
{
  public:
    virtual std::uint8_t getSizeX() const = 0;
    virtual std::uint8_t getSizeY() const = 0;
    virtual bool getCell(std::uint8_t x, std::uint8_t y) const = 0;
};