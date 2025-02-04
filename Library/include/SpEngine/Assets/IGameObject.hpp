#pragma once

#include <DirectXMath.h>
#include <iostream>
#include <SpEngine/Input/Input.hpp>

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
    DX::XMFLOAT2 GetPosition() const;
    std::string GetTextureString() const;
    bool ToRender() const;
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
    DX::XMFLOAT2 m_position = { 0, 0 };
    bool m_isActive = true;
    std::string m_texture;
    bool m_toRender = false;
};

inline bool IGameObject::IsActive() const
{
	return m_isActive;
}

inline void IGameObject::SetActive(bool activeState)
{
	m_isActive = activeState;
}

inline DX::XMFLOAT2 IGameObject::GetPosition() const
{
    return m_position;
}
inline std::string IGameObject::GetTextureString() const
{
    return m_texture;
}
inline bool IGameObject::ToRender() const
{
    return m_toRender;
}