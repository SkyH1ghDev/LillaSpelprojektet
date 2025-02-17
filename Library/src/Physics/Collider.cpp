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

/**
 * Circle-Circle Collision Detection
 */
bool Collider::CheckCircleCollision(const Collider& other) const
{
	float dx = m_position.x - other.m_position.x;
	float dy = m_position.y - other.m_position.y;
	float distanceSquared = dx * dx + dy * dy;
	float radiusSum = m_radiusX + other.m_radiusX;

	return distanceSquared <= (radiusSum * radiusSum);
}

/**
 * AABB Collision Detection (for rectangular objects)
 */
bool Collider::CheckAABBCollision(const Collider& other) const
{
	float leftA = m_position.x - m_radiusX;
	float rightA = m_position.x + m_radiusX;
	float topA = m_position.y - m_radiusY;
	float bottomA = m_position.y + m_radiusY;

	float leftB = other.m_position.x - other.m_radiusX;
	float rightB = other.m_position.x + other.m_radiusX;
	float topB = other.m_position.y - other.m_radiusY;
	float bottomB = other.m_position.y + other.m_radiusY;

	return (leftA < rightB && rightA > leftB && topA < bottomB && bottomA > topB);
}

/**
 * General Collision Check based on collision type.
 */
bool Collider::CheckCollision(const Collider& other) const
{
	// First, check if the collision layers allow interaction.
	if (!CanCollideWith(other.GetLayer())) return false;

	// If both colliders are circles, use circle collision check.
	if (m_radiusX == m_radiusY && other.m_radiusX == other.m_radiusY)
		return CheckCircleCollision(other);

	// Otherwise, use AABB collision check.
	return CheckAABBCollision(other);
}
