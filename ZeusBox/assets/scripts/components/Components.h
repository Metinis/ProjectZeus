#pragma once
#include "ZeusEngineCore/scripting/CompRegistry.h"

struct Player {
    float health;
    float speed;
};
struct Test {
    float test;
};

REGISTER_COMPONENT(Player,
    FIELD(Player, health),
    FIELD(Player, speed)
);

REGISTER_COMPONENT(Test,
    FIELD(Test, test),
);

