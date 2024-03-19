#include <iostream>
#include "hero.h"
#include "character.h"

int main() {
    Hero hero("Annina", 100, 500);
    Character enemy1("Matthias", 30, 20);
    Character enemy2("Pascal", 40, 30);

    Item sword("Schwert", 100);
    Item shield("Schild", 50);
    enemy1.addInventarItem(sword);
    enemy2.addInventarItem(shield);

    if (hero.fight(enemy1)) {
        std::cout << "Der Held hat gegen " << enemy1.getName() << " gewonnen!" << std::endl;
    }

    if (hero.fight(enemy2)) {
        std::cout << "Der Held hat gegen " << enemy2.getName() << " gewonnen!" << std::endl;
    }

    for (std::vector<Item>::size_type i = 0; i < hero.equipment.size(); i++) {
        hero.sellItem(i);
    }

    return 0;
}
