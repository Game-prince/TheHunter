#ifndef INVENTORY_C
#define INVENTORY_C

#include <iostream>
#include <map>
#include "Weapon.cpp"

class Inventory {
private:
	std::map<std::string, Weapon*> weapons;
public:
	Inventory() {}
	~Inventory() {
		for (auto it = weapons.begin(); it != weapons.end(); it++) {
			delete it->second;
		}
		weapons.clear();
	}

	void showInventory() {
		std::cout << "You have nothing in your inventory\n";
	}

	void addItem(Weapon *weapon) {
		weapons[weapon->getName()] = weapon;
		std::cout << weapon->getName() << " has been added to your inventory\n";
	}

	void removeItem(Weapon *weapon) {
		weapons.erase(weapon->getName());
		std::cout << weapon->getName() << " has been removed from your inventory\n";
	}

	void display() {
		std::cout << std::endl;

		if (weapons.empty()) {
			std::cout << "You have nothing in your inventory\n" << std::endl;
			return;
		}
		std::cout << "You have the following items in your inventory:\n";
		for (auto it = weapons.begin(); it != weapons.end(); it++) {
			std::cout << it->first << "\n";
		}

		std::cout << std::endl;
	}
};

#endif // !INVENTORY_C
