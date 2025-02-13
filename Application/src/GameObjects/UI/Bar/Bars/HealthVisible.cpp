#include "HealthVisible.hpp"

void HealthVisible::Visible(std::string& texture, float& layer, float& scale, DirectX::XMFLOAT2& position)
{
	layer = 0.5;
	scale = 0.09;
	position = { 500, 10 };
	
	srand(time(0));

	// Generate a random number between 0 and 100
	int hp = rand() % 6;

	switch (hp) {
	case 0: 
		texture = "heart0.png";
		break;
	case 1:
		texture = "heart1.png";
		break;
	case 2:
		texture = "heart2.png";
		break;
	case 3:
		texture = "heart3.png";
		break;
	case 4: 
		texture = "heart4.png";
		break;
	case 5:
		texture = "heart5.png";
		break;
	default:
		texture = "heart.png";
		break;
	}

}
