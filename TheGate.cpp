#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Player.cpp"
#include "rapidjson/document.h"

// read json file
static rapidjson::Document readJson(std::string filename) {
    rapidjson::Document document;

    std::ifstream file(filename);
    if (!file.is_open()) {
		std::cout << "File not found\n";
        return document;
	}

    std::string jsonString;
    std::string line;
    while (std::getline(file, line)) jsonString += line;
    file.close();

    document.Parse(jsonString.c_str());

    if (document.HasParseError()) {
        std::cerr << "JSON parse error: " << document.GetParseError() << '\n';
        return document;
    }

    return document;
}


int main() {

        std::cout << "Welcome to The Hunter\n";

        Player* player = new Player();
        

        std::cout << "\nYou are a hunter who was hired to clear a dungeon of monsters.\n";
        std::cout << "You are now standing in front of the gate of the dungeon.\n";

        std::cout << "\nWhat would you like to do?\n";
        std::cout << "1. Enter the dungeon\n";
        std::cout << "2. Leave\n";
        std::cout << "3. Check your inventory\n";
        std::cout << "4. Check your stats\n";

        int choice;
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        while (choice != 1 && choice != 2) {

            if (choice == 3) {
                player->showInvetory();
            }
            else if (choice == 4) {
                player->showStats();
            }
            else {
				std::cout << "Invalid choice\n";
            }
				std::cout << "Choose again: ";
				std::cin >> choice;
		}

        if (choice == 2) {
			std::cout << "You left the game\n";
			return 0;
		}

        player->addGold(100);
        std::cout << "Choose a weapon to take with you\n";
        std::cout << std::setw(20) << "Name" << std::setw(10) << "Attack" << std::setw(10) << "Price" << std::endl;

        rapidjson::Document weaponsDocument = readJson("weapons.json");
        const rapidjson::Value& weapons = weaponsDocument["weapons"];
        for (rapidjson::SizeType i = 0; i < weapons.Size(); i++) {
			const rapidjson::Value& weapon = weapons[i];
			std::string name = weapon["name"].GetString();
            int attack = weapon["damage"].GetInt();
            int price = weapon["value"].GetInt();
            std::cout << std::setw(20) << name << std::setw(10) << attack << std::setw(10) << price << std::endl;
			
		}

        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        while (choice < 1 || choice > 5) {
			std::cout << "Invalid choice\n";
			std::cout << "Choose again: ";
			std::cin >> choice;
		}

        if (choice == 1) {
			Weapon* sword = new Weapon("Sword", "Melee", 20, 100, 50, "Common", "Main Hand", "A simple sword");
			player->addItem(sword);
		}
        else if (choice == 2) {
			Weapon* mace = new Weapon("Mace", "Melee", 25, 100, 60, "Common", "Main Hand", "A simple mace");
			player->addItem(mace);
		}
        else if (choice == 3) {
			Weapon* axe = new Weapon("Axe", "Melee", 30, 100, 70, "Common", "Main Hand", "A simple axe");
			player->addItem(axe);
		}
        else if (choice == 4) {
			Weapon* bow = new Weapon("Bow", "Ranged", 35, 100, 80, "Common", "Main Hand", "A simple bow");
			player->addItem(bow);
		}
        else if (choice == 5) {
			Weapon* dagger = new Weapon("Dagger", "Melee", 40, 100, 90, "Common", "Main Hand", "A simple dagger");
			player->addItem(dagger);
		}

		player->showInvetory();

		std::cout << "You are now ready to enter the dungeon\n";

		return 0;

}