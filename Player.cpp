#ifndef PLAYER_C
#define PLAYER_C

#include <iostream>
#include "Inventory.cpp"

class Player {
private:
	int health, mana, level, attack, defence, experience, gold, baseAttack, baseDefence;
	Inventory* inventory;
public:
	Player() {
		this->health = 100;
		this->mana = 100;
		this->level = 1;
		this->baseAttack = 10;
		this->baseDefence = 10;
		this->attack = 10;
		this->defence = 10;
		this->experience = 0;
		this->gold = 0;

		inventory = new Inventory();
	}
	~Player() {}

	void showStats() const {
		std::cout << std::endl;

		std::cout << "Your stats are:\n";
		std::cout << "Health: " << health << "\n";
		std::cout << "Mana: " << mana << "\n";
		std::cout << "Level: " << level << "\n";
		std::cout << "Attack: " << attack << "\n";
		std::cout << "Defence: " << defence << "\n";
		std::cout << "Experience: " << experience << "\n";
		std::cout << "Gold: " << gold << "\n";

		std::cout << std::endl;
	}

	// ============= INVENTORY ===========
	void addItem(Weapon* weapon) {
		inventory->addItem(weapon);
	}
	void removeItem(Weapon* weapon) {
		inventory->removeItem(weapon);
	}
	void showInvetory() {
		inventory->display();
	}

	// ============= GOLD ===========
	int getGold() const {
		return gold;
	}

	void addGold(int gold) {
		this->gold += gold;
		std::cout << "You received " << gold << " gold\n";
	}

	void removeGold(int gold) {
		this->gold -= gold;
		std::cout << "You lost " << gold << " gold\n";
	}

	// ============= EXPERIENCE ===========
	int getExperience() const {
		return experience;
	}
	void addExperience(int experience) {
		this->experience += experience;
		std::cout << "You received " << experience << " experience\n";
	}
	void removeExperience(int experience) {
		this->experience -= experience;
		std::cout << "You lost " << experience << " experience\n";
	}

	// ============= HEALTH ===========
	int getHealth() const {
		return health;
	}
	void addHealth(int health) {
		this->health += health;
		std::cout << "You received " << health << " health\n";
	}
	void removeHealth(int health) {
		this->health -= health;
		std::cout << "You lost " << health << " health\n";
	}

	// ============= MANA ===========
	int getMana() const {
		return mana;
	}

	void addMana(int mana) {
		this->mana += mana;
		std::cout << "You received " << mana << " mana\n";
	}

	void removeMana(int mana) {
		this->mana -= mana;
		std::cout << "You lost " << mana << " mana\n";
	}

	// ============= Attack ===========
	int getAttack() const {
		return attack;
	}
	void addAttack(int attack) {
		this->attack += attack;
		std::cout << "You received " << attack << " attack\n";
	}

	void removeAttack(int attack) {
		this->attack -= attack;
		std::cout << "You lost " << attack << " attack\n";
	}

	// ============= Defence ===========
	int getDefence() const {
		return defence;
	}

	void addDefence(int defence) {
		this->defence += defence;
		std::cout << "You received " << defence << " defence\n";
	}

	void removeDefence(int defence) {
		this->defence -= defence;
		std::cout << "You lost " << defence << " defence\n";
	}

	// ============= LEVEL ===========
	int getLevel() const {
		return level;
	}

	void addLevel(int level) {
		this->level += level;
		std::cout << "You received " << level << " level\n";
	}

	void removeLevel(int level) {
		this->level -= level;
		std::cout << "You lost " << level << " level\n";
	}

};

#endif // !PLAYER_C
