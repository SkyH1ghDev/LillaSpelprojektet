#include "MouseVisible.hpp"
#include <SpEngine/Input/Input.hpp>

void MouseVisible::Visible(std::string& texture, DX::XMFLOAT2 position, float& layer, float& scale)
{
	layer = 1.0;
	scale = 0.3;
	
}

void MouseVisible::UpdateLayer(DX::XMFLOAT2& position, float& layer) {
	position.x = Input::GetMousePositionX();
	position.y = Input::GetMousePositionY();
}