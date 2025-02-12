#pragma once

#include <SpEngine/Assets/IScript.hpp>

#include <DirectXMath.h>
#include <memory>
#include <string>
#include <vector>
#include <SpEngine/Input/Input.hpp>

namespace DX = DirectX;

class IScript;

class IGameObject : public std::enable_shared_from_this<IGameObject>
{

public:

    IGameObject() = default;
    virtual ~IGameObject() {}
    IGameObject(const IGameObject& other) = default;
    IGameObject& operator=(const IGameObject& other) = default;
    IGameObject(IGameObject&& other) noexcept = default;
    IGameObject& operator=(IGameObject&& other) noexcept = default;



    /**
     * Function that gets called every frame
     */
    virtual void Update() = 0;

    /**
     * Function that gets called when the game starts
     */
    virtual void OnStart() = 0;

    void AttachScript(const std::shared_ptr<IScript>& script);

    void DetachScript(const std::shared_ptr<IScript>& script);

    void UpdateScripts() const;

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

    /**
     * Gets position of the GameObject
     *
     * @return Position
     */
    DX::XMFLOAT2 GetPosition() const;

    /**
     * Gets the identifier for the texture of the GameObject
     *
     * @return Texture ID / Name
     */
    std::string GetTextureString() const;

    /**
     * Gets the layer float value for the game object
     *
     * @return a float between 0 and 1
     */
    float GetLayerFloat() const;

    /**
    * Gets the scale float value for the game object
    *
    * @return a float between 0 and 1
    */
    float GetScaleFloat() const;

    /**
    * Gets the rotation float value for the game object
    *
    * @return a float value
    */
    float GetRotationFloat() const;

    /**
    * Gets the origin offset value for the game object
    *
    * @return a XMFLOAT2 value
    */
    DX::XMFLOAT2 GetOriginOffset() const;

    /**
     * Returns whether the sprite of the object is centered or not
     *
     * @return True if yes, False if no
     */
    bool IsOriginCentered() const;

    /**
     * Returns whether the GameObject should be rendered
     *
     * @return True if yes, False if no
     */
    bool ShouldRender() const;

    /**
     * Sets object position.
     *
     *
     */
    void SetPosition(DX::XMFLOAT2 position);

    /**
     * Sets object rotation.
     *
     *
     */
    void SetRotation(float rotation);

    /**
     * Sets object origin, false if top left = (0,0), true if centered.
     *
     *
     */
    void CenterOrigin(bool centerOrigin);

protected:
    std::string m_textureName;
    DX::XMFLOAT2 m_position = { 0, 0 };
    float m_layerFloat = 0.0;
    float m_scaleFloat = 1.0;
    float m_rotationFloat = 0.0;
    DX::XMFLOAT2 m_origonOffset = { 0, 0 };

    bool m_centerOrigin = false;
    bool m_isActive = true;
    bool m_shouldRender = false;

    std::vector<std::shared_ptr<IScript>> m_scripts;
};

inline void IGameObject::AttachScript(const std::shared_ptr<IScript>& script)
{
    if (const auto it = std::ranges::find(m_scripts, script); it == m_scripts.end())
    {
        m_scripts.push_back(script);

        script->OnStart();
        script->SetGameObject(shared_from_this());
    }
}

inline void IGameObject::DetachScript(const std::shared_ptr<IScript>& script)
{
    if (const auto it = std::ranges::find(m_scripts, script); it != m_scripts.end())
    {
        m_scripts.erase(it);
    }
}

inline void IGameObject::UpdateScripts() const
{
    for (const auto& script : m_scripts)
    {
        script->Update();
    }
}

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
    return DX::XMFLOAT2(m_position.x, m_position.y);
}
inline std::string IGameObject::GetTextureString() const
{
    return m_textureName;
}
inline float IGameObject::GetLayerFloat() const
{
    return m_layerFloat;
}
inline float IGameObject::GetScaleFloat() const
{
    return m_scaleFloat;
}
inline float IGameObject::GetRotationFloat() const 
{
    return m_rotationFloat;
}
inline DX::XMFLOAT2 IGameObject::GetOriginOffset() const
{
    return m_origonOffset;
}
inline bool IGameObject::IsOriginCentered() const
{
    return m_centerOrigin;
}
inline bool IGameObject::ShouldRender() const
{
    return m_shouldRender;
}
inline void IGameObject::SetPosition(DX::XMFLOAT2 position)
{
    m_position = position;
}
inline void IGameObject::SetRotation(float rotation) 
{
    m_rotationFloat = rotation;
}
inline void IGameObject::CenterOrigin(bool centerOrigin)
{
    this->m_centerOrigin = centerOrigin;
}
