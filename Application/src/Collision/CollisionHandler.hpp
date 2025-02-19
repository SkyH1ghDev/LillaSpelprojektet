#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include <SpEngine/Assets/Game/IGameObject.hpp>
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Assets/Game/IScript.hpp>

struct GridCell {
    int x = 0, y = 0;

    bool operator==(const GridCell& other) const {
        return x == other.x && y == other.y;
    }
};

// Hash function for GridCell
namespace std {
    template <>
    struct hash<GridCell> {
        size_t operator()(const GridCell& cell) const {
            return ((hash<int>()(cell.x) * 73856093) ^ (hash<int>()(cell.y) * 19349663));
        }
    };
}

class CollisionHandler : public IScript {  // Inheriting from Script to make it a component
public:
    CollisionHandler(int tileSize);
    ~CollisionHandler() override = default;

    void OnStart() override;    // Runs once when the script is initialized
    void Update() override;   // Runs every frame

private:
    int tileSize;
    std::unordered_map<GridCell, std::vector<std::shared_ptr<IGameObject>>> grid;

    GridCell GetTileForPosition(float x, float y);
    void HandleCollision(const std::shared_ptr<IGameObject>& objA,
        const std::shared_ptr<IGameObject>& objB);
};
