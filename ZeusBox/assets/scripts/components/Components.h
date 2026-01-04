#include "ZeusEngineCore/scripting/CompRegistry.h"

struct Player {
    float health;
    float speed;
};

REGISTER_COMPONENT(Player,
    FIELD(Player, health),
    FIELD(Player, speed)
);