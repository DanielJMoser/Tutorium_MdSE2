
#ifndef TUT1_CHARACTER_H
#define TUT1_CHARACTER_H

#include "item.h"
#include "hero.h"

struct Item_t;
struct Hero_t;

struct Character_t {
    char name[50];
    int health;
    int gold;
    Item_t inventory[10];
};

void initCharacter(Character_t* character, const char* name, int health, int gold);
void attack(Character_t* character, Hero_t* hero);

#endif //TUT1_CHARACTER_H
