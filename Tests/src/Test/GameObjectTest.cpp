#include "DummyObjects/DummyGameObject.hpp"
#include "DummyObjects/DummyScript.hpp"

#include <gtest/gtest.h>


TEST(GameObjStartValues, TextureName)
{
    DummyGameObject dummyGameObject;

    ASSERT_TRUE(dummyGameObject.GetTextureString());
}

TEST(GameObjStartValues, Position)
{
    DummyGameObject dummyGameObject;

    ASSERT_EQ(dummyGameObject.GetPosition(), DX::XMFLOAT2(0, 0));
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
    DummyGameObject dummyGameObject;
    std::shared_ptr<DummyScript> dummyScript;

    dummyGameObject.AttachScript(std::static_pointer_cast<IScript, DummyScript>(dummyScript));

    ASSERT_EQ(dummyGameObject.GetAttachedScripts().size(), 1);
}

TEST(GameObjFunc, DetachScript)
{
    DummyGameObject dummyGameObject;
    std::shared_ptr<DummyScript> dummyScript;

    dummyGameObject.AttachScript(std::static_pointer_cast<IScript, DummyScript>(dummyScript));
    dummyGameObject.DetachScript(std::static_pointer_cast<IScript, DummyScript>(dummyScript));

    ASSERT_EQ(dummyGameObject.GetAttachedScripts().size(), 0);
}
