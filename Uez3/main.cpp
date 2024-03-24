#include "hero.h"
#include "sorcerer.h"
#include "fighter.h"
#include <cstdlib>
#include <ctime>

int main() {
    // Initialisiert die Zufallszahlen
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Erstellung der Heldin mit neuen Konstruktoren
    Hero hero("Frida", 300, 100, 5, 5); // Angenommene Werte für Armor und MagicResistance

    // Erstellung der Gegner
    Sorcerer pascal("Pascal", 100, 1000, 3, 8, 20); // Angenommene Werte für Armor, MagicResistance und MagicPower
    pascal.addInventoryItem(Item("Diamant", 1000, true));
    pascal.addInventoryItem(Item("Schwert", 10, true));
    pascal.addInventoryItem(Item("Schild", 10, true));

    Fighter matthias("Matthias", 100, 100, 7, 2, 15); // Angenommene Werte für Armor, MagicResistance und Strength
    matthias.addInventoryItem(Item("Rubin", 1000, true));
    matthias.addInventoryItem(Item("Dolch", 10, true));
    matthias.addInventoryItem(Item("Armbrust", 10, true));

    // Kämpfe
    if (hero.fight(&pascal)) {
        hero.fight(&matthias);
    }

    // Verkaufen von Gegenständen, falls die Heldin noch am Leben ist
    if (hero.getHealth() > 0) {
        for (int i = 0; i < 10; i++) {
            hero.sellItem(i);
        }
    }

    return 0;
}
