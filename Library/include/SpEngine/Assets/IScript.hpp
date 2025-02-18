#pragma once

#include <memory>
#include <SpEngine/Physics/PhysicsEngine.hpp>

class IGameObject;

class IScript
{
public:
    IScript() = default;
    virtual ~IScript() = default;
    IScript(const IScript& other) = default;
    IScript& operator=(const IScript& other) = default;
    IScript(IScript&& other) noexcept = default;
    IScript& operator=(IScript&& other) noexcept = default;

    virtual void OnStart() = 0;

    virtual void Update() = 0;

    void SetGameObject(const std::weak_ptr<IGameObject>& gameObject);

protected:

    std::weak_ptr<IGameObject> m_gameObject;
};

inline void IScript::SetGameObject(const std::weak_ptr<IGameObject>& gameObject)
{
    this->m_gameObject = gameObject;
}

