#include "character.h"
#include <iostream>
#include <cstdlib>


Character::Character(const std::string& name, int health, int gold, int armor, int magicResistance)
        : name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance) {
    for (int i = 0; i < 10; i++) {
        inventory[i].invalidate();
    }
}

Character::~Character() {
    std::cout << name << " verabschiedet sich und reitet in den Sonnenuntergang." << std::endl;
}

void Character::addInventoryItem(const Item& item) {
    for (int i = 0; i < 10; i++) {
        if (!inventory[i].isValid()) {
            inventory[i] = item;
            break;
        }
    }
}

Item Character::retrieveRandomLoot() {
    for (int i = 0; i < 10; i++) {
        int index = rand() % 10;
        if (inventory[index].isValid()) {
            Item loot = inventory[index];
            inventory[index].invalidate();
            return loot;
        }
    }
    return Item(); // Leeres Item, falls kein Loot vorhanden ist
}

Item Character::removeInventoryItem(int slot) {
    if (isInventorySlotValid(slot) && inventory[slot].isValid()) {
        Item item = inventory[slot];
        inventory[slot].invalidate();
        return item;
    }
    return Item();
}

bool Character::isInventorySlotValid(int slot) const {
    return slot >= 0 && slot < 10;
}

int Character::getHealth() const {
    return health;
}

void Character::setHealth(int health) {
    this->health = health;
}

int Character::getGold() const {
    return gold;
}

void Character::setGold(int gold) {
    this->gold = gold;
}

int Character::getArmor() const {
    return armor;
}

int Character::getMagicResistance() const {
    return magicResistance;
}

const std::string& Character::getName() const {
    return name;
}

std::ostream &operator<<(std::ostream &os, const Character &character) {
    os << character.name << ": Health = " << character.health << ", Gold = " << character.gold;
    return os;
}


