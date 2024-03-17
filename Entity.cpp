#ifndef ENTITY_C
#define ENTITY_C

#include <iostream>

class Entity {
private:
	std::string name;

	// HP
	int maxHP, HP, baseHP;

	// MP
	int maxMP, MP;

	// DMG
	int baseDMG, DMG;

	// Def
	int baseDef, Def;

	int level, experience, gold;
public:
	Entity() {
		this->name = "Player";
		this->maxHP = this->baseHP = 0;
		this->HP = 0;
		this->maxMP = 0;
		this->MP = 0;
		this->baseDMG = 0;
		this->DMG = 0;
		this->baseDef = 0;
		this->Def = 0;
		this->level = 1;
		this->experience = 0;
		this->gold = 0;

	}

	Entity(std::string name,int HP, int MP, int baseDMG, int baseDef) {
		this->name = name;
		this->maxHP = this->HP = this->baseHP = HP;
		this->maxMP = this->MP = MP;
		this->baseDMG = this->DMG = baseDMG;
		this->baseDef = this->Def = baseDef;
		this->level = 1;
		this->experience = 0;
		this->gold = 0;

	}

	void showStats() const {
		std::cout << std::endl;

		std::cout << "=========" << this->name << "'s stats ==========\n";
		std::cout << "HP: " << HP << "\n";
		std::cout << "MP: " << MP << "\n";
		std::cout << "Level: " << level << "\n";
		std::cout << "DMG: " << DMG << "\n";
		std::cout << "Def: " << Def << "\n";

	}

	// ============= NAME ===========
	std::string getName() const { return name; }
	
	// ============= GOLD ===========
	int getGold() const {return gold;}
	void updateGold(int gold, bool adding = true) {
		if (adding) {
			this->gold += gold;
			std::cout << "You received " << gold << " gold\n";
		}
		else {
			this->gold -= gold;
			if (this->gold < 0) this->gold = 0;
			std::cout << "You lost " << gold << " gold\n";
		}
	}

	// ============= EXPERIENCE ===========
	int getExperience() const {return experience;}
	void addExperience(int experience) {
		this->experience += experience;
		std::cout << "You received " << experience << " experience\n";
	}

	// ============= HP ===========
	int getMaxHP() const {return maxHP;}
	int getHP() const { return HP;}
	void updateHP(int hp, bool adding = true) {
		if (adding) {
			this->HP += HP;
			std::cout << "You received " << HP << " HP\n";
		}
		else {
			this->HP -= HP;
			if (this->HP < 0) this->HP = 0;
			std::cout << "You lost " << HP << " HP\n";
		}
	}

	// ============= MP ===========
	int getMaxMP() const { return this->maxMP; }
	int getMP() const {return MP;}
	void updateMP(int MP, bool adding = true) {
		if (adding) {
			this->MP += MP;
			std::cout << "You received " << MP << " MP\n";
		}
		else {
			this->MP -= MP;
			if (this->MP < 0) this->MP = 0;
			std::cout << "You lost " << MP << " MP\n";
		}
	}

	// ============= DMG ===========
	int getDMG() const {return DMG;}
	void updateDMG(int DMG, bool adding=true) {
		if (adding) {
			this->DMG += DMG;
			std::cout << "You received " << DMG << " DMG\n";
		}
		else {
			this->DMG -= DMG;
			std::cout << "You lost " << DMG << " DMG\n";
		}
	}
	void doDMG(Entity* entity) const {entity->dealsDamage(this->DMG);}

	// ============= Def ===========
	int getDef() const {return Def;}
	void updateDef(int def, bool add = true) {
		if (add) {
			this->Def += Def;
			std::cout << "You received " << Def << " Def\n";
		}
		else {
			this->Def -= Def;
			std::cout << "You lost " << Def << " Def\n";
		}
	}
	void dealsDamage(int damage) {
		if (this->HP + this->Def <= damage) {
			this->HP = 0;
		}
		else {
			this->HP -= (damage - Def) > 0 ? (damage - Def) : 0;
		}
		std::cout << this->name << " received " << damage << " damage\n";
	}

	// ============= LEVEL ===========
	int getLevel() const {return level;}
	void addLevel(int level) {
		this->level += level;
		std::cout << "You received " << level << " level\n";
	}

};

#endif // !ENTITY_C
