#include <iostream>
#include <ZeusEngineCore/scripting/ISystem.h>
#include "ZeusEngineCore/Scene.h"
#include "ZeusEngineCore/input/Input.h"
#include "ZeusEngineCore/input/KeyCodes.h"

class MovementSystem : public ZEN::ISystem {
    ~MovementSystem() override = default;

    void onLoad(ZEN::Scene* scene) override {
        ISystem::onLoad(scene);

    }
    void onUpdate(float dt) override {
        if (ZEN::Input::isKeyPressed(ZEN::Key::W)) {
            for (auto entity : m_Scene->getEntities<ZEN::MeshComp>()) {
                entity.getComponent<ZEN::TransformComp>().localPosition.z -= 1.0f * dt;
            }
        }
        if (ZEN::Input::isKeyPressed(ZEN::Key::S)) {
            for (auto entity : m_Scene->getEntities<ZEN::MeshComp>()) {
                entity.getComponent<ZEN::TransformComp>().localPosition.z += 1.0f * dt;
            }
        }
        if (ZEN::Input::isKeyPressed(ZEN::Key::A)) {
            for (auto entity : m_Scene->getEntities<ZEN::MeshComp>()) {
                entity.getComponent<ZEN::TransformComp>().localPosition.x -= 1.0f * dt;
            }
        }
        if (ZEN::Input::isKeyPressed(ZEN::Key::D)) {
            for (auto entity : m_Scene->getEntities<ZEN::MeshComp>()) {
                entity.getComponent<ZEN::TransformComp>().localPosition.x += 1.0f * dt;
            }
        }
        if (ZEN::Input::isKeyPressed(ZEN::Key::Space)) {
            for (auto entity : m_Scene->getEntities<ZEN::MeshComp>()) {
                entity.getComponent<ZEN::TransformComp>().localPosition.y += 1.0f * dt;
            }
        }
        if (ZEN::Input::isKeyPressed(ZEN::Key::LeftShift)) {
            for (auto entity : m_Scene->getEntities<ZEN::MeshComp>()) {
                entity.getComponent<ZEN::TransformComp>().localPosition.y -= 1.0f * dt;
            }
        }
    }
    void onUnload() override {

    }

};
//macos
extern "C" ZEN_API ZEN::ISystem* createScriptSystem() {
    return new MovementSystem();
}