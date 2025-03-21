#include "Mesh.hpp"
#include "MeshStaticComponentFactory.hpp"
#include "MeshVisibleComponentFactory.hpp"
#include <iostream>

Mesh::Mesh(MeshType meshType, const std::string& name, const std::string& textureName) : IGameObject(name),
    m_static(CreateStaticComponent(meshType)),
    m_visible(CreateVisibleComponent(meshType)),
    m_type(meshType)
{
    this->m_textureName = textureName;
    std::cout << "Entity created of type: " << (m_type == MeshType::Background ? "Background" : "Enemy") << "\n";
}

void Mesh::OnStart() {
    PerformVisible();
    this->m_shouldRender = true;
    this->m_isAlive = true;
    this->m_isActive = false;
}

void Mesh::Update() {
    this->m_visible->UpdateLayer(this->m_position, this->m_layerFloat);
}

void Mesh::Reset()
{
    PerformVisible();
    this->m_shouldRender = true;
    this->m_isAlive = true;
    this->m_isActive = false;
}

void Mesh::SetTexture(std::string textureName)
{
    this->m_textureName = textureName;
}