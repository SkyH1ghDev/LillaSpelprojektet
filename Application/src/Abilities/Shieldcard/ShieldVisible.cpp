#include "ShieldVisible.hpp"

void ShieldVisible::Visible(std::string& texture, CardState cardState, float& layer, float& scale)
{
    scale = 1.0;
    layer = 0.6;
    texture = "Shield.png";
    std::cerr << "visa kort effekt" << std::endl;
}
