#include "MeshVisibleComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IMeshVisible> CreateVisibleComponent(MeshType type)
{
    switch (type) {
    case MeshType::Background:
        return std::make_shared<BackgroundVisible>();
        break;
    case MeshType::Mouse:
        return std::make_shared<MouseVisible>();
        break;
    case MeshType::Weapon:
        return std::make_shared<WeaponVisible>();
        break;
    default:
        throw std::invalid_argument("Unknown MeshType in CreateVisibleComponent");
        break;
    }
}
