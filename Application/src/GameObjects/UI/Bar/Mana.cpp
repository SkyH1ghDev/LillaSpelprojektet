#include "Mana.hpp"

Mana::Mana(ManaType type) :
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
	this->m_scaleFloat = 0.85;
	this->m_shouldRender = true;
	this->m_isActive = false;
	SetIsAlive(true);
	if(textureNameUpdate.empty())
		textureNameUpdate = "mana_0.png";
}

void Mana::UpdateMana(bool positive, size_t manaCrystalIndex)
{
	if (positive) {
		switch (manaCrystalIndex) {
		case 0:
			textureNameUpdate = "mana_1.png";
			break;
		case 1:
			textureNameUpdate = "mana_2.png";
			break;
		case 2:
			textureNameUpdate = "mana_3.png";
			break;
		case 3:
			textureNameUpdate = "mana_4.png";
			break;
		case 4:
			textureNameUpdate = "mana_5.png";
			break;
		case 5:
			textureNameUpdate = "mana_0.png";
			break;
		default:
			throw std::invalid_argument("invaild manaCrystalIndex");
		}
	}
	else {
		switch (manaCrystalIndex) {
		case 0:
			textureNameUpdate = "mana_0.png";
			break;
		case 1:
			textureNameUpdate = "mana_0.png";
			break;
		case 2:
			textureNameUpdate = "mana_1.png";
			break;
		case 3:
			textureNameUpdate = "mana_2.png";
			break;
		case 4:
			textureNameUpdate = "mana_3.png";
			break;
		case 5:
			textureNameUpdate = "mana_4.png";
			break;
		default:
			throw std::invalid_argument("invaild manaCrystalIndex");
		}
	}


}


void Mana::Reset()
{
	this->m_layerFloat = 0.7;
	this->m_scaleFloat = 0.85;
	this->m_shouldRender = true;
	this->m_isActive = false;
	SetIsAlive(true);
	if (textureNameUpdate.empty())
		textureNameUpdate = "mana_0.png";
}