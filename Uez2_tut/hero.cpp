#include <iostream>
#include <cstring>
#include "hero.h"
#include "character.h"



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

int Hero::addEquipmentItem(const Item &item) {
    if (equipment.size() < 2) {
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
    return Item(); // Ungültiges Item
}

bool Hero::fight(Character &enemy) {
    while (health > 0 && enemy.getHealth() > 0) {
        attack(enemy);
        if (enemy.getHealth() <= 0) {
            std::cout << enemy.getName() << " fiel in Ohnmacht!" << std::endl;
            if (enemy.getInventorySize() > 0) {
                int slot = rand() % enemy.getInventorySize();
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











/*
void initHero(Hero_t* hero, const char* name, int health, int gold) {
    strncpy(hero->name, name, sizeof(hero->name) - 1);
    hero->name[sizeof(hero->name) - 1] = '\0';
    hero->health = health;
    hero->gold = gold;

    for (int i = 0; i < 10; ++i) {
        invalidateItem(&(hero->inventory[i]));
    }
    for (int i = 0; i < 2; ++i) {
        invalidateItem(&(hero->equipment[i]));
    }
}

void attack(Hero_t* hero, Character_t* enemy) {
    int damage = rand() % 11 + 15;
    enemy->health -= damage;
    std::cout << hero->name << " trifft" << enemy->name << " fuer" << damage << " Lebenspunke!" <<std::endl;
}


bool fight(Hero_t* hero, Character_t* enemy) {
    while (hero->health > 0 && enemy->health >0) {
        attack(hero, enemy);
        if (enemy->health <= 0) {
            std::cout << enemy->name << " fiel in Ohnmacht!" <<std::endl;
            return true;
        }
        attack(enemy, hero);
        if (hero->health <= 0) {
            std::cout << hero->name << " fiel in Ohnmacht!" <<std::endl;
            return false;
        }
    }
    return false;
}

void sellItem(Hero_t* hero, int index) {
    if (hero->inventory[index].isValid) {
        hero->gold += hero->inventory[index].value;
        std::cout << "Gegenstand " << hero->inventory[index].name << " wurde verkauft. "
        << hero->name << " besitz nun " << hero->gold << " Gold." << std::endl;
        invalidateItem(&hero->inventory[index]);
    }
}
 */