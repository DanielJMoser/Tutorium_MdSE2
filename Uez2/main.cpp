#include "hero.h"
#include "character.h"
#include <iostream>

int main() {
    Hero hero("Lara", 100, 500);
    Character enemy1("Goblin", 30, 10);
    Character enemy2("Orc", 45, 15);

    // Erstellen Sie einige Items für den Kampf
    Item sword("Schwert", 100);
    Item shield("Schild", 50);
    enemy1.addInventarItem(sword);
    enemy2.addInventarItem(shield);

    // Kämpfe
    if (hero.fight(enemy1)) {
        std::cout << "Der Held hat gegen " << enemy1.getName() << " gewonnen!" << std::endl;
    }

    if (hero.fight(enemy2)) {
        std::cout << "Der Held hat gegen " << enemy2.getName() << " gewonnen!" << std::endl;
    }

    // Verkaufe alle Ausrüstungsgegenstände
    for (std::vector<Item>::size_type i = 0; i < hero.equipment.size(); ++i) {
        hero.sellItem(i);
    }

    return 0;
}
