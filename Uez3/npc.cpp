

#include "npc.h"

NPC::NPC(const std::string &name, int health, int gold, int armor, int magicResistance) :
Character(name, health, gold,
          armor,
          magicResistance) {

}

NPC::~NPC() {}