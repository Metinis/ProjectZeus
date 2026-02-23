#include <iostream>
#include <ZeusEngineCore/scripting/ISystem.h>
#include <ZeusEngineCore/engine/Scene.h>
#include <ZeusEngineCore/input/Input.h>
#include <ZeusEngineCore/input/KeyCodes.h>
#include "components/Components.h"

REGISTER_COMPONENT(CameraMov,
                   FIELD(CameraMov, sensitivity),
);

class CameraMovement : public ZEN::ISystem {
    bool m_isGrounded{false};

    ~CameraMovement() override = default;

    void onLoad(ZEN::Scene *scene) override {
        if (!scene) {
            // Scene pointer is null
            std::cerr << "Error: scene pointer is null!" << std::endl;
            return;
        }
        ISystem::onLoad(scene);
        ZEN::Input::setMouseLock(true);
    }

    void onUpdate(float dt) override {
        if (ZEN::Input::isKeyPressed(ZEN::Key::Escape)) {
            ZEN::Input::setMouseLock(false);
        }

        for (auto entity: ZEN_GET_ENTITIES(CameraMov)) {
            if (auto *tc = entity.tryGetComponent<ZEN::TransformComp>()) {
                static std::pair<float, float> lastMousePos = ZEN::Input::getMousePos();
                static bool firstMouse = true;

                std::pair<float, float> currentMousePos = ZEN::Input::getMousePos();

                glm::vec2 mouseDelta;
                mouseDelta.x = currentMousePos.first - lastMousePos.first;
                mouseDelta.y = currentMousePos.second - lastMousePos.second;

                lastMousePos = currentMousePos;

                if (firstMouse) {
                    mouseDelta = glm::vec2(0.0f);
                    firstMouse = false;
                }

                float sensitivity = 0.002f;
                float yawAmount = -mouseDelta.x * sensitivity;
                float pitchAmount = -mouseDelta.y * sensitivity;

                glm::quat pitchRot = glm::angleAxis(pitchAmount, glm::vec3(1.0f, 0.0f, 0.0f));

                tc->localRotation = tc->localRotation * pitchRot;

                for (auto& player : ZEN_GET_ENTITIES(Player)) {
                    if (auto *pc = player.tryGetComponent<ZEN::PhysicsBodyComp>()) {
                        pc->rotate(glm::vec3(0.0f, 1.0f, 0.0f), yawAmount);
                    }
                }

            }
        }
    }

    void onCollisionEnter(const ZEN::CollisionEvent &e) override {

    }

    void onCollisionStay(const ZEN::CollisionEvent &e) override {
    }

    void onCollisionExit(const ZEN::CollisionEvent &e) override {
    }

    void onUnload() override {
    }
};


extern "C" PLUGIN_API ZEN::ISystem *createScriptSystem() {
    return new CameraMovement();
}
