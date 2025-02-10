#pragma once
#include <memory>
#include "Mesh.hpp"
#include "BackgroundStatic.hpp"

std::shared_ptr<IMeshStatic> CreateStaticComponent(MeshType type);
