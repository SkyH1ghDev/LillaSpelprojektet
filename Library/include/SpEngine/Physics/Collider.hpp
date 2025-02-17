#pragma once

#include <DirectXMath.h>

namespace DX = DirectX;

/**
* A Collider need to retrieve information like
* -Position both x and y
* -Radius
*/

class Collider
{
public:
	/**
	* Constructor for a circle.
	* @param[IN] position XMFLOAT2
	* @param[IN] radius float
	*/
	Collider(DX::XMFLOAT2 position, float radius);

	/**
	* Constructor for an oval.
	* @param[IN] position XMFLOAT2
	* @param[IN] radius float
	* @param[IN] aspectRatio float (modifier for aspect ratio)
	*/
	Collider(DX::XMFLOAT2 position, float radius, float aspectRatio);

	/**
	* Updates position for a collider. (Should be called every frame)
	* @param[IN] position XMFLOAT2
	*/
	void updatePosition(DX::XMFLOAT2 position);

	DX::XMFLOAT2 GetPosition() const;
	float GetRadius() const;
	float GetRadiusX() const;
	float GetRadiusY() const;
	
	//bool WallEntityXCollision(const float xPos, const float radius = 10.0f);
	//bool WallEntityYCollision(const float yPos, const float radius = 16.5f);
	//bool ProjectileProjectileCollision(const DX::XMFLOAT2& projPos1, const DX::XMFLOAT2& projPos2, const float radius1, const float radius2);
	//bool WallProjectileCollision(const DX::XMFLOAT2 projPos, const float radius = 1.0f);
	//bool EntityEntityCollision(const DX::XMFLOAT2& projPos1, const DX::XMFLOAT2& projPos2, const float radiusX1, const float radiusY1, const float radiusX2, const float radiusY2);

private:
	DX::XMFLOAT2 m_position;
	float m_radiusX;
	float m_radiusY;
};