#pragma once

//#include <d3d11.h>
#include <DirectXMath.h>
#include <Collider.hpp>

namespace DX = DirectX;

/**
* This class will probably undergo changes in the future.
* 
* The plan is to send the objects needing collision
* checks instead of just the raw data. That will make
* the class easier to use. The raw data is currently used
* right now because the right getters and stucture in
* the program does not exist yet.
* 
* -Puntis :)
*/

class PhysicsEngine
{
public:
	PhysicsEngine() = default;
	~PhysicsEngine() = default;

	/**
	 * Finds out if there is a collision between
	 * an entity and the outer most wall in the x-axis
	 *
	 * @param[IN] xPos float entityposition
	 * @param[IN] radius float entityradius
	 * @param[OUT] bool
	 * @return true on Collision, false on NO collision
	 */
	static bool WallEntityXCollision(const float xPos, const float radiusX = 10.0f);

	/**
	 * Finds out if there is a collision between
	 * an entity and the outer most wall in the y-axis
	 *
	 * @param[IN] yPos float entityposition
	 * @param[IN] radius float entityradius
	 * @param[OUT] bool
	 * @return true on Collision, false on NO collision
	 */
	static bool WallEntityYCollision(const float yPos, const float radiusY = 16.5f);

	static bool WallEntityXCollision(const Collider& entity);
	static bool WallEntityYCollision(const Collider& entity);

private:
	/**
	 * Finds out if there is a collision between
	 * a projectile and a projectile
	 *
	 * @param[IN] projPos1 XMFLOAT2 first projectileposition
	 * @param[IN] projPos2 XMFLOAT2 second projectileposition
	 * @param[IN] radius1 float first projectileradius
	 * @param[IN] radius2 float second projectileradius
	 * @param[OUT] bool
	 * @return true on Collision, false on NO collision
	 */
	bool ProjectileProjectileCollision(const DX::XMFLOAT2& projPos1, const DX::XMFLOAT2& projPos2, const float radius1, const float radius2);

	/**
	 * Finds out if there is a collision between
	 * a projectile and a projectile
	 *
	 * @param[IN] projPos XMFLOAT2 projectileposition
	 * @param[IN] radius float projectileradius
	 * @param[OUT] bool
	 * @return true on Collision, false on NO collision
	 */
	bool WallProjectileCollision(const DX::XMFLOAT2& projPos, const float radius = 1.0f);

	/**
	 * Finds out if there is a collision between
	 * a projectile and the outer most wall in the y-axis
	 *
	 * @param[IN] projPos1 XMFLOAT2 first projectileposition
	 * @param[IN] projPos2 XMFLOAT2 second projectileposition
	 * @param[IN] radiusX1 float "oval width"
	 * @param[IN] radiusY1 float "oval height"
	 * @param[IN] radiusX2 float "oval width"
	 * @param[IN] radiusY2 float "oval height"
	 * @param[OUT] bool
	 * @return true on Collision, false on NO collision
	 */
	bool EntityEntityCollision(const DX::XMFLOAT2& projPos1, const DX::XMFLOAT2& projPos2, const float radiusX1, const float radiusY1, const float radiusX2, const float radiusY2);

private:
	static int m_leftWall;
	static int m_rightWall;
	static int m_topWall;
	static int m_bottomWall;
};