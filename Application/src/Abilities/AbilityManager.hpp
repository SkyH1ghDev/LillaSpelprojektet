#include <DirectXMath.h>

namespace DX = DirectX;

class AbilityManager
{
public:
	static void Shotgun(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, size_t projectileCount, float lifeSpan, float shotSpeed, float spreadAngle);

private:
};