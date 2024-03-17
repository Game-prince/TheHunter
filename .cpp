#ifndef WEAPON_C
#define WEAPON_C

#include <iostream>
#include "Equipable.cpp"

class Weapon : public Equipable {
private:
public:
	Weapon(std::string name, std::string type, int attack, int durability, int value, std::string rarity, std::string slot, std::string description) : Equipable(name, type, attack, durability, value, rarity, slot, description) {}

	void viewDetails() const {
		Equipable::viewDetails();
	}
};

#endif // !WEAPON_C
