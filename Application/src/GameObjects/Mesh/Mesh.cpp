#include "Mesh.hpp"
#include "MeshStaticComponentFactory.hpp"
#include "MeshVisibleComponentFactory.hpp"
#include <iostream>

Mesh::Mesh(MeshType meshType) :
    m_static(CreateStaticComponent(meshType)),
    m_visible(CreateVisibleComponent(meshType)),
    m_type(meshType)
{
    std::cout << "Entity created of type: " << (m_type == MeshType::Background ? "Background" : "Enemy") << "\n";
}

void Mesh::OnStart() {
    PerformVisible();
    this->m_toRender = true;
}

void Mesh::Update() {}
