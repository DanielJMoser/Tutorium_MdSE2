
#ifndef TUT1_CHARACTER_H
#define TUT1_CHARACTER_H

#pragma once
#include <string>
#include <vector>
#include "item.h"

class Character {

public:
    Character(const std::string& name, int health, int gold);
    virtual ~Character();

    // Methoden
    virtual void attack(Character& target);
    void receiveItem(const Item& item);
    Item* getItem(int index);
    int addInventarItem(const Item& item);
    Item removeInventarItem(int slot);

    // Getter und Setter
    std::string getName() const;
    int getHealth() const;
    int getGold() const;
    void setHealth(int health);
    void setGold(int gold);
    int getInventorySize() const;

protected:
    std::string name;
    int health;
    int gold;
    std::vector<Item> inventory;
};

#endif //TUT1_CHARACTER_H
