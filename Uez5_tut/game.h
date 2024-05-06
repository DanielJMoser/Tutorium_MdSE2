#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <unordered_map>
#include <memory>
#include "character.h"

class Game {
private:
    std::unordered_map<std::string, std::shared_ptr<Character>> characters;

public:
    Game();
    ~Game();

    // Änderung: Überladen der Methode addCharacter für vereinfachte Nutzung
    void addCharacter(const std::string& name, int health, int gold, int armor, int magicResistance);

    // Methode für das Hinzufügen von Charakteren mit vordefinierten shared_ptr
    void addCharacter(const std::string& name, std::shared_ptr<Character> character);

    void play();
    void cleanupDeadCharacters();
};

#endif /* GAME_H_ */
