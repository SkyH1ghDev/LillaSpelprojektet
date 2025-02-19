#include "Mana.hpp"

#include "ManaReadyVisible.hpp"

std::shared_ptr<IUIVisible> CreateVisibleComponent(ManaType type) {
	switch (type) {
	case ManaType::Ready:
		return std::make_shared<ManaReadyVisible>();
	default:
		throw std::invalid_argument("invalid hearttype");
	}
}

Mana::Mana(ManaType type) :
m_visible(CreateVisibleComponent(type)),
m_type(type)
{
	std::cout << "Mana created" << std::endl;
}

void Mana::Update()
{
	this->m_textureName = textureNameUpdate;
}

void Mana::OnStart()
{
	this->m_layerFloat = 0.7;
	this->m_scaleFloat = 0.06;
	this->m_shouldRender = true;
	if(textureNameUpdate.empty())
		textureNameUpdate = "mana0.png";
}

void Mana::UpdateMana(bool positive, size_t manaCrystalIndex)
{
	if (positive) {
		switch (manaCrystalIndex) {
		case 0:
			textureNameUpdate = "mana1.png";
			break;
		case 1:
			textureNameUpdate = "mana2.png";
			break;
		case 2:
			textureNameUpdate = "mana3.png";
			break;
		case 3:
			textureNameUpdate = "mana4.png";
			break;
		case 4:
			textureNameUpdate = "mana5.png";
			break;
		case 5:
			textureNameUpdate = "mana0.png";
			break;
		default:
			throw std::invalid_argument("invaild manaCrystalIndex");
		}
	}
	else {
		textureNameUpdate = "mana0.png";
	}


}
