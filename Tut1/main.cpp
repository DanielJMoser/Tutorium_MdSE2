#include <iostream>
#include "hero.h"
#include "character.h"
#include "item.h"



int main() {

    srand(time(nullptr));

    Hero_t hero;
    initHero(&hero, "Annina", 300, 100);

    Character_t enemy1, enemy2;
    initCharacter(&enemy1, "Matthias", 50, 20);
    initCharacter(&enemy2, "Pascal", 100, 30);

    if (fight(&hero, &enemy1)) {
        std::cout << "Annina hat noch " << hero.health << " Lebenspunkte uebrig." << std::endl;
        Item_t loot;
        initItem(&loot, "Der Eine Ring", 10);
        hero.inventory[0] = loot;
        std::cout << "Neuer Gegenstand im Inventar." << std::endl;
    }

    if (fight(&hero, &enemy2)) {
        std::cout << "Annina hat noch " << hero.health << " Lebenspunkte uebrig." << std::endl;
        Item_t loot;
        initItem(&loot, "Zauberstab", 100);
        hero.inventory[1] = loot;
        std::cout << "Neuer Gegenstand im Inventar." << std::endl;
    }

    for (int i = 0; i < 10; ++i) {
        if (hero.inventory[i].isValid) {
            sellItem(&hero, i);
        }
    }

    return 0;
}
