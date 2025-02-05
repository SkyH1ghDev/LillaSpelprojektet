#include "MeshVisibleComponentFactory.hpp"

std::shared_ptr<IMeshVisible> CreateVisibleComponent(MeshType type)
{
    switch (type) {
    case MeshType::Background:
        return std::shared_ptr<IMeshVisible>();
    default:
        throw std::invalid_argument("Unknown MeshType in CreateVisibleComponent");
    }
}
