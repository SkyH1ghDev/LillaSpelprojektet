#pragma once
#include <memory>
#include "Mesh.hpp"
#include "BackgroundVisible.hpp"
#include "MouseVisible.hpp"
#include "ObjectVisible.hpp"

std::shared_ptr<IMeshVisible> CreateVisibleComponent(MeshType type);