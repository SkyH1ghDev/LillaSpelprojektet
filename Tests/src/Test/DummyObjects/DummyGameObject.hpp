#pragma once

#include <SpEngine/Assets/IGameObject.hpp>

class DummyGameObject : public IGameObject
{
public:
    DummyGameObject() = default;
    ~DummyGameObject() override = default;
    DummyGameObject(const DummyGameObject& other) = default;
    DummyGameObject& operator=(const DummyGameObject& other) = default;
    DummyGameObject(DummyGameObject&& other) noexcept = default;
    DummyGameObject& operator=(DummyGameObject&& other) noexcept = default;

    void Update() override;
    void OnStart() override;

    std::vector<std::shared_ptr<IScript>> GetAttachedScripts();
};

inline void DummyGameObject::Update()
{

}

inline void DummyGameObject::OnStart()
{

}

inline std::vector<std::shared_ptr<IScript>> DummyGameObject::GetAttachedScripts()
{
    return m_scripts;
}
