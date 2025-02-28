#pragma once
#include <memory>
#include <SpEngine/Assets/Game/IGameObject.hpp>

// Define an enum for the entity type

class StaticMesh : public IGameObject
{
public:

    StaticMesh() = default;
    ~StaticMesh() override = default;
    StaticMesh(const StaticMesh& other) = default;
    StaticMesh& operator=(const StaticMesh& other) = default;
    StaticMesh(StaticMesh&& other) noexcept = default;
    StaticMesh& operator=(StaticMesh&& other) noexcept = default;

    StaticMesh(const std::string& name, const std::string& textureName, DX::XMFLOAT2 position, float radius, float aspectRatio);

    void Update() override;
    void OnStart() override;
    void Reset() override;

private:
    float m_radius;
    float m_aspectRatio;
};