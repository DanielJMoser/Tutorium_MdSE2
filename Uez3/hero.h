#ifndef HERO_H_
#define HERO_H_

#include "character.h"



class Hero : public Character {
public:

    Hero(const std::string& name, int health, int gold, int armor, int magicResistance);

    virtual ~Hero();

    virtual void attack(Character* target) override;

	void sellItem(int index);

	bool fight(Character* enemy);

    int addInventoryItem(const Item& item);



	int getGold() const {
		return gold;
	}

	void setGold(int gold) {
		this->gold = gold;
	}

	int getHealth() const {
		return health;
	}

	void setHealth(int health) {
		this->health = health;
	}


	const std::string& getName() const {
		return name;
	}

	void setName(const std::string &name) {
		this->name = name;
	}

private:
	Item gear[2];
};


#endif /* HERO_H_ */
