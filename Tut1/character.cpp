#include <cstring>
#include <iostream>
#include "character.h"


void initCharacter(Character_t* character, const char* name, int health, int gold) {
    strncpy(character->name, name, sizeof(character->name) - 1);
    character->name[sizeof(character->name) - 1] = '\0';
    character->health = health;
    character->gold = gold;

    for (int i = 0; i < 10; ++i) {
        invalidateItem(&(character->inventory[i]));
    }
}

void attack(Character_t* character, Hero_t* hero) {
    int damage = rand() % 11 + 5;
    hero->health -= damage;
    std::cout << character->name << " trifft" << hero->name << " fuer" << damage << " Lebenspunke!" <<std::endl;
}