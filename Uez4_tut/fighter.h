#ifndef FIGHTER_H_
#define FIGHTER_H_

#include "npc.h"

class Fighter : public NPC {
public:
    Fighter(const std::string& name, int health, int gold, int armor, int magicResistance, int strength);
    virtual ~Fighter();

    virtual void attack(Character* target) override;

private:
    int strength;
};

#endif /* FIGHTER_H_ */
