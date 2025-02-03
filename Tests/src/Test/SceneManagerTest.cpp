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
    SceneManager sceneManager;

    bool Success = sceneManager.RegisterScene("game_level_1", []() { return TestFactory::CreateScene(1); });

    ASSERT_EQ(Success, true);
}

TEST(SceneManager, LoadScene)
{
    SceneManager sceneManager;

    sceneManager.RegisterScene("game_level_1", []() { return TestFactory::CreateScene(1); });

    bool Success = sceneManager.SetCurrentScene("game_level_1");

    ASSERT_EQ(Success, true);
}

TEST(SceneManager, Update)
{
    SceneManager sceneManager;

    sceneManager.RegisterScene("game_level_1", []() { return TestFactory::CreateScene(1); });

    sceneManager.SetCurrentScene("game_level_1");

    bool Success = sceneManager.Update();

    ASSERT_EQ(Success, true);
}