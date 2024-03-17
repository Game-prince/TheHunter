#ifndef EQUIPABLE_C
#define EQUIPABLE_C

#include <iostream>

class Equipable {
private:
	int DMG, durability, value, Def;
	std::string name, type, rarity, slot, description;
public:

	Equipable(std::string name, std::string type, int DMG, int durability, int value, std::string rarity, std::string slot, std::string description, int Def) {
		this->name = name;
		this->type = type;
		this->DMG = DMG;
		this->durability = durability;
		this->value = value;
		this->rarity = rarity;
		this->slot = slot;
		this->description = description;
		this->Def = Def;
	}

	void viewDetails() const {
		std::cout << "Name: " << name << std::endl;
		std::cout << "Type: " << type << std::endl;
		std::cout << "DMG: " << DMG << std::endl;
		std::cout << "Durability: " << durability << std::endl;
		std::cout << "Value: " << value << std::endl;
		std::cout << "Rarity: " << rarity << std::endl;
		std::cout << "Slot: " << slot << std::endl;
		std::cout << "Description: " << description << std::endl;
		std::cout << "Def: " << Def << std::endl;
	}

	std::string getName() { return name; }
	std::string getType() { return type; }
	int getDMG() const { return DMG; }
	int getDurability() const { return durability; }
	int getValue() const { return value; }
	std::string getRarity() { return rarity; }
	std::string getSlot() { return slot; }
	std::string getDescription() { return description; }
	int getDef() const { return Def; }
};

#endif // !EQUIPABLE_C
