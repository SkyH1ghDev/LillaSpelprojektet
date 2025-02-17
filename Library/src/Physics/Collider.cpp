#include <istream>
#include "Collider.hpp"

Collider::Collider(DX::XMFLOAT2 position, float radius)
{
	this->m_position = position;
	this->m_radiusX = radius;
	this->m_radiusY = radius;
}

Collider::Collider(DX::XMFLOAT2 position, float radius, float aspectRatio)
{
	this->m_position = position;
	this->m_radiusX = radius;
	this->m_radiusY = radius * aspectRatio;
}

void Collider::updatePosition(DX::XMFLOAT2 position)
{
	this->m_position = position;
}

DX::XMFLOAT2 Collider::GetPosition() const
{
	return this->m_position;
}

float Collider::GetRadius() const
{
	return this->m_radiusX;
}

float Collider::GetRadiusX() const
{
	return this->m_radiusX;
}

float Collider::GetRadiusY() const
{
	return this->m_radiusY;
}
