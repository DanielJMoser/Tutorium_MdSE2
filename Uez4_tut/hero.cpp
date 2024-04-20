#include "hero.h"
#include <iostream>
#include <cstdlib> // Für rand()

#include "exceptions.h"


Hero::Hero(const std::string& name, int health, int gold, int armor, int magicResistance)
        : Character(name, health, gold, armor, magicResistance) {}

Hero::~Hero() {
}

void Hero::attack(Character* target) {
    int damage = rand() % (25 - 15 + 1) + 15 - target->getArmor();
    if (damage < 0) damage = 0;
    target->setHealth(target->getHealth() - damage);
    std::cout << getName() << " trifft " << target->getName() << " fuer " << damage << " Schadenspunkte!" << std::endl;
}

void Hero::sellItem(int index) {
    // Wir werfen eine Exception, wenn der Index außerhalb des gültigen Bereichs liegt.
    // Sollt eh nicht passieren, weil wir dies ja schon in der main-Funktion sicherstellen.
    // Aber hey, falls doch, doppelt hält besser.
    if (index < 0 || index >= 10) {
        throw index_invalid_exception("Index außerhalb der Range des Inventars!");
    }
    // Wir werfen eine Exception, wenn der Gegenstand ungültig ist.
    // Ebenso schon in der main-Funktion gecheckt
    if (inventory[index] == nullptr) {
        throw item_invalid_exception("Versuch, ein ungültiges Item zu verkaufen!");
    }
    // Wir werfen eine Exception, wenn der Wert des Gegenstands negativ ist.
    if (inventory[index]->getGoldValue() < 0) {
        throw value_invalid_exception("Versuch, ein Item mit Wert < 0 zu verkaufen! (koa guats Gschaeft...)");
    }
    setGold(getGold() + inventory[index]->getGoldValue());
    std::cout << "Gegenstand " << inventory[index]->getName() << " verkauft für "
              << inventory[index]->getGoldValue() << " Gold." << std::endl;
    // Löschen des Gegenstands aus dem Inventar
    delete inventory[index];
    inventory[index] = nullptr;
}


bool Hero::fight(Character* enemy) {
    while (getHealth() > 0 && enemy->getHealth() > 0) {
        attack(enemy);
        if (enemy->getHealth() > 0) {
            enemy->attack(this);
        }
    }

    if (getHealth() > 0) {  // If hero wins
        std::cout << getName() << " hat gewonnen und erhält einen Gegenstand aus " << enemy->getName() << "'s Inventar." << std::endl;
        Item* loot = enemy->retrieveRandomLoot();
        if (loot != nullptr) {
            int added = addInventoryItem(loot);
            if (added != -1) {
                std::cout << getName() << " erbeutet " << loot->getName() << "." << std::endl;
            } else {
                // TODO: Ist das Inventar voll, so wird der Gegenstand gelöscht.
                std::cout << "Kein Platz im Inventar für " << loot->getName() << "." << std::endl;
                delete loot;
            }
        } else {
            std::cout << enemy->getName() << " hat keinen lootbaren Gegenstand." << std::endl;
        }
        return true;
    } else {
        return false;
    }
}



int Hero::addInventoryItem(Item* item) {
    for (int i = 0; i < 10; i++) {
        if (inventory[i] == nullptr) {
            inventory[i] = item;
            return i;
        }
    }
    // Ist das Inventar voll, werfen wir eine Exception.
    // Ob des sinnvoll is, naja... diskutierbar.
    // In der Hero::fight-Methode wird der Gegenstand einfach gelöscht, was vielleicht
    // die bessere Lösung wäre.
    // Aber wir wollen ja Exceptions schmeißen... Ich hab die obige Stelle mal mit
    // TODO
    // markiert, damit sie ins Auge sticht.
    throw inventory_full_exception("No space left in inventory.");
}

Item *Hero::getInventoryItem(int i) {
    return inventory[i];
}

