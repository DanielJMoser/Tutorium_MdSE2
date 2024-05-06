#ifndef SORCERER_H_
#define SORCERER_H_

#include "npc.h"

class Sorcerer : public NPC {
public:
    Sorcerer(const std::string& name, int health, int gold, int armor, int magicResistance, int magicPower);
    virtual ~Sorcerer();

    virtual void attack(Character* target) override;

private:
    int magicPower;
};

#endif /* SORCERER_H_ */
