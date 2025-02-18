#include "Collider.hpp"
#include <cmath>

Collider::Collider(DX::XMFLOAT2 position, float radius, CollisionLayer layer, CollisionLayer mask)
	: m_position(position), m_radiusX(radius), m_radiusY(radius), m_layer(layer), m_mask(mask) {
}

Collider::Collider(DX::XMFLOAT2 position, float radius, float aspectRatio, CollisionLayer layer, CollisionLayer mask)
	: m_position(position), m_radiusX(radius), m_radiusY(radius* aspectRatio), m_layer(layer), m_mask(mask) {
}

void Collider::UpdatePosition(DX::XMFLOAT2 position)
{
	this->m_position = position;
}

DX::XMFLOAT2 Collider::GetPosition() const { return m_position; }
float Collider::GetRadius() const { return m_radiusX; }
float Collider::GetRadiusX() const { return m_radiusX; }
float Collider::GetRadiusY() const { return m_radiusY; }
CollisionLayer Collider::GetLayer() const { return m_layer; }
CollisionLayer Collider::GetMask() const { return m_mask; }

bool Collider::CanCollideWith(CollisionLayer otherLayer) const
{
	return static_cast<int>(m_mask) & static_cast<int>(otherLayer);
}

