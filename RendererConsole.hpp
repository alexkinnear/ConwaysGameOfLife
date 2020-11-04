#include "Renderer.hpp"

class RendererConsole : Renderer
{
  public:
    void render(const LifeSimulator& simulation) override;
};