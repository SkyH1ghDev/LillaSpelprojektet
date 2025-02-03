#include <gtest/gtest.h>
#include <SpEngine/Manager/SceneManager.hpp>
#include <iostream>
#include <SpEngine/Assets/IScene.hpp>
#include <unordered_map>
#include <string>
#include <functional>
#include <memory>
#include <stdexcept>

class TestScene : public IScene {
private:
    int m_level;

public:
    explicit TestScene(int level) : m_level(level) {}

    void Display() const override {

    }
};

class TestFactory {
public:
    static std::unique_ptr<IScene> CreateScene(int level) {
        return std::make_unique<TestScene>(level);
    }
};

TEST(SceneManager, RegisterScene)
{
    bool Success = SceneManager::RegisterScene("game_level_1", TestFactory::CreateScene(1));

    ASSERT_EQ(Success, true);
}

TEST(SceneManager, LoadScene)
{
    bool Success = SceneManager::RegisterScene("game_level_1", TestFactory::CreateScene(1));

    Success = SceneManager::SetCurrentScene("game_level_1");

    ASSERT_EQ(Success, true);
}
