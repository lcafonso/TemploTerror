#include "Enemy.h"



Enemy::Enemy(int level)
{
	this->level = level;
	this->hpMax = level * 10;
	this->hp = this->hpMax;
	this->damageMin = this->level * 4;
	this->damageMax = this->level * 5 ;
	this->dropChange = rand() % 100 + 1;
	this->defence = rand() % level*5 + 1;
	this->accuracy = rand() % level*5 + 1;
}


Enemy::~Enemy()
{
}

std::string Enemy::getAsString() const
{
	return "Level: " +  std::to_string(this->level) + "\n" + 
		"Hp: " + std::to_string(this->hp) + " / " + std::to_string(this->hpMax) + "\n" +
		"Damange: " + std::to_string(this->damageMin) + " - " + std::to_string(this->damageMax) + "\n" + 
		"Defence: " + std::to_string(this->defence) + "\n" +
		"Accuracy: " + std::to_string(this->accuracy) + "\n" +
		"Drop Chance: " + std::to_string(this->dropChange) + "\n";
	
}

void Enemy::takeDamage(int damage)
{
	this->hp -= damage;

	if (this->hp <= 0)
	{
		this->hp = 0;
	}

}
