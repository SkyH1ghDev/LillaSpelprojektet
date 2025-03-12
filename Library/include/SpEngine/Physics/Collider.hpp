#pragma once

#include <memory>
#include <DirectXMath.h>

namespace DX = DirectX;

/**
 * Collision layers define object types for filtering.
 */
enum class CollisionLayer {
	None = 0,
	Player = 1 << 0,  // 000001 (1)
	Enemy = 1 << 1,   // 000010 (2)
	AllyProjectile = 1 << 2, // 000100 (4)
	EnemyProjectile = 1 << 3,    // 001000 (8)
	DisruptorWave = 1 << 4, // 010000
	PickUps = 1 << 5, // 100000
	Blade = 1 << 6, //1000000
	All = ~0          // 1111111 (all bits set)
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
	 * Getters for collider properties.
	 */
	DX::XMFLOAT2 GetPosition() const;
	float GetRadius() const;
	float GetRadiusX() const;
	float GetRadiusY() const;
	CollisionLayer GetLayer() const;
	CollisionLayer GetMask() const;
	bool CanCollideWith(CollisionLayer otherLayer) const;

	/**
	 * Setters for collider properties. (Only necessary)
	 */
	void SetRadius(float newRadius, float aspectRatio = 1.0f);

private:
	DX::XMFLOAT2 m_position;
	float m_radiusX;
	float m_radiusY;
	CollisionLayer m_layer;
	CollisionLayer m_mask;
};
