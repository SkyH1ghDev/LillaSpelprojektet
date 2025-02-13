#pragma once

#include <DirectXMath.h>

namespace DX = DirectX;

/**
* A Collider need to retrieve information like
* -Position both x and y
* -Radius
* -ARM both x and y (aspectRatioModifier)
*/

class Collider
{
public:
	Collider() = default;
	~Collider() = default;

	DX::XMFLOAT2 GetPosition();
	
	//bool WallEntityXCollision(const float xPos, const float radius = 10.0f, const float ARM = 1.0f);
	//bool WallEntityYCollision(const float yPos, const float radius = 10.0f, const float ARM = 1.65f);
	//bool ProjectileProjectileCollision(const DX::XMFLOAT2& projPos1, const DX::XMFLOAT2& projPos2, const float radius1, const float radius2);
	//bool WallProjectileXCollision(const float xPos, const float radius = 1.0f, const float ARM = 1.0f);
	// WallProjectileYCollision(const float yPos, const float radius = 1.0f, const float ARM = 1.0f);
	//bool EntityEntityCollision(const DX::XMFLOAT2& projPos1, const DX::XMFLOAT2& projPos2, const float radiusX1, const float radiusY1, const float radiusX2, const float radiusY2);

private:
};