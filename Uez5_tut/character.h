#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include <vector>
#include <memory>  // Für std::shared_ptr
#include "item.h"

class Character {
public:
    Character(const std::string& name, int health, int gold, int armor, int magicResistance);
    virtual ~Character();

    virtual void attack(Character* target) = 0;
    std::shared_ptr<Item> retrieveRandomLoot();
    void addInventoryItem(std::shared_ptr<Item> item);
    std::shared_ptr<Item> removeInventoryItem(int slot);

    int getHealth() const;
    void setHealth(int health);
    int getGold() const;
    void setGold(int gold);
    int getArmor() const;
    int getMagicResistance() const;
    const std::string& getName() const;

    friend std::ostream& operator<<(std::ostream& os, const Character& character);

protected:
    std::string name;
    int health;
    int gold;
    int armor;
    int magicResistance;
    std::vector<std::shared_ptr<Item>> inventory;  // Smart Pointer für automatische Speicherverwaltung

private:
};

#endif /* CHARACTER_H_ */