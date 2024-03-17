#ifndef MONSTER_C
#define MONSTER_C

#include <iostream>
#include "Entity.cpp"

class Monster :public Entity {
private:
public:
	Monster(std::string name,int HP, int MP, int baseDMG, int baseDef) : Entity(name,HP, MP, baseDMG, baseDef) {}
};

#endif // !MONSTER_C
