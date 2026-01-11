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
    ~MovementSystem() override = default;

    void onLoad(ZEN::Scene *scene) override {
        ISystem::onLoad(scene);
    }

    void updateMovement(float dt) {
        glm::vec3 dir(0.0f);
        if (ZEN::Input::isKeyPressed(ZEN::Key::W)) dir.z -= 1.0f;
        if (ZEN::Input::isKeyPressed(ZEN::Key::S)) dir.z += 1.0f;
        if (ZEN::Input::isKeyPressed(ZEN::Key::A)) dir.x -= 1.0f;
        if (ZEN::Input::isKeyPressed(ZEN::Key::D)) dir.x += 1.0f;
        if (ZEN::Input::isKeyPressed(ZEN::Key::Space)) dir.y += 1.0f;
        if (ZEN::Input::isKeyPressed(ZEN::Key::LeftShift)) dir.y -= 1.0f;
        if (glm::length(dir) > 0.0f) dir = glm::normalize(dir);

        if (glm::length(dir) == 0.0f) return;

        for (auto entity : ZEN_GET_ENTITIES(Player)) {
            float speed = ZEN_GET_FIELD(Player, entity, speed);
            entity.getComponent<ZEN::TransformComp>().localPosition += dir * dt * speed;
        }
    }

    void onUpdate(float dt) override {
        //updateMovement(dt);
        for (auto entity : ZEN_GET_ENTITIES(Player)) {
            if (auto* pc = entity.tryGetComponent<ZEN::PhysicsBodyComp>()) {
                auto& tc = entity.getComponent<ZEN::TransformComp>();
                glm::vec3 vel = pc->getVelocity();

                float moveX = 0.0f;
                float moveZ = 0.0f;

                if (ZEN::Input::isKeyPressed(ZEN::Key::W)) moveZ -= 1.0f;
                if (ZEN::Input::isKeyPressed(ZEN::Key::S)) moveZ += 1.0f;
                if (ZEN::Input::isKeyPressed(ZEN::Key::A)) moveX -= 1.0f;
                if (ZEN::Input::isKeyPressed(ZEN::Key::D)) moveX += 1.0f;

                glm::vec3 forward = glm::normalize(glm::vec3(tc.worldMatrix[2]));
                glm::vec3 right   = glm::normalize(glm::vec3(tc.worldMatrix[0]));
                glm::vec3 moveDir = forward * moveZ + right * moveX;
                if (glm::length(moveDir) > 0.0f)
                    moveDir = glm::normalize(moveDir);
                float speed = ZEN_GET_FIELD(Player, entity, speed);
                vel.x = moveDir.x * speed;
                vel.z = moveDir.z * speed;
                pc->setVelocity({vel.x, pc->getVelocity().y, vel.z});

                float jumpImpulse = ZEN_GET_FIELD(Player, entity, jumpImpulse);
                if (ZEN::Input::isKeyPressed(ZEN::Key::Space)) {
                    pc->addImpulse({0.0f, jumpImpulse, 0.0f});
                }

                float rotDir = 0.0f;
                if (ZEN::Input::isKeyPressed(ZEN::Key::Left)) {
                    rotDir += 1.0f;
                }
                if (ZEN::Input::isKeyPressed(ZEN::Key::Right)) {
                    rotDir -= 1.0f;
                }
                float rotationSpeed = ZEN_GET_FIELD(Player, entity, rotationSpeed);
                pc->rotate(glm::vec3(0.0f, 1.0f, 0.0f), rotDir * glm::radians(rotationSpeed) * dt);
            }
        }
    }


    void onUnload() override {

    }
};

//macos
extern "C" ZEN_API ZEN::ISystem *createScriptSystem() {
    return new MovementSystem();
}
