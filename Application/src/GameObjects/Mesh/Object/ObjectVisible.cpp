#include "ObjectVisible.hpp"

void ObjectVisible::Visible(std::string& texture, DX::XMFLOAT2 position, float& layer, float& scale)
{
	scale = 1.0;
	layer = 0.5 + position.y * 0.3 / 360;
}

void ObjectVisible::UpdateLayer(DX::XMFLOAT2& position, float& layer)
{
	layer = 0.5 + position.y * 0.3 / 360;
}