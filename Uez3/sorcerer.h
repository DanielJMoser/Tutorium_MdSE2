//
// Created by danielm on 24.03.24.
//

#ifndef UEZ3_SORCERER_H
#define UEZ3_SORCERER_H

#include "npc.h"

class Sorcerer : public NPC {
public:
    Sorcerer(const std::string& name, int health, int gold, int armor, int magicResistance, int magicPower);
    virtual ~Sorcerer();

    virtual void attack(Character* target) override;

private:
    int magicPower;
};


#endif //UEZ3_SORCERER_H
