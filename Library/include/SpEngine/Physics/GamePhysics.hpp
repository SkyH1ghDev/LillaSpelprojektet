#pragma once

#include <DirectXMath.h>
#include <SpEngine/Physics/Collider.hpp>

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
	 * @param[IN] entity Collider
	 * @param[OUT] bool
	 * @return true on Collision, false on NO collision
	 */
	static bool WallEntityXCollision(std::shared_ptr<Collider> entity);

	/**
	 * Finds out if there is a collision between
	 * an entity and the outer most wall in the y-axis
	 *
	 * @param[IN] entity Collider
	 * @param[OUT] bool
	 * @return true on Collision, false on NO collision
	 */
	static bool WallEntityYCollision(std::shared_ptr<Collider> entity);

	/**
	 * Finds out if there is a collision between
	 * an entity and a pojectile
	 *
	 * @param[IN] projectile Collider
	 * @param[IN] entity Collider
	 * @param[OUT] bool
	 * @return true on Collision, false on NO collision
	 */
	static bool ProjectileEntityCollision(std::shared_ptr<Collider> projectile, std::shared_ptr<Collider> entity);

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
	bool EntityEntityCollision(const Collider& projectile, const Collider& entity);

private:
	static int m_leftWall;
	static int m_rightWall;
	static int m_topWall;
	static int m_bottomWall;
};