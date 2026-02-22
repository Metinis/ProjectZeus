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
            if (auto* pc = entity.tryGetComponent<ZEN::PhysicsBodyComp>()) {
                auto& tc = entity.getComponent<ZEN::TransformComp>();
                float rotationSpeed = ZEN_GET_FIELD(Test, entity, test);
                pc->rotate(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(rotationSpeed) * dt);
            }
        }
    }
    void onCollisionEnter(const ZEN::CollisionEvent& e) override {
        ZEN::Entity entityA = e.A;
        if (ZEN_HAS_COMP(Test, e.B) && e.A.hasComponent<ZEN::PhysicsBodyComp>()) {
            auto& pb = entityA.getComponent<ZEN::PhysicsBodyComp>();
            glm::vec3 impulse = -e.contactNormal * 100.0f;
            pb.addImpulse(impulse);
        }
    }
    void onCollisionStay(const ZEN::CollisionEvent &e) override {

    }
    void onCollisionExit(const ZEN::CollisionEvent& e) override {

    }
    void onUnload() override {

    }

};

extern "C" PLUGIN_API ZEN::ISystem* createScriptSystem() {
    return new TestSystem();
}