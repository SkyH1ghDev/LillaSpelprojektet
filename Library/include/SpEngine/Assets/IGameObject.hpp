#pragma once

#include <SpEngine/Assets/IScript.hpp>

#include <DirectXMath.h>
#include <memory>
#include <string>
#include <vector>

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
     * Returns whether the GameObject should be rendered
     *
     * @return True if yes, False if no
     */
    bool ShouldRender() const;

protected:
    std::string m_textureName;
    DX::XMFLOAT2 m_position = { 0, 0 };

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
        script->SetGameObject(nullptr);
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
    return m_position;
}
inline std::string IGameObject::GetTextureString() const
{
    return m_textureName;
}
inline bool IGameObject::ShouldRender() const
{
    return m_shouldRender;
}
