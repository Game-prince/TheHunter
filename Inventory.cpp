#ifndef INVENTORY_C
#define INVENTORY_C

#include <iostream>
#include <map>
#include "Equipable.cpp"

class Inventory {
private:
	std::map<std::string, Equipable*> equipables;
public:
	Inventory() {}
	~Inventory() {
		for (auto it = equipables.begin(); it != equipables.end(); it++) {
			delete it->second;
		}
		equipables.clear();
	}

	void addItem(Equipable* equipable) {
		equipables[equipable->getName()] = equipable;
		std::cout << equipable->getName() << " has been added to your inventory\n";
	}

	void removeItem(Equipable* item) {
		std::string name = item->getName();
		if (equipables.find(name) == equipables.end()) {
			std::cout << "You don't have " << name << " in your inventory\n";
			return;
		}
		delete equipables[name];
		equipables.erase(name);
		std::cout << name << " has been removed from your inventory\n";
	}

	void display() {
		std::cout << std::endl;

		if (equipables.empty()) {
			std::cout << "You have nothing in your inventory\n" << std::endl;
			return;
		}
		std::cout << "You have the following items in your inventory:\n";
		int count = 1;
		for (auto it = equipables.begin(); it != equipables.end(); it++) {
			std::cout << count << ". ";
			std::cout << it->first << "\n";
			count++;
		}
		std::cout << std::endl;
	}

	int size() { return (int)this->equipables.size(); }
};

#endif // !INVENTORY_C
