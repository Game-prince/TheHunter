#ifndef MONSTER_C
#define MONSTER_C

#include <iostream>
#include "Entity.cpp"

class Monster :public Entity {
private:
public:
	Monster(std::string name,int health, int mana, int baseAttack, int baseDefence) : Entity(name,health, mana, baseAttack, baseDefence) {}
};

#endif // !MONSTER_C
