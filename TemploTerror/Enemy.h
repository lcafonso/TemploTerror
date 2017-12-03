#pragma once

#include <stdlib.h>
#include <string>

using namespace std;

class Enemy
{
private:
	int level;
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	float dropChange;
	int defence;
	int accuracy;

public:
	Enemy(int level = 0);
	virtual ~Enemy();

	// Operators

	// Functions
	inline bool isAlive() const { return this->hp > 0; }
	std::string getAsString() const;
	void takeDamage(int damage);

	inline int getLevel() const { return this->level; }
	inline int getDamage() const { return rand() % this->damageMax + this->damageMin; };
	inline int getExp() const { return this->level * 100; };
	inline int getHp() const { return this->hp; }
	inline int getHpMax() const { return this->hpMax; }
	inline int getDefence() const { return this->defence; }
	inline int getAccuracy() const { return this->accuracy; }


	// Accessors

	// Modifiers
};

