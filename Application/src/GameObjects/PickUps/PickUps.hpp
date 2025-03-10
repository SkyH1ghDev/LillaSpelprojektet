#pragma once
#include <memory>
#include <SpEngine/Assets/Game/IGameObject.hpp>

enum class PickUpType {
    Base
};

class PickUps : public IGameObject
{
public:

    PickUps() = default;
    ~PickUps() override = default;
    PickUps(const PickUps& other) = default;
    PickUps& operator=(const PickUps& other) = default;
    PickUps(PickUps&& other) noexcept = default;
    PickUps& operator=(PickUps&& other) noexcept = default;

    PickUps(const PickUpType& type, const std::string& name);

    void Initialize(const std::string& textureName, DX::XMFLOAT2 position, float radius, float aspectRatio);

    void Update() override;
    void OnStart() override;
    void Reset() override;

private:
    float m_radius;
    float m_aspectRatio;
    PickUpType m_type;
};