#include <iostream>
#include <ZeusEngineCore/scripting/ISystem.h>
#include <ZeusEngineCore/engine/Scene.h>
#include "components/Components.h"

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
            auto& transform = entity.getComponent<ZEN::TransformComp>();
            transform.localRotation =
                glm::rotate(
                    transform.localRotation,
                    dt * t,
                    glm::vec3(0.0f, 1.0f, 0.0f)
                );
        }
    }
    void onUnload() override {

    }

};

extern "C" PLUGIN_API ZEN::ISystem* createScriptSystem() {
    return new TestSystem();
}