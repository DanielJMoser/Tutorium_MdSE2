#ifndef HERO_H_
#define HERO_H_

#include "character.h"

#define HERO_GEAR_SIZE  2

class Hero : public Character {
public:
    Hero(const std::string &name, int health, int gold, int armor, int magicResistance);

    virtual ~Hero();

    virtual void attack(Character *target) override;

    void sellItem(int index);

    bool fight(Character *enemy);

    int addInventoryItem(Item *item);

    Item *getInventoryItem(int i);

private:
    Item* gear[HERO_GEAR_SIZE]; // Annahme, dass Helden zwei Ausrüstungsgegenstände tragen können
};

#endif /* HERO_H_ */
