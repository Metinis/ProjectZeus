#include <iostream>
#include <ZeusEngineCore/scripting/ISystem.h>
#include "ZeusEngineCore/Scene.h"

//todo fix duplicates in .h includes
struct Test {
    float test;
};
REGISTER_COMPONENT(Test,
    FIELD(Test, test),
);

class TestSystem : public ZEN::ISystem {
    ~TestSystem() override = default;

    void onLoad(ZEN::Scene* scene) override {
        ISystem::onLoad(scene);

    }
    void onUpdate(float dt) override {
        for (auto entity : ZEN_GET_ENTITIES(Test)) {
            float t = ZEN_GET_FIELD(Test, entity, test);
            entity.getComponent<ZEN::TransformComp>().localRotation.y += dt * t;
        }
    }
    void onUnload() override {

    }

};
//macos
extern "C" ZEN_API ZEN::ISystem* createScriptSystem() {
    return new TestSystem();
}