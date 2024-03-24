

#ifndef UEZ3_NPC_H
#define UEZ3_NPC_H

#include "character.h"

class NPC : public Character {

public:
    NPC(const std::string& name, int health, int gold, int armor, int magicResistance);
    virtual ~NPC();

    virtual void attack(Character* target) = 0;
};


#endif //UEZ3_NPC_H
