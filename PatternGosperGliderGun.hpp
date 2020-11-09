#include "Pattern.hpp"

class PatternGosperGliderGun : public Pattern
{
  public:
    std::uint8_t getSizeX() const override
    {
        return 36;
    };
    std::uint8_t getSizeY() const override { return 9; };
    bool getCell(std::uint8_t x, std::uint8_t y) const override { return pattern[x][y]; };

  private:
    std::vector<std::vector<bool>> pattern = {
        { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false },
        { false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, false, true, false, false, false, false, false, false, false, false, false, false },
        { false, false, false, false, false, false, false, false, false, false, false, false, true, true, false, false, false, false, false, false, false, true, true, false, false, false, false, false, false, false, false, false, false, false, true, true },
        { false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, true, false, false, false, false, false, true, true, false, false, false, false, false, false, false, false, false, false, false, true, true },
        { true, true, false, false, false, false, false, false, false, false, true, false, false, false, false, false, true, false, false, false, false, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false },
        { true, true, false, false, false, false, false, false, false, false, true, false, false, false, false, false, true, true, false, false, false, false, false, true, false, true, false, false, false, false, false, false, false, false, false, false },
        { false, false, false, false, false, false, false, false, false, false, true, false, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, false },
        { false, false, false, false, false, false, false, false, false, false, false, true, false, false, false, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false },
        { false, false, false, false, false, false, false, false, false, false, false, false, true, true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false }
    };
};