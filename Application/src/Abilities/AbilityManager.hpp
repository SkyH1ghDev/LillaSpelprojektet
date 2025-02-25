#include <DirectXMath.h>

namespace DX = DirectX;

class AbilityManager
{
public:
	static void Shotgun(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, size_t projectileCount, float lifeSpan, float shotSpeed, float spreadAngle);
	static void SurroundShot(DX::XMFLOAT2 position, size_t projectileCount, float lifeSpan, float shotSpeed);
	static void SniperShot(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float shotSpeed, float damageMultiplier);

private:
};