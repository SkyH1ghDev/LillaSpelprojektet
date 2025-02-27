#include "Heart.hpp"

void Heart::Update()
{

}

void Heart::OnStart()
{
	PerformVisible();
	SetIsAlive(true);
	this->m_isActive = false;
	this->m_shouldRender = true;
	this->m_scaleFloat = 1.0;
	this->m_layerFloat = 0.8;
	this->m_textureName = "heart.png";
}

void Heart::UpdateHeart(bool heart)
{
	if (heart)
		this->m_textureName = "heart.png";
	else
		this->m_textureName = "heart0.png";
}

void Heart::Reset()
{
	PerformVisible();
	SetIsAlive(true);
	this->m_isActive = false;
}