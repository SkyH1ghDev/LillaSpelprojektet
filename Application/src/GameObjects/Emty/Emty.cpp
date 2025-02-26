#include "Emty.hpp"

void Emty::OnStart()
{
	this->m_isAlive = true;
}

void Emty::Update()
{

}

void Emty::Reset()
{
	this->m_isAlive = true;
	this->m_isActive = false;
}
