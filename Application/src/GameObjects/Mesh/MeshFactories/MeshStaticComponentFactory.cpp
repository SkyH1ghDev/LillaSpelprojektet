#include "MeshStaticComponentFactory.hpp"

std::shared_ptr<IMeshStatic> CreateStaticComponent(MeshType type)
{
    switch (type) {
    case MeshType::Background:
        return std::make_shared<BackgroundStatic>();
    default:
        throw std::invalid_argument("Unknown MeshType in CreateStaticComponent");
    }
}
