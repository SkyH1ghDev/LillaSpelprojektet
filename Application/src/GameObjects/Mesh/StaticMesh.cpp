#include "StaticMesh.hpp"
#include <SpEngine/Physics/Collider.hpp>

StaticMesh::StaticMesh(const std::string& name) : IGameObject(name)
{

}

void StaticMesh::Initialize(const std::string& textureName, DX::XMFLOAT2 position, float radius, float aspectRatio)
{   
    this->m_radius = radius;
    this->m_aspectRatio = aspectRatio;
    this->m_position = position;
    this->m_textureName = textureName;
}

void StaticMesh::OnStart() {
    this->m_shouldRender = true;
    this->m_isAlive = true;
    this->m_isActive = false;
    this->m_layerFloat = 0.5;
    this->m_scaleFloat = 0.25;
    this->m_collider = std::make_unique<Collider>(Collider(this->m_position, this->m_radius, this->m_aspectRatio, CollisionLayer::StaticMesh, static_cast<CollisionLayer>(
        static_cast<int>(CollisionLayer::StaticMesh) | static_cast<int>(CollisionLayer::Player))));
    this->CenterOrigin(true);
    this->m_origonOffset = DX::XMFLOAT2(0, 50);
}

void StaticMesh::Update() {

}

void StaticMesh::Reset()
{
    this->m_shouldRender = true;
    this->m_isAlive = true;
    this->m_isActive = false;
}