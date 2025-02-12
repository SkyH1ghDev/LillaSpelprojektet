#include "ObjectVisible.hpp"

void ObjectVisible::Visible(std::string& texture, DX::XMFLOAT2 position, float& layer, float& scale)
{
	scale = 0.1;
	layer = 0.5 + position.y * 0.3 / 360;
}