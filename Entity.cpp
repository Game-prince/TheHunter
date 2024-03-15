#ifndef ENTITY_C
#define ENTITY_C

#include <iostream>
#include "Inventory.cpp"

class Entity {
private:
	std::string name;
	int health, mana, level, attack, defence, experience, gold, baseAttack, baseDefence;
	Inventory* inventory;
public:
	Entity() {
		this->name = "Player";
		this->health = 0;
		this->mana = 0;
		this->level = 1;
		this->baseAttack = 0;
		this->baseDefence = 0;
		this->attack = 0;
		this->defence = 0;
		this->experience = 0;
		this->gold = 0;

		inventory = new Inventory();
	}

	Entity(std::string name,int health, int mana, int baseAttack, int baseDefence) {
		this->name = name;
		this->health = health;
		this->mana = mana;
		this->level = 1;
		this->baseAttack = baseAttack;
		this->baseDefence = baseDefence;
		this->attack = baseAttack;
		this->defence = baseDefence;
		this->experience = 0;
		this->gold = 0;

		inventory = new Inventory();
	}

	~Entity() {
		delete inventory;
	}

	void showStats() const {
		std::cout << std::endl;

		std::cout << this->name << "'s stats:\n";
		std::cout << "========= stats ==========\n";
		std::cout << "Health: " << health << "\n";
		std::cout << "Mana: " << mana << "\n";
		std::cout << "Level: " << level << "\n";
		std::cout << "Attack: " << attack << "\n";
		std::cout << "Defence: " << defence << "\n";
		std::cout << "Experience: " << experience << "\n";
		std::cout << "Gold: " << gold << "\n";

		std::cout << std::endl;
	}

	// ============= NAME ===========
	std::string getName() const {
		return name;
	}


	// ============= INVENTORY ===========
	void addItem(Weapon* weapon) {
		inventory->addItem(weapon);
	}
	void removeItem(Weapon* weapon) {
		inventory->removeItem(weapon);
	}
	void showInventory() {
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

	void doAttack(Entity* entity) {
		entity->dealsDamage(this->attack);
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

	void dealsDamage(int damage) {
		if (this->health <= damage) {
			this->health = 0;
		}
		else {
			this->health -= damage;
		}
		std::cout << "You received " << damage << " damage\n";
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

#endif // !ENTITY_C
