#include <iostream>
#include <cstring>
#include "hero.h"
#include "character.h"

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