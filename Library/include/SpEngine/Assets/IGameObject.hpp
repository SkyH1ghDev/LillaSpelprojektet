#pragma once

#include <d3d11.h>
#include <DirectXMath.h>

namespace DX = DirectX;
class IGameObject
{

public:

    IGameObject() = default;
    virtual ~IGameObject() {}
    IGameObject(const IGameObject& other) = default;
    IGameObject& operator=(const IGameObject& other) = default;
    IGameObject(IGameObject&& other) noexcept = default;
    IGameObject& operator=(IGameObject&& other) noexcept = default;
    DX::XMFLOAT2 GetPosition();

    /**
     * Function that gets called every frame
     */
    virtual void Update() = 0;

    /**
     * Function that gets called when the game starts
     */
    virtual void OnStart() = 0;

    /**
     * Returns the active state of the game object
     *
     * @return True if yes, False if not
     */
    bool IsActive() const;

    /**
     * Sets the active state of the game object
     *
     * @param activeState The state to set the object to
     */
    void SetActive(bool activeState);


protected:
    DX::XMFLOAT2 m_position;
    bool m_isActive = true;

};

inline bool IGameObject::IsActive() const
{
	return m_isActive;
}

inline void IGameObject::SetActive(bool activeState)
{
	m_isActive = activeState;
}

inline DX::XMFLOAT2 IGameObject::GetPosition()
{
    return m_position;
}