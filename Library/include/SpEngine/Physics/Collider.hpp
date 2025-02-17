#pragma once

#include <memory>
#include <DirectXMath.h>

namespace DX = DirectX;

/**
 * Collision layers define object types for filtering.
 */
enum class CollisionLayer {
	None = 0,
	Player = 1 << 0,
	Enemy = 1 << 1,
	Projectile = 1 << 2,
	Wall = 1 << 3,
	All = ~0
};

class Collider
{
public:
	/**
	 * Constructor for a circular collider.
	 * @param position Collider center position.
	 * @param radius Collider radius.
	 */
	Collider(DX::XMFLOAT2 position, float radius, CollisionLayer layer, CollisionLayer mask);

	/**
	 * Constructor for an oval collider.
	 * @param position Collider center position.
	 * @param radius Base radius.
	 * @param aspectRatio Scale factor for Y-axis.
	 */
	Collider(DX::XMFLOAT2 position, float radius, float aspectRatio, CollisionLayer layer, CollisionLayer mask);

	/**
	 * Updates the collider's position.
	 */
	void UpdatePosition(DX::XMFLOAT2 position);

	/**
	 * Collision detection functions.
	 */
	bool CheckCollision(const Collider& other) const;
	bool CheckCircleCollision(const Collider& other) const;
	bool CheckAABBCollision(const Collider& other) const;

	/**
	 * Getters for collider properties.
	 */
	DX::XMFLOAT2 GetPosition() const;
	float GetRadius() const;
	float GetRadiusX() const;
	float GetRadiusY() const;
	CollisionLayer GetLayer() const;
	CollisionLayer GetMask() const;
	bool CanCollideWith(CollisionLayer otherLayer) const;

private:
	DX::XMFLOAT2 m_position;
	float m_radiusX;
	float m_radiusY;
	CollisionLayer m_layer;
	CollisionLayer m_mask;
};
