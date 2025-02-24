#include "Heart.hpp"

#include "HeartFullVisible.hpp"
#include "HeartEmptyVisible.hpp"	


std::shared_ptr<IUIVisible> CreateVisibleComponent(HeartType type) {
	switch (type) {
	case HeartType::Full:
		return std::make_shared<HeartFullVisible>();
	case HeartType::Empty:
		return std::make_shared<HeartEmptyVisible>();
	default:
		throw std::invalid_argument("Invalid HeartType");
	}
}

Heart::Heart(HeartType type) :
	m_visible(CreateVisibleComponent(type)),
	m_type(type)
{

}

void Heart::Update()
{
	if (heart_empty)
		this->m_shouldRender = true;
	else
		this->m_shouldRender = false;
}

void Heart::OnStart()
{
	PerformVisible();
	SetIsAlive(true);
	this->m_isActive = true;
}

void Heart::UpdateHeart(bool positive)
{
	if (positive) {
		//refill a heart
		this->heart_empty = true;
	}
	else {
		//Removes a heart
		this->heart_empty = false;
	}
}
