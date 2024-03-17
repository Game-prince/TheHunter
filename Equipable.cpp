#ifndef EQUIPABLE_C
#define EQUIPABLE_C

#include <iostream>

class Equipable {
private:
	int attack, durability, value;
	std::string name, type, rarity, slot, description;
public:

	Equipable(std::string name, std::string type, int attack, int durability, int value, std::string rarity, std::string slot, std::string description) {
		this->name = name;
		this->type = type;
		this->attack = attack;
		this->durability = durability;
		this->value = value;
		this->rarity = rarity;
		this->slot = slot;
		this->description = description;
	}

	void viewDetails() const {
		std::cout << "Name: " << name << std::endl;
		std::cout << "Type: " << type << std::endl;
		std::cout << "Attack: " << attack << std::endl;
		std::cout << "Durability: " << durability << std::endl;
		std::cout << "Value: " << value << std::endl;
		std::cout << "Rarity: " << rarity << std::endl;
		std::cout << "Slot: " << slot << std::endl;
		std::cout << "Description: " << description << std::endl;
	}

	std::string getName() { return name; }
	std::string getType() { return type; }
	int getAttack() const { return attack; }
	int getDurability() const { return durability; }
	int getValue() const { return value; }
	std::string getRarity() { return rarity; }
	std::string getSlot() { return slot; }
	std::string getDescription() { return description; }
};

#endif // !EQUIPABLE_C
