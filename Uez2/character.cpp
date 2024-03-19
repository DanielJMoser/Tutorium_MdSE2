#include "character.h"
#include <iostream>

Character::Character(const std::string& name, int health, int gold)
        : name(name), health(health), gold(gold) {}

Character::~Character() {}

void Character::attack(Character& target) {
    int damage = rand() % 11 + 5; // Beispiel für zufälligen Schaden
    target.health -= damage;
    std::cout << name << " trifft " << target.name << " für " << damage << " Lebenspunkte!" << std::endl;
}

void Character::receiveItem(const Item& item) {
    inventory.push_back(item);
}

Item* Character::getItem(int index) {
    if (index >= 0 && static_cast<std::vector<Item>::size_type>(index) < inventory.size()) {
        return &inventory[index];
    }
    return nullptr;
}

int Character::addInventarItem(const Item& item) {
    if (inventory.size() < 10) { // Angenommene maximale Inventargröße
        inventory.push_back(item);
        return inventory.size() - 1; // Rückgabe des Slotplatzes
    }
    return -1; // Kein Platz mehr
}

Item Character::removeInventarItem(int slot) {
    if (slot >= 0 && static_cast<std::vector<Item>::size_type>(slot) < inventory.size()) {
        Item item = inventory[slot];
        inventory.erase(inventory.begin() + slot);
        return item;
    }
    return Item(); // Rückgabe eines ungültigen Items
}


std::string Character::getName() const { return name; }
int Character::getHealth() const { return health; }
int Character::getGold() const { return gold; }
void Character::setHealth(int health) { this->health = health; }
void Character::setGold(int gold) { this->gold = gold; }
int Character::getInventorySize() const { return inventory.size(); }