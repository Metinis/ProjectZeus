#include <iostream>
#include <ZeusEngineCore/scripting/ISystem.h>
#include <ZeusEngineCore/engine/Scene.h>
#include <ZeusEngineCore/input/Input.h>
#include <ZeusEngineCore/input/KeyCodes.h>
#include "components/Components.h"

REGISTER_COMPONENT(Player,
    FIELD(Player, health),
    FIELD(Player, speed)
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
        updateMovement(dt);

    }


    void onUnload() override {

    }
};

//macos
extern "C" ZEN_API ZEN::ISystem *createScriptSystem() {
    return new MovementSystem();
}
