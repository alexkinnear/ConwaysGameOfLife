#include "Pattern.hpp"

class PatternBlinker : public Pattern
{
  public:
    std::uint8_t getSizeX() const override { return 1; };
    std::uint8_t getSizeY() const override { return 3; };
    bool getCell(std::uint8_t x, std::uint8_t y) const override { return pattern[x][y]; };

  private:
    std::vector<std::vector<bool>> pattern = {
        { true, true, true }
    };
};