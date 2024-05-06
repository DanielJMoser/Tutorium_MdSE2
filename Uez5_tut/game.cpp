#include "game.h"
#include <memory>
#include <iostream>

Game::Game() {
    std::cout << "Spiel gestartet." << std::endl;
}

Game::~Game() {
    std::cout << "Spiel beendet und alle Charaktere zerstört." << std::endl;
}

void Game::addCharacter(const std::string& name, int health, int gold, int armor, int magicResistance) {
    // Erzeugen und Hinzufügen eines neuen Charakters mit make_shared
    characters[name] = std::make_shared<Character>(name, health, gold, armor, magicResistance);
    std::cout << "Charakter " << name << " hinzugefügt." << std::endl;
}
void Game::play() {
    if (characters.size() < 2) {
        std::cout << "Nicht genügend Charaktere zum Starten des Spiels." << std::endl;
        return;
    }

    auto it = characters.begin();
    std::shared_ptr<Character> hero = it->second;
    it++;
    std::shared_ptr<Character> enemy = it->second;

    // Simuliere einen Kampf zwischen zwei Charakteren
    while (hero->getHealth() > 0 && enemy->getHealth() > 0) {
        hero->attack(enemy.get());
        if (enemy->getHealth() > 0) {
            enemy->attack(hero.get());
        }
    }

    if (hero->getHealth() > 0) {
        std::cout << hero->getName() << " hat gewonnen." << std::endl;
    } else {
        std::cout << enemy->getName() << " hat gewonnen." << std::endl;
    }

    cleanupDeadCharacters();
}

void Game::cleanupDeadCharacters() {
    for (auto it = characters.begin(); it != characters.end(); ) {
        if (it->second->getHealth() <= 0) {
            std::cout << it->second->getName() << " wird aus dem Spiel entfernt." << std::endl;
            it = characters.erase(it); // Korrekte Nutzung von erase für Smart Pointer
        } else {
            ++it;
        }
    }
}
