#include <iostream>
#include <ZeusEngineCore/scripting/ISystem.h>
#include "ZeusEngineCore/Scene.h"

class MovementSystem : public ZEN::ISystem {
    ~MovementSystem() override = default;

    void onLoad(ZEN::Scene* scene) override {
        ISystem::onLoad(scene);
        std::cout<<"[MovementSystem] loaded"<<std::endl;
    }
    void onUpdate(float dt) override {
        std::cout<<"[MovementSystem] update dt="<<dt<<std::endl;
    }
    void onUnload() override {
        std::cout<<"[MovementSystem] unloaded"<<std::endl;
    }

};
//macos
extern "C" ZEN_API ZEN::ISystem* createScriptSystem() {
    return new MovementSystem();
}