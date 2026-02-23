#include <iostream>
#include <ZeusEngineCore/scripting/ISystem.h>
#include <ZeusEngineCore/engine/Scene.h>
#include <ZeusEngineCore/input/Input.h>
#include <ZeusEngineCore/input/KeyCodes.h>
#include "components/Components.h"

REGISTER_COMPONENT(Player,
                   FIELD(Player, health),
                   FIELD(Player, speed),
                   FIELD(Player, jumpImpulse),
                   FIELD(Player, rotationSpeed)
);

class MovementSystem : public ZEN::ISystem {
    bool m_isGrounded{false};

    ~MovementSystem() override = default;

    void onLoad(ZEN::Scene *scene) override {
        if (!scene) {
            // Scene pointer is null
            std::cerr << "Error: scene pointer is null!" << std::endl;
            return;
        }
        ISystem::onLoad(scene);
    }

    void onUpdate(float dt) override {
        if (ZEN::Input::isKeyPressed(ZEN::Key::Escape)) {
            ZEN::Input::setMouseLock(false);
        }
        for (auto entity: ZEN_GET_ENTITIES(Player)) {
            if (auto *pc = entity.tryGetComponent<ZEN::PhysicsBodyComp>()) {
                auto &tc = entity.getComponent<ZEN::TransformComp>();
                glm::vec3 vel = pc->getVelocity();

                float moveX = 0.0f;
                float moveZ = 0.0f;

                if (ZEN::Input::isKeyPressed(ZEN::Key::W)) moveZ -= 1.0f;
                if (ZEN::Input::isKeyPressed(ZEN::Key::S)) moveZ += 1.0f;
                if (ZEN::Input::isKeyPressed(ZEN::Key::A)) moveX -= 1.0f;
                if (ZEN::Input::isKeyPressed(ZEN::Key::D)) moveX += 1.0f;

                glm::vec3 forward = glm::normalize(glm::vec3(tc.worldMatrix[2]));
                glm::vec3 right = glm::normalize(glm::vec3(tc.worldMatrix[0]));
                glm::vec3 moveDir = forward * moveZ + right * moveX;
                if (glm::length(moveDir) > 0.0f)
                    moveDir = glm::normalize(moveDir);

                float speed = ZEN_GET_FIELD(Player, entity, speed);
                glm::vec3 currentVel = pc->getVelocity();

                glm::vec3 inputVel = moveDir * speed;
                currentVel.x = inputVel.x;
                currentVel.z = inputVel.z;
                pc->setVelocity(currentVel);

                float jumpImpulse = ZEN_GET_FIELD(Player, entity, jumpImpulse);
                if (ZEN::Input::isKeyPressed(ZEN::Key::Space) && m_isGrounded) {
                    pc->addImpulse({0.0f, jumpImpulse, 0.0f});
                    m_isGrounded = false;

                }
            }
        }
    }

    void onCollisionEnter(const ZEN::CollisionEvent &e) override {
        if (ZEN_HAS_COMP(Player, e.A)) {
            m_isGrounded = true;
        }
    }

    void onCollisionStay(const ZEN::CollisionEvent &e) override {
    }

    void onCollisionExit(const ZEN::CollisionEvent &e) override {
    }

    void onUnload() override {
    }
};


extern "C" PLUGIN_API ZEN::ISystem *createScriptSystem() {
    return new MovementSystem();
}
