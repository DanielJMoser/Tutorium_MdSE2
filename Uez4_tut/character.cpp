#include "character.h"
#include "exceptions.h"
#include <iostream>
#include <cstdlib>

Character::Character(const std::string& name, int health, int gold, int armor, int magicResistance)
        : name(name), health(health), gold(gold), armor(armor), magicResistance(magicResistance) {
    // Das Inventar wird initialisiert und mit nullptr gefüllt
        for (int i = 0; i < 10; ++i) {
            inventory[i] = nullptr;
    }
}

Character::~Character() {
    std::cout << name << " verabschiedet sich und reitet in den Sonnenuntergang." << std::endl;
}

void Character::addInventoryItem(const Item* item) {
    for (int i = 0; i < 10; i++) {
        if (inventory[i] == nullptr) {
            // Hier wird ein neues Item erstellt und der Pointer darauf gespeichert
            inventory[i] = new Item(*item);
            return;
        }
    }
    // Wenn wir hier ankommen, dann ist das Inventar voll (sollte eigentlich nicht passieren)
    // Wie in Hero::fight() diskutiert, ist diese Exception ev. nicht the yellow from the egg
    // Diese spezifische Funktion steuern wir ja eh nur aus der main-Funktion an – wennst da dann
    // 100 Items ins Inventar steckst, dann schmeißts dir halt die Exception...
    throw inventory_full_exception("Inventory schon voll!");
}

Item* Character::retrieveRandomLoot() {
    for (int i = 0; i < 10; i++) {
        int index = rand() % 10;  // Random index
        if (inventory[index] != nullptr) {
            Item* loot = inventory[index];  // Wir holen uns den Pointer zum Loot
            inventory[index] = nullptr;     // Hier clearen wir den Slot
            return loot;                    // ...und da geben wir den Pointer direkt zurück
        }
    }
    return nullptr;  // Wenn kein Loot gefunden wurde, geben wir den nullptr zurück
}

// Eigentlich hätten wa die auch nutzen können, wo wir sie schon haben lol
Item Character::removeInventoryItem(int slot) {
    if (inventory[slot] != nullptr) {
        Item *item = inventory[slot];
        inventory[slot] = nullptr;
        return *item;
    }
    return Item();
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
