#include "game.h"
#include <iostream>

int main() {
    Game game;

    // Hinzufügen von Charakteren direkt mit spezifizierten Attributen
    game.addCharacter("Zauberer Pascal", 100, 50, 5, 10);
    game.addCharacter("Kämpfer Matthias", 150, 100, 20, 5);

    // Start des Spiels
    game.play();

    return 0;
}
