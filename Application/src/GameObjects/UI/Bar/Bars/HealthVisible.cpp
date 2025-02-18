#include "HealthVisible.hpp"

void HealthVisible::Visible(std::string& texture, float& layer, float& scale, DirectX::XMFLOAT2& position)
{
	layer = 0.6;
	scale = 0.09;
	
	int hp = 0;

	switch (hp) {
	case 0: 
		texture = "heart0.png";
		break;
	case 1:
		texture = "heart.png";
		break;
	default:
		texture = "heart.png";
		break;
	}

}
