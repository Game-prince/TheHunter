#ifndef PLAYER_C
#define PLAYER_C

#include <iostream>
#include <map>
#include "Entity.cpp"
#include "Equipable.cpp"
#include "Inventory.cpp"

class Player : public Entity{
private:
	std::map<std::string, Equipable*> equipped;
	Inventory* inventory;
public:
	Player(std::string name) : Entity(name,100, 100, 10, 5) {
		equipped["head"] = nullptr;
		equipped["chest"] = nullptr;
		equipped["legs"] = nullptr;
		equipped["feet"] = nullptr;
		equipped["leftHand"] = nullptr;
		equipped["rightHand"] = nullptr;

		inventory = new Inventory();
	}

	// ============= INVENTORY ===========
	void addItem(Equipable* weapon) {
		inventory->addItem(weapon);
	}
	void removeItem(Equipable* weapon) {
		inventory->removeItem(weapon);
	}
	void showInventory() {
		inventory->display();

		std::cout << "\n";
	}

	void buyItem(Equipable* item) {
		addItem(item);
		this->updateGold(item->getValue(), false);
	}

	// ===============  STATS ============

	void showStats() const {

		Entity::showStats();
		std::cout << "Gold: " << this->getGold() << "\n";
		std::cout << "Experience: " << this->getExperience() << "\n";
		std::cout << std::endl;

		std::cout << "\n1. View equipped item.\n";
		std::cout << "2. Go back.\n";

		std::cout << "\nEnter your choice: ";
		int choice; std::cin >> choice;
		while (choice < 1 && choice > 2) {
			std::cout << "Invalid choice\n";
			std::cout << "Choose again: ";
			std::cin >> choice;
		}

		if (choice == 1) this->showEquipped();
		else return;
		
	}

	// ============== Equipables =================
	void showEquipped() const {
		std::cout << "=========" << this->getName() << "'s equipped items ==========\n";
		std::cout << "Head: " << (equipped.at("head") == nullptr ? "Nothing" : equipped.at("head")->getName()) << "\n";
		std::cout << "Chest: " << (equipped.at("chest") == nullptr ? "Nothing" : equipped.at("chest")->getName()) << "\n";
		std::cout << "Legs: " << (equipped.at("legs") == nullptr ? "Nothing" : equipped.at("legs")->getName()) << "\n";
		std::cout << "Feet: " << (equipped.at("feet") == nullptr ? "Nothing" : equipped.at("feet")->getName()) << "\n";
		std::cout << "Left Hand: " << (equipped.at("leftHand") == nullptr ? "Nothing" : equipped.at("leftHand")->getName()) << "\n";
		std::cout << "Right Hand: " << (equipped.at("rightHand") == nullptr ? "Nothing" : equipped.at("rightHand")->getName()) << "\n";
		std::cout << std::endl;
	}

	void equipItem(Equipable* item) {
		std::string slot = item->getSlot();

		// if the slot is already equipped, remove the item and add to inventory
		if (equipped[slot]) {
			Equipable* current = removeEquipped(slot);
			this->addItem(current);
		}

		// equip the item at slot and remove the item from inventory
		this->equipped[slot] = item;
		this->removeItem(item);
		this->updateStats(item);
	}

	Equipable* removeEquipped(std::string slot) {

		Equipable* current = this->equipped[slot];
		this->equipped[slot] = nullptr;
		this->updateStats(current, false);

		return current;
	}

	void updateStats(Equipable* item, bool adding=true) {
		this->updateDMG(item->getDMG(), adding);
		this->updateDef(item->getDef(), adding);
		this->updateHP(item->getDurability(), adding);
	}

};

#endif // !PLAYER_C
