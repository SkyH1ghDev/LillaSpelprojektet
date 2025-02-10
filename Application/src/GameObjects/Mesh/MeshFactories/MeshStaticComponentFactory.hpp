#pragma once
#include <memory>
#include "Mesh.hpp"
#include "BackgroundStatic.hpp"
#include "MouseStatic.hpp"

std::shared_ptr<IMeshStatic> CreateStaticComponent(MeshType type);