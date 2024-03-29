#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "Entity.cpp"
#include "Player.cpp"
#include "Monster.cpp"
#include "rapidjson/document.h"

// contains all the entities
static std::vector<Entity*> entities;

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

// create weapon from json
static Equipable* createWeapon(const rapidjson::Value& weapon) {
	std::string name = weapon["name"].GetString();
	std::string type = weapon["type"].GetString();
	int DMG = weapon["damage"].GetInt();
	int durability = weapon["durability"].GetInt();
	int value = weapon["value"].GetInt();
	std::string rarity = weapon["rarity"].GetString();
	std::string slot = weapon["slot"].GetString();
    std::string description = weapon["description"].GetString();

	return new Equipable(name, type, DMG, durability, value, rarity, slot, description, 0);
}

// fight with monster
static int fight(Player* player, Monster* monster) {

    bool playerFirst;
    int turn = 0; // 0 for player, 1 for monster

    int toss = rand() % 2;
    if (toss == 0) {
		playerFirst = true;
        std::cout << "You will DMG first\n";
	}
    else {
		playerFirst = false;
        turn = 1;
        std::cout << monster->getName() << " will DMG first\n";
	}

    int round = 0;
    while (player->getHP() > 0 && monster->getHP() > 0) {

        std::cout << "================" << (round == 0 ? "First Round" : "Next Round") << "============================\n";

        // monster's turn
        if (turn) {
            std::cout << monster->getName() << "'s turn\n";
            monster->doDMG(player);
            player->showStats();
        }

        // player's turn
        else {
            std::cout << player->getName() << "'s(your) turn\n";
            std::cout << "What would you like to do?\n";
            std::cout << "1. DMG\n";
            std::cout << "2. Run\n";

            int choice;
            std::cin >> choice;
            while (choice != 1 && choice != 2) {
				std::cout << "Invalid choice\n";
				std::cout << "Choose again: ";
				std::cin >> choice;
			}

            if (choice == 2) {
				std::cout << "You can't run away from the monster\n";
				std::cout << "The monster DMGed you and you lost\n";
				return 1; // player lost
			}

            player->doDMG(monster);
            monster->showStats();
        }

        turn = (turn + 1) % 2;
        round++;
	}

    std::cout << "\n====================== Fight Results ================" << std::endl;

    if (player->getHP() == 0) {
        std::cout << "You lost\n";
        return 1; // player lost
    }
    else {
		std::cout << "You won\n";
		return 0; // player won
	}
}

// Game over option
static int gameOverOption() {
    for (auto entity : entities) {
        delete entity;
    }
    entities.clear();

    std::cout << "\nDo you want to play again?\n";
    std::cout << "1. Yes\n";
    std::cout << "2. No\n";

    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;

    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice\n";
        std::cout << "Choose again: ";
        std::cin >> choice;
    }

    return choice;
}

int main() {

    bool playing = true;
    while (playing) {

        // welcome text
        std::cout << "Welcome to The Hunter\n";

        std::cout << "Please enter your name: ";
        std::string name;
        std::getline(std::cin, name);
        Player* player = new Player(name);

        std::cout << "\n============================================\n";
        std::cout << "Hello " << name << "\n";
        std::cout << "You are a hunter who was hired to clear a dungeon of monsters.\n";
        std::cout << "You are now standing in front of the gate of the dungeon.\n";

		int choice;
        do {
            std::cout << "\nWhat would you like to do?\n";
            std::cout << "1. Enter the dungeon\n";
            std::cout << "2. Exit game\n";
            std::cout << "3. Check your inventory\n";
            std::cout << "4. Check your stats\n";

            std::cout << "\nEnter your choice: ";
            std::cin >> choice;


            if (choice == 2) {
                std::cout << "You left the game\n";
                return 0;
            }
			else if (choice == 3) {
                    player->showInventory();
            }
            else if (choice == 4) {
                player->showStats();
			}
            else {
                std::cout << "Invalid choice\n";
            }
            std::cout << "\n============================================\n";
            
        } while (choice != 1);

        // First weapon
        player->updateGold(100);
        std::cout << "Choose a weapon to take with you\n";
        std::cout << std::setw(5) << "Sr." << std::setw(20) << "Name" << std::setw(10) << "DMG" << std::setw(10) << "Price" << std::endl;

        const rapidjson::Document weaponsDocument = readJson("weapons.json");
        const rapidjson::Value& weapons = weaponsDocument["weapons"];
        for (rapidjson::SizeType i = 0; i < weapons.Size(); i++) {
            const rapidjson::Value& weapon = weapons[i];
            std::string name = weapon["name"].GetString();
            int DMG = weapon["damage"].GetInt();
            int price = weapon["value"].GetInt();
            std::cout << std::setw(5) << i + 1 << std::setw(20) << name << std::setw(10) << DMG << std::setw(10) << price << std::endl;

        }
        std::cout << std::endl;

        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        while (choice < 1 || choice > 5) {
            std::cout << "Invalid choice\n";
            std::cout << "Choose again: ";
            std::cin >> choice;
        }

        Equipable* w = createWeapon(weapons[choice - 1]);
        player->buyItem(w);
        player->showInventory();

        std::cout << "\n============================================\n";
        std::cout << "You are now ready to enter the dungeon\n";
        std::cout << "Good luck!\n";

        // Enter the dungeon
        std::cout << "\nYou entered the dungeon\n";
        std::cout << "The dungeon is dark and you can hear the sound of monsters\n";
        std::cout << "You are now in the first room of the dungeon\n";

        // First monster (goblin) encounter
        std::cout << "As you were walking, you saw a monster. The monster is a goblin and he has also sensed you.\n";

        Monster* goblin = new Monster("Goblin", 50, 10, 5, 2);

        std::cout << "The goblin is about to Attack you\n";
        choice = 0;
        do {
            std::cout << "\nWhat would you like to do?\n";
            std::cout << "1. Attack\n";
            std::cout << "2. Run\n";
            std::cout << "3. View stats of the goblin\n";
            std::cout << "4. View your stats\n";
            std::cout << "5. View your inventory\n";

            std::cout << "\nEnter your choice: ";
            std::cin >> choice;

            if (choice == 1) {
                int result = fight(player, goblin);
                if (result == 1) {
                    std::cout << "Game over\n";
                    int choice = gameOverOption();

                    if (choice == 2) {
                        return 0;
                    }
                    else if (choice == 1) {
                        system("cls");
                        continue;
                    }

                }
            }
            else if (choice == 2) {
                std::cout << "\nGoblins are fast creatures and you can't run away from him\n";
                std::cout << "The goblin DMGed you and you lost\n";
                std::cout << "Game over\n";

                int choice = gameOverOption();

                if (choice == 2) {
                    return 0;
                }
                else if (choice == 1) {
                    system("cls");
                    continue;
                }
            }
            else  if (choice == 3) { goblin->showStats(); std::cout << std::endl; }
            else if (choice == 4) { player->showStats(); }
            else if (choice == 5) { player->showInventory(); }
            else { std::cout << "Invalid choice\n"; }

            std::cout << "\n============================================\n";
            
        } while (choice != 1);

        std::cout << "\n============================================\n";
        player->showStats();
    }

		return 0;

}