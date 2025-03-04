#pragma once
#include "IMeshStatic.hpp"
#include "IMeshVisible.hpp"

#include <memory>

#include <SpEngine/Assets/Game/IGameObject.hpp>

// Define an enum for the entity type
enum class MeshType {
    Background,
    Title,
    Mouse,
    Object

};

class Mesh : public IGameObject
{
public:

    Mesh() = default;
    ~Mesh() override = default;
    Mesh(const Mesh& other) = default;
    Mesh& operator=(const Mesh& other) = default;
    Mesh(Mesh&& other) noexcept = default;
    Mesh& operator=(Mesh&& other) noexcept = default;

    Mesh(MeshType meshType, const std::string& name, const std::string& textureName);
    
    void PerformStatic() { if (m_static) m_static->Static(); }
    void PerformVisible() { if (m_visible) m_visible->Visible(m_textureName, m_position, m_layerFloat, m_scaleFloat); }
    void SetTexture(std::string textureName);

    void Update() override;
    void OnStart() override;
    void Reset() override;

    MeshType GetType() const { return m_type; }

private:
    std::shared_ptr<IMeshStatic> m_static;
    std::shared_ptr<IMeshVisible> m_visible;
    MeshType m_type;
};