#include <DirectXMath.h>

namespace DX = DirectX;
class PlayerInfo {
public:
    // Set player's position
    static void SetPosition(DX::XMFLOAT2 playerPos);

    // Get player's position
    static DX::XMFLOAT2 GetPosition();

private:
    // Private static variables to store position
    static DX::XMFLOAT2 m_playerPos;
};

inline void PlayerInfo::SetPosition(DX::XMFLOAT2 playerPos)
{
    PlayerInfo::m_playerPos = playerPos;
}

inline DX::XMFLOAT2 PlayerInfo::GetPosition()
{
    return PlayerInfo::m_playerPos;
}
