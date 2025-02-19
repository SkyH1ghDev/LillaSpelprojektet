#include "BackgroundVisible.hpp"

void BackgroundVisible::Visible(std::string& texture, DX::XMFLOAT2 position, float& layer, float& scale)
{
	scale = 1.0;
	layer = 0.0;

}

void BackgroundVisible::UpdateLayer(DX::XMFLOAT2& position, float& layer) {}