#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include "item.h"

#define CHARACTER_INVENTORY_SIZE    10

class Character {
public:
    Character(const std::string& name, int health, int gold, int armor, int magicResistance);
    virtual ~Character();

    virtual void attack(Character* target) = 0;
    Item *retrieveRandomLoot();
    void addInventoryItem(const Item* item);
    Item removeInventoryItem(int slot);

    // Getter und Setter
    int getHealth() const;
    void setHealth(int health);
    int getGold() const;
    void setGold(int gold);
    int getArmor() const;
    int getMagicResistance() const;
    const std::string& getName() const;

    // Überladung des Output-Stream Operators
    friend std::ostream& operator<<(std::ostream& os, const Character& character);

protected:
    std::string name;
    int health;
    int gold;
    int armor;
    int magicResistance;
    Item *inventory[CHARACTER_INVENTORY_SIZE];

private:
};

#endif /* CHARACTER_H_ */