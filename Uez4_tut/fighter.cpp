#include "fighter.h"
#include <iostream>
#include <cstdlib> // Für rand()


Fighter::Fighter(const std::string& name, int health, int gold, int armor, int magicResistance, int strength)
        : NPC(name, health, gold, armor, magicResistance), strength(strength) {}

Fighter::~Fighter() {}


void Fighter::attack(Character* target) {
    int damage = rand() % (10 - 5 + 1) + 5 + strength - target->getArmor();
    if (damage < 0) damage = 0;
    target->setHealth(target->getHealth() - damage);
    std::cout << getName() << " trifft " << target->getName() << " mit brutaler Stärke für " << damage << " Schadenspunkte!" << std::endl;
}