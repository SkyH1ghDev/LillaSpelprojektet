#pragma once
#include <memory>
#include "Mesh.hpp"


std::shared_ptr<IMeshVisible> CreateVisibleComponent(MeshType type);