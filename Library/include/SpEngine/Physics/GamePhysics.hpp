#pragma once

//#include <d3d11.h>
#include <DirectXMath.h>

namespace DX = DirectX;

class GamePhysics
{
public:
	GamePhysics() = default;
	~GamePhysics() = default;

	DX::XMFLOAT2 WallEntityCollision(const DX::XMFLOAT2& position);

private:
	int m_leftWall = 20;
	int m_rightWall = 560;
	int m_topWall = -10;
	int m_bottomWall = 260;
};