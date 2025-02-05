#pragma once
#include <memory>
#include "Mesh.hpp"
#include "BackgroundVisible.hpp"

std::shared_ptr<IMeshVisible> CreateVisibleComponent(MeshType type);