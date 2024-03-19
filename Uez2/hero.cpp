#include "hero.h"
#include <iostream>

Hero::Hero(const std::string& name, int health, int gold) : Character(name, health, gold) {}

Hero::~Hero() {}

void Hero::attack(Character& target) {
    Character::attack(target); // Verwendung der Basis-Klassen-Methode
}

void Hero::sellItem(int index) {
    Item* item = getItem(index);
    if (item && item->isValid()) {
        gold += item->getValue();
        std::cout << "Gegenstand " << item->getName() << " wurde verkauft. " << name << " besitzt nun " << gold << " Gold." << std::endl;
        item->invalidate();
    }
}

int Hero::addEquipmentItem(const Item& item) {
    if (equipment.size() < 2) { // Angenommene maximale Ausrüstungsgröße
        equipment.push_back(item);
        return equipment.size() - 1;
    }
    return -1;
}

Item Hero::removeEquipmentItem(int slot) {
    if (slot >= 0 && static_cast<std::vector<Item>::size_type>(slot) < equipment.size()) {
        Item item = equipment[slot];
        equipment.erase(equipment.begin() + slot);
        return item;
    }
    return Item(); // Rückgabe eines ungültigen Items
}

bool Hero::fight(Character& enemy) {
    while (health > 0 && enemy.getHealth() > 0) {
        attack(enemy);
        if (enemy.getHealth() <= 0) {
            std::cout << enemy.getName() << " fiel in Ohnmacht!" << std::endl;
            // Stellen Sie sicher, dass das Inventar des Feindes nicht leer ist
            if (enemy.getInventorySize() > 0) {
                // Zufälliger Gegenstand vom Feind übernehmen
                int slot = rand() % enemy.getInventorySize(); // Zufälliger Slot
                Item stolenItem = enemy.removeInventarItem(slot);
                if (addInventarItem(stolenItem) == -1) {
                    std::cout << "Kein Platz mehr vorhanden!" << std::endl;
                }
            }
            return true;
        }
        enemy.attack(*this);
        if (health <= 0) {
            std::cout << name << " fiel in Ohnmacht!" << std::endl;
            return false;
        }
    }
    return false;
}

