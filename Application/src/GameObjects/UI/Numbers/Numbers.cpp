#include "Numbers.hpp"
#include "EnemyManager.hpp"

Numbers::Numbers(NumberPos numberPos)
{
	this->m_pos = numberPos;
}

void Numbers::Update()
{
	int roundNum = EnemyManager::GetRoundCount();
	int firstDigit = roundNum / 10;  // Extract first digit
	int secondDigit = roundNum % 10; // Extract second digit

	if (this->m_pos == NumberPos::First)
	{
		this->m_animationTime = firstDigit / 24.0f; // Use first digit
	}
	else if (this->m_pos == NumberPos::Second)
	{
		this->m_animationTime = secondDigit / 24.0f; // Use second digit
	}
	
}

void Numbers::OnStart()
{
	SetIsAlive(true);
	this->m_isActive = false;
	this->m_shouldRender = true;
	this->m_scaleFloat = 1.0;
	this->m_layerFloat = 0.8;
	this->m_textureName = "numbers";
}

void Numbers::Reset()
{
	SetIsAlive(true);
	this->m_isActive = false;
}