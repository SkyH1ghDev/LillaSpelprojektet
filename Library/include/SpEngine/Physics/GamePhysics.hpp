#pragma once

//#include <d3d11.h>
#include <DirectXMath.h>

namespace DX = DirectX;

class GamePhysics
{
public:
	GamePhysics() = default;
	~GamePhysics() = default;

	bool WallEntityCollision(const DX::XMFLOAT2& position);
	bool ProjectileProjectileCollision(const DX::XMFLOAT2& projPos1, const DX::XMFLOAT2& projPos2, const float radius1, const float radius2);

private:
	int m_leftWall = 20;
	int m_rightWall = 560;
	int m_topWall = -10;
	int m_bottomWall = 260;
};