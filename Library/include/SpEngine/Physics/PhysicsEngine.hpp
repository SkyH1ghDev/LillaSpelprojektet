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
	 * an entity and a pojectile. Or an entity and entity collision.
	 *
	 * @param[IN] projectile Collider
	 * @param[IN] entity Collider
	 * @param[OUT] bool
	 * @return true on Collision, false on NO collision
	 */

	static bool ColliderColliderCollision(std::shared_ptr<Collider> col1, std::shared_ptr<Collider> col2);

	/**
	 * Finds out if there is a collision between
	 * a projectile and a wall
	 *
	 * @param[IN] projectile Collider
	 * @param[OUT] bool
	 * @return true on Collision, false on NO collision
	 */
	static bool WallProjectileCollision(std::shared_ptr<Collider> projectile);

	/**
	 * Finds out if there is a collision between
	 * a projectile and a projectile
	 *
	 * @param[IN] projectile1 Collider
	 * @param[IN] projectile2 Collider
	 * @param[OUT] bool
	 * @return true on Collision, false on NO collision
	 */
	static bool ProjectileProjectileCollision(std::shared_ptr<Collider> col1, std::shared_ptr<Collider> col2);

private:
	static int m_leftWall;
	static int m_rightWall;
	static int m_topWall;
	static int m_bottomWall;
};