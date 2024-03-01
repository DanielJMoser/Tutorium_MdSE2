
#ifndef TUT1_HERO_H
#define TUT1_HERO_H

#include "item.h"
#include "character.h"

struct Item_t;
struct Character_t;

struct Hero_t {
    char name[50];
    int health;
    int gold;
    Item_t inventory[10];
    Item_t equipment[2];
};

void initHero(Hero_t* hero, const char* name, int health, int gold);
void attack(Hero_t* hero, Character_t* enemy);
bool fight(Hero_t* hero, Character_t* enemy);
void sellItem(Hero_t* hero, int index);


#endif //TUT1_HERO_H
