#include "character.h"
#include "exceptions.h"
#include <iostream>
#include <cstdlib>

Character::Character(const std::string& name, int health, int gold, int armor, int magicResistance)
    : name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance) {}

Character::~Character() {
    std::cout << name << " verabschiedet sich und reitet in den Sonnenuntergang." << std::endl;
    // Keine manuelle Speicherfreigabe mehr nötig, Smart Pointer kümmern sich darum
}

void Character::addInventoryItem(std::shared_ptr<Item> item) {
    inventory.push_back(item);  // Hinzufügen eines shared_ptr zum Vector
}

std::shared_ptr<Item> Character::removeInventoryItem(int slot) {
    if (slot < 0 || slot >= inventory.size()) {
        throw index_invalid_exception("Slot index out of range");
    }
    std::shared_ptr<Item> item = inventory[slot];
    inventory.erase(inventory.begin() + slot);
    return item;
}

std::shared_ptr<Item> Character::retrieveRandomLoot() {
    if (inventory.empty()) return nullptr;
    int index = rand() % inventory.size();  // Anpassung an die Größe des Vectors
    std::shared_ptr<Item> loot = inventory[index];
    inventory.erase(inventory.begin() + index);  // Entfernen des Items aus dem Vector
    return loot;
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

std::ostream& operator<<(std::ostream& os, const Character& character) {
    os << character.name << ": Health = " << character.health << ", Gold = " << character.gold;
    return os;
}