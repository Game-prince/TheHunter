#ifndef PLAYER_C
#define PLAYER_C

#include <iostream>
#include "Entity.cpp"

class Player : public Entity{
private:
public:
	Player(std::string name) : Entity(name,100, 100, 10, 5) {}

	void buyItem(Weapon* weapon) {
		addItem(weapon);
		removeGold(weapon->getValue());
	}
};

#endif // !PLAYER_C
