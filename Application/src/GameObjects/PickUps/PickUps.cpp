#include "PickUps.hpp"
#include <SpEngine/Physics/Collider.hpp>

PickUps::PickUps(const PickUpType& type, const std::string& name) : IGameObject(name),
m_type(type)
{

}

void PickUps::Initialize(const std::string& textureName, DX::XMFLOAT2 position, float radius, float aspectRatio)
{
    this->m_layerFloat = 0.5;
    this->m_scaleFloat = 0.5;
    this->CenterOrigin(true);
    this->m_origonOffset = DX::XMFLOAT2(0, 50);
    this->m_shouldRender = true;
    this->m_isAlive = true;
    this->m_isActive = true;
    SetCollider(nullptr);
    this->m_radius = radius;
    this->m_aspectRatio = aspectRatio;
    this->m_position = position;
    this->m_textureName = textureName;
    this->m_collider = std::make_unique<Collider>(Collider(this->m_position, this->m_radius, this->m_aspectRatio, CollisionLayer::PickUps, static_cast<CollisionLayer>(
        static_cast<int>(CollisionLayer::PickUps) | static_cast<int>(CollisionLayer::Player))));
}

void PickUps::OnStart() {
    this->m_shouldRender = false;
    this->m_isAlive = false;
    this->m_isActive = false;
    this->m_layerFloat = 0.5;
    this->m_scaleFloat = 0.25;
    this->m_collider = std::make_unique<Collider>(Collider(this->m_position, this->m_radius, this->m_aspectRatio, CollisionLayer::PickUps, static_cast<CollisionLayer>(
        static_cast<int>(CollisionLayer::PickUps) | static_cast<int>(CollisionLayer::Player))));
    
}

void PickUps::Update() {

}

void PickUps::Reset()
{
    this->m_shouldRender = false;
    this->m_isAlive = false;
    this->m_isActive = false;
}