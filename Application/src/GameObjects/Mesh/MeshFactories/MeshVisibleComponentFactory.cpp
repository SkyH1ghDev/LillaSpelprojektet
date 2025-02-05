#include "MeshVisibleComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IMeshVisible> CreateVisibleComponent(MeshType type)
{
    switch (type) {
    case MeshType::Background:
        return std::make_shared<BackgroundVisible>();
    default:
        throw std::invalid_argument("Unknown MeshType in CreateVisibleComponent");
    }
}
