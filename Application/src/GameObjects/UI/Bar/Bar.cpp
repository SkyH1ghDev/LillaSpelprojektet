#include "Bar.hpp"

#include "HealthVisible.hpp"
#include "ManaVisible.hpp"	


std::shared_ptr<IUIVisible> CreateVisibleComponent(BarType type) {
	switch (type) {
	case BarType::Health:
		return std::make_shared<HealthVisible>();
	case BarType::Mana:
		return std::make_shared<ManaVisible>();
	default:
		throw std::invalid_argument("Invalid BarType");
	}
}

Bar::Bar(BarType type) :   
	m_visible(CreateVisibleComponent(type)),
	m_type(type)
{
	std::cout << "Bar created" << std::endl;
}

void Bar::Update()
{
}

void Bar::OnStart()
{
	PerformVisible();
	this->m_shouldRender = true;
   
}
