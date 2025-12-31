#include <iostream>
#include <ZeusEngineCore/scripting/ISystem.h>
#include "ZeusEngineCore/Scene.h"

class TestSystem : public ZEN::ISystem {
    ~TestSystem() override = default;

    void onLoad(ZEN::Scene* scene) override {
        ISystem::onLoad(scene);

    }
    void onUpdate(float dt) override {

    }
    void onUnload() override {

    }

};
//macos
extern "C" ZEN_API ZEN::ISystem* createScriptSystem() {
    return new TestSystem();
}