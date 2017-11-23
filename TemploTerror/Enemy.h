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
	inline int getDamage() const { return rand() % this->damageMax - this->damageMin; };
	inline int getExp() const { return this->level * 100; };


	// Accessors

	// Modifiers

};

