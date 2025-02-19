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
}

void Mana::OnStart()
{
	PerformVisible();
	this->m_shouldRender = true;
}

void Mana::UpdateMana(bool positive)
{

}
