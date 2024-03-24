#include "hero.h"
#include <cstdlib>
#include <iostream>


Hero::Hero(const std::string &name, int health, int gold, int armor, int magicResistance) :
Character(name, health,
          gold, armor,
          magicResistance) {
}

Hero::~Hero() {}


void Hero::attack(Character* target) {
	int damage = rand() % (25 - 15 + 1) + 15 - target->getArmor();
    if (damage < 0) damage = 0;
	std::cout << name << " trifft " << target->getName() << " fuer " << damage << " Lebenspunkte!" << std::endl;
    target->setHealth(target->getHealth() - damage);
}

void Hero::sellItem(int index) {
	if (index >= 0 && index < 10) {
		if (inventory[index].isValid()) {
			gold += inventory[index].getGoldValue();
			inventory[index].invalidate();
			std::cout << "Gegenstand " << inventory[index].getName() << " wurde verkauft. "
					<< name << " besitzt nun " << gold << " Gold." << std::endl;
		}
	}
}

bool Hero::fight(Character* enemy) {
    while (health > 0 && enemy->getHealth() > 0) {
        attack(enemy);
        if (enemy->getHealth() > 0) {
            enemy->attack(this);
        }
    }
    if (health > 0) {
        std::cout << name << " hat gewonnen!" << std::endl;
        Item loot = enemy->retrieveRandomLoot();

        if (loot.isValid()) {
            int added = addInventoryItem(loot);
            if (added != -1) {
                std::cout << getName() << "erbeutet " << loot.getName() << "!" << std::endl;
            } else {
                std::cout << "Kein Platz im Inventar für " << loot.getName() << "." << std::endl;
            }
        } else {
            std::cout << enemy->getName() << " hat keinen lootbaren Gegenstand." << std::endl;
        }
        return true;

    } else {
        return false;
    }
}



int Hero::addInventoryItem(const Item &item) {
    for (int i = 0; i < 10; i++) {
        if (!inventory[i].isValid()) {
            inventory[i] = item;
            return i;
        }
    }
    return -1;
}