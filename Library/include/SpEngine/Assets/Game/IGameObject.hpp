#pragma once

#include <SpEngine/Assets/Game/IScript.hpp>
#include <DirectXMath.h>
#include <memory>
#include <string>
#include <vector>
#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Physics/Collider.hpp>
#include <SpEngine/Clock/Clock.hpp>

namespace DX = DirectX;

class IScript;

class IGameObject : public std::enable_shared_from_this<IGameObject>
{

public:

    IGameObject();
    IGameObject(const std::string& name);
    virtual ~IGameObject() = default;
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

    virtual void Reset() = 0;

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
     * Sets the render state of the game object
     *
     * @param renderState The state to set the object to
     */
    void SetShouldRender(bool renderState);
     
    std::string GetName() const;

    int GetUID() const;
    
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

    void SetCollider(std::shared_ptr<Collider> collider);

    std::shared_ptr<Collider> GetCollider() const;

    void SetName(const std::string& name);
    void UpdateAnimation();
    void ResetAnimation();
    float GetAnimationTime();

    /**
     * Sets objects alive state.
     *, if currently alive in a scene
     *
     */
    void SetIsAlive(bool isAlive);

    /**
     * Returns wether or not GameObject is alive in a scene.
     *
     */
    bool IsAlive();

protected:
    std::string m_gameObjectName;
    std::string m_textureName;
    DX::XMFLOAT2 m_position = {0, 0};
    std::shared_ptr<Collider> m_collider = nullptr;
    float m_layerFloat = 0.0;
    float m_scaleFloat = 1.0;
    float m_rotationFloat = 0.0;
    DX::XMFLOAT2 m_origonOffset = { 0, 0 };

    bool m_centerOrigin = false;
    bool m_isActive = false;
    bool m_shouldRender = false;
    bool m_isAlive = false;

    std::vector<std::shared_ptr<IScript>> m_scripts;
    
    int m_uniqueID = m_numGameObjects++;
    static int m_numGameObjects;
    float m_animationTime = 0;
};

inline IGameObject::IGameObject()
{
    this->m_gameObjectName = "Unnamed##" + std::to_string(m_numGameObjects);
    ++m_numGameObjects;
}

inline IGameObject::IGameObject(const std::string& name)
{
    m_gameObjectName = name + "##" + std::to_string(m_numGameObjects);
    ++m_numGameObjects;
}


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

inline void IGameObject::SetShouldRender(bool renderState)
{
    m_shouldRender = renderState;
}

inline std::string IGameObject::GetName() const
{
    return m_gameObjectName;
}

inline int IGameObject::GetUID() const
{
    return this->m_uniqueID;
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

/* Collision Handling */
inline void IGameObject::SetCollider(std::shared_ptr<Collider> collider)
{
    m_collider = collider;
}

inline std::shared_ptr<Collider> IGameObject::GetCollider() const
{
    return m_collider;
}

inline void IGameObject::SetName(const std::string& name)
{
    this->m_gameObjectName = name;
}

inline void IGameObject::UpdateAnimation()
{
    this->m_animationTime += Clock::GetDeltaTime();
}

inline void IGameObject::ResetAnimation()
{
    this->m_animationTime = 0;
}

inline float IGameObject::GetAnimationTime()
{
    return this->m_animationTime;
}

inline void IGameObject::SetIsAlive(bool isAlive)
{
    this->m_isAlive = isAlive;
}

inline bool IGameObject::IsAlive()
{
    return this->m_isAlive;
}
