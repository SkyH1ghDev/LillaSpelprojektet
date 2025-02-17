#include "MeshStaticComponentFactory.hpp"
#include "CursorMeshStatic.hpp"
#include "ObjectMeshStatic.hpp"

std::shared_ptr<IMeshStatic> CreateStaticComponent(MeshType type)
{
    switch (type) {
    case MeshType::Background:
        return std::make_shared<BackgroundStatic>();
        break;
    case MeshType::Mouse:
        return std::make_shared<CursorMeshStatic>();
        break;
        case MeshType::Object:
        return std::make_shared<ObjectMeshStatic>();
        break;
    default:
        throw std::invalid_argument("Unknown MeshType in CreateStaticComponent");
        break;
    }
}
