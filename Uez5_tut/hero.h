#ifndef HERO_H_
#define HERO_H_

#include "character.h"
#include <vector>
#include <memory>

class Hero : public Character {
public:
    Hero(const std::string &name, int health, int gold, int armor, int magicResistance);
    virtual ~Hero();
    virtual void attack(Character *target) override;

    void sellItem(int index);
    bool fight(Character *enemy);
    int addInventoryItem(std::shared_ptr<Item> item);
    std::shared_ptr<Item> getInventoryItem(int index);

private:
    std::vector<std::shared_ptr<Item>> gear; // Dynamisches Array für die Ausrüstung, verwaltet als Smart Pointer
};

#endif /* HERO_H_ */
