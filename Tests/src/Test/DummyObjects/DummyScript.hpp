#pragma once

#include <SpEngine/Assets/IScript.hpp>

class DummyScript : public IScript
{
public:
    DummyScript() = default;
    ~DummyScript() override = default;
    DummyScript(const DummyScript& other) = default;
    DummyScript& operator=(const DummyScript& other) = default;
    DummyScript(DummyScript&& other) noexcept = default;
    DummyScript& operator=(DummyScript&& other) noexcept = default;

    void Update() override;
    void OnStart() override;

};

inline void DummyScript::Update()
{

}

inline void DummyScript::OnStart()
{

}
