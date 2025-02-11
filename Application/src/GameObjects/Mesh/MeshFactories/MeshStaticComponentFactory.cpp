#include "MeshStaticComponentFactory.hpp"
#include "CursorMeshStatic.hpp"
#include "WeaponMeshStatic.hpp"

std::shared_ptr<IMeshStatic> CreateStaticComponent(MeshType type)
{
    switch (type) {
    case MeshType::Background:
        return std::make_shared<BackgroundStatic>();
        break;
        case MeshType::Mouse:
        return std::make_shared<CursorMeshStatic>();
        break;
        case MeshType::Weapon:
        return std::make_shared<WeaponMeshStatic>();
        break;
    default:
        throw std::invalid_argument("Unknown MeshType in CreateStaticComponent");
        break;
    }
}
