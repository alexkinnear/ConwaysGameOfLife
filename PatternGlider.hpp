#include "Pattern.hpp"

class PatternGlider : public Pattern
{
  public:
    std::uint8_t getSizeX() const override { return 3; };
    std::uint8_t getSizeY() const override { return 3; };
    bool getCell(std::uint8_t x, std::uint8_t y) const override { return pattern[x][y]; };

  private:
    std::vector<std::vector<bool>> pattern = {
        { false, true, false },
        { false, false, true },
        { true, true, true }
    };
};