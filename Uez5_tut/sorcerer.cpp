#include "sorcerer.h"
#include <iostream>
#include <cstdlib> // Für rand()

Sorcerer::Sorcerer(const std::string& name, int health, int gold, int armor, int magicResistance, int magicPower)
        : NPC(name, health, gold, armor, magicResistance), magicPower(magicPower) {}

Sorcerer::~Sorcerer() {}

void Sorcerer::attack(Character* target) {
    int damage = rand() % (10 - 5 + 1) + 5 + magicPower - target->getMagicResistance();
    if (damage < 0) damage = 0;
    target->setHealth(target->getHealth() - damage);
    std::cout << getName() << " trifft " << target->getName() << " mit einem Zauberspruch für " << damage << " Schadenspunkte!" << std::endl;
}

