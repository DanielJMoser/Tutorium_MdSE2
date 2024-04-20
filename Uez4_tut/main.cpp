#include "hero.h"
#include "sorcerer.h"
#include "fighter.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    // Initialisiert die Zufallszahlen
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // UNTERSCHIEDE ZWISCHEN TRY/CATCH UND IF/ELSE BEI EXCEPTIONS: //
    //                  ./exceptionGuide.md                        //

    try {
        // Erstellung der Heldin mit neuen Konstruktoren
        Hero hero("Frida", 300, 100, 5, 5); // Angenommene Werte für Armor und MagicResistance

        // Erstellung der Gegner
        Sorcerer pascal("Pascal", 100, 1000, 3, 8, 20); // Angenommene Werte für Armor, MagicResistance und MagicPower
        pascal.addInventoryItem(new Item("Diamant", 1000, true));
        pascal.addInventoryItem(new Item("Schwert", 10, true));
        pascal.addInventoryItem(new Item("Schild", 10, true));

        Fighter matthias("Matthias", 100, 100, 7, 2, 15); // Angenommene Werte für Armor, MagicResistance und Strength
        matthias.addInventoryItem(new Item("Rubin", 1000, true));
        matthias.addInventoryItem(new Item("Dolch", 10, true));
        matthias.addInventoryItem(new Item("Armbrust", 10, true));

        // Kämpfe
        if (hero.fight(&pascal)) {
            hero.fight(&matthias);
        }

        // Verkaufen von Gegenständen, falls die Heldin noch am Leben ist
        if (hero.getHealth() > 0) {
            for(int i = 0; i < CHARACTER_INVENTORY_SIZE; i++) {
                if (hero.getInventoryItem(i) != nullptr) {
                    hero.sellItem(i);
                }
            }
        }

    }
    catch (const std::exception& e) {
        std::cout << "Ein Fehler ist aufgetreten: " << e.what() << std::endl;
    }

    return 0;
}
