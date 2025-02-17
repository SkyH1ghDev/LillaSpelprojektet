#include "HealthVisible.hpp"

void HealthVisible::Visible(std::string& texture, float& layer, float& scale, DirectX::XMFLOAT2& position)
{
	layer = 0.5;
	scale = 0.09;
	position = { 30, 10 };
	
	srand(time(0));

	// Generate a random number between 0 and 100
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
