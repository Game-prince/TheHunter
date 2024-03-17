#ifndef PLAYER_C
#define PLAYER_C

#include <iostream>
#include <map>
#include "Entity.cpp"
#include "Equipable.cpp"

class Player : public Entity{
private:
	std::map<std::string, Equipable*> equipped;
public:
	Player(std::string name) : Entity(name,100, 100, 10, 5) {
		equipped["head"] = nullptr;
		equipped["chest"] = nullptr;
		equipped["legs"] = nullptr;
		equipped["feet"] = nullptr;
		equipped["leftHand"] = nullptr;
		equipped["rightHand"] = nullptr;
	}

	void buyItem(Equipable* item) {
		addItem(item);
		removeGold(item->getValue());
	}

	void showStats() const {

		Entity::showStats();
		std::cout << "Gold: " << this->getGold() << "\n";
		std::cout << "Experience: " << this->getExperience() << "\n";
		std::cout << std::endl;
	}

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
};

#endif // !PLAYER_C
