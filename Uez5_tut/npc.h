#ifndef NPC_H_
#define NPC_H_

#include "character.h"

// NPC ist eine abstrakte Basisklasse für alle Nicht-Spieler-Charaktere
class NPC : public Character {
public:
    NPC(const std::string& name, int health, int gold, int armor, int magicResistance);
    virtual ~NPC();

    virtual void attack(Character* target) = 0;
};

#endif /* NPC_H_ */
