#include "TitleVisible.hpp"

void TitleVisible::Visible(std::string& texture, DX::XMFLOAT2 position, float& layer, float& scale)
{
	scale = 1.0;
	layer = 0.8;
}

void TitleVisible::UpdateLayer(DX::XMFLOAT2& position, float& layer) {}