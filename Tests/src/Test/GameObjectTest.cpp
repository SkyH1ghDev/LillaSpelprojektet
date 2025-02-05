#include "DummyObjects/DummyGameObject.hpp"
#include "DummyObjects/DummyScript.hpp"

#include <gtest/gtest.h>


TEST(GameObjStartValues, TextureName)
{
    DummyGameObject dummyGameObject;

    ASSERT_TRUE(dummyGameObject.GetTextureString().empty());
}

TEST(GameObjStartValues, PositionX)
{
    DummyGameObject dummyGameObject;

    ASSERT_EQ(dummyGameObject.GetPosition().x, DX::XMFLOAT2(0, 0).x);
}

TEST(GameObjectStartValues, PositionY)
{
    DummyGameObject dummyGameObject;

    ASSERT_EQ(dummyGameObject.GetPosition().y, DX::XMFLOAT2(0, 0).y);
}

TEST(GameObjStartValues, IsActive)
{
    DummyGameObject dummyGameObject;

    ASSERT_TRUE(dummyGameObject.IsActive());
}

TEST(GameObjStartValues, ShouldRender)
{
    DummyGameObject dummyGameObject;

    ASSERT_FALSE(dummyGameObject.ShouldRender());
}

TEST(GameObjFunc, SetActive)
{
    DummyGameObject dummyGameObject;

    dummyGameObject.SetActive(false);

    ASSERT_FALSE(dummyGameObject.IsActive());
}

TEST(GameObjFunc, AttachScript)
{
    std::shared_ptr<DummyGameObject> dummyGameObject = std::make_shared<DummyGameObject>();
    std::shared_ptr<DummyScript> dummyScript = std::make_shared<DummyScript>();

    dummyGameObject->AttachScript(std::static_pointer_cast<IScript, DummyScript>(dummyScript));

    ASSERT_EQ(dummyGameObject->GetAttachedScripts().size(), 1);
}

TEST(GameObjFunc, DetachScript)
{
    std::shared_ptr<DummyGameObject> dummyGameObject = std::make_shared<DummyGameObject>();
    std::shared_ptr<DummyScript> dummyScript = std::make_shared<DummyScript>();

    dummyGameObject->AttachScript(std::static_pointer_cast<IScript, DummyScript>(dummyScript));
    dummyGameObject->DetachScript(std::static_pointer_cast<IScript, DummyScript>(dummyScript));

    ASSERT_EQ(dummyGameObject->GetAttachedScripts().size(), 0);
}
