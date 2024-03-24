
#ifndef UEZ3_FIGHTER_H
#define UEZ3_FIGHTER_H

#include "npc.h"

class Fighter : public NPC {
public:
    Fighter(const std::string& name, int health, int gold, int armor, int magicResistance, int strength);
    virtual ~Fighter();

    virtual void attack(Character* target) override;

private:
    int strength;
};


#endif //UEZ3_FIGHTER_H
