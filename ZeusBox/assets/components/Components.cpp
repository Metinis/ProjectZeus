#include "ZeusEngineCore/scripting/CompRegistry.h"

struct Player {
    float health;
    float speed{10.0f};
};

REGISTER_COMPONENT(Player,
    FIELD(Player, health),
    FIELD(Player, speed)
);