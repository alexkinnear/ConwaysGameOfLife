#include "Pattern.hpp"

class PatternBlock : public Pattern
{
  public:
    std::uint8_t getSizeX() const override { return 2; };
    std::uint8_t getSizeY() const override { return 2; };
    bool getCell(std::uint8_t x, std::uint8_t y) const override { return true; };
};