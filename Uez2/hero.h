
#ifndef TUT_UEZ1_HERO_H
#define TUT_UEZ1_HERO_H

#pragma once
#include "character.h"
#include <vector>

class Hero : public Character {
public:
    Hero(const std::string& name, int health, int gold);
    ~Hero();

    // Zusätzliche Methoden spezifisch für Hero
    // Attribute für die Ausrüstung
    std::vector<Item> equipment;

    // Methoden hinzufügen
    int addEquipmentItem(const Item& item);
    Item removeEquipmentItem(int slot);
    bool fight(Character& enemy); // Anpassung der Methode
    void sellItem(int index);

    // Erweiterung der vorhandenen Methoden
    void attack(Character& target) override;
};

#endif //TUT_UEZ1_HERO_H
