#include <iostream>
#include "Player.cpp"


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
        std::cout << "1. Sword\n";
        std::cout << "2. Mace\n";
        std::cout << "3. Axe\n";
        std::cout << "4. Bow\n";
        std::cout << "5. Dagger\n";

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