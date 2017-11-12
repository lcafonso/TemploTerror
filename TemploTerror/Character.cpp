#include "Character.h"



Character::Character()
{
	this->distanceTravelled = 0;

	this->gold = 0;

	this->name = "";
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;

	this->strength = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->hp = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->accuracy = 0;
	this->luck = 0;
	this->statPoints = 0;
	this->skillPoints = 0;
}

Character::Character(string name, int distanceTravelled, int gold, int level, int exp, int strength, int vitality, int dexterity, int intelligence, int hp, int stamina, int statPoints, int skillPoints)
{
	this->distanceTravelled = distanceTravelled;

	this->gold = gold;

	this->name = name;
	this->level = level;
	this->exp = exp;
	this->expNext = 0;

	this->strength = strength;
	this->vitality = vitality;
	this->dexterity = dexterity;
	this->intelligence = intelligence;

	this->hp = hp;
	this->hpMax = 0;
	this->stamina = stamina;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->accuracy = 0;
	this->luck = 0;
	this->statPoints = statPoints;
	this->skillPoints = skillPoints;

	this->updateStatus();
}


Character::~Character()
{
}


// Functions
void Character::initialize(const string name)
{
	this->distanceTravelled = 0;

	this->gold = 100;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = 
		static_cast<int>((50 / 3)*((pow(this->level, 3) -
			6 * pow(this->level, 2)) +
			(17 * this->level) - 12)) + 100;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;

	this->hpMax = (this->vitality * 2) + (this->strength / 2);
	this->hp = hpMax;
	this->staminaMax = this->vitality + (this->strength/2) + (this->dexterity/3);
	this->stamina = staminaMax;
	
	this->damageMin = this->strength;
	this->damageMax = this->strength+2;
	this->defence = this->dexterity +  (this->intelligence/2);
	this->accuracy = (this->dexterity / 2);
	this->luck = this->intelligence;

	this->statPoints = 0;
	this->skillPoints = 0;

}

void Character::printStatus() const
{
	cout << "= Character Sheet =" << endl;
	cout << endl;
	cout << "Name: " << this->name << endl;
	cout << "Level: " << this->level << endl;
	cout << "Exp: " << this->exp << endl;
	cout << "Exp to next level: " << this->expNext << endl;
	cout  << endl;
	cout << "Strength: " << this->strength << endl;
	cout << "Vitality: " << this->vitality << endl;
	cout << "Dexterity: " << this->dexterity << endl;
	cout << "intelligence: " << this->intelligence << endl;
	cout  << endl;
	cout << "HP: " << this->hp << " / " <<  this->hpMax << endl;
	cout << "Stamina: " << this->stamina << " / " << staminaMax << endl;
	cout << "Damage: " << this->damageMin << " - " << this->damageMax << endl;
	cout << "Defence: " << this->defence << endl;
	cout << "Accurancy: " << this->accuracy << endl;
	cout << "Luck: " << this->luck << endl;
	cout << endl;

}

void Character::levelUp()
{
	if (this->exp >= this->expNext)
	{
		this->exp -= this->expNext;
		this->level++;
		this->expNext =
			static_cast<int>((50 / 3)*((pow(this->level, 3) -
				6 * pow(this->level, 2)) +
				(17 * this->level) - 12)) + 100;

		this->statPoints++;
		this->skillPoints++;

		this->updateStatus();

		cout << "You are now level " << this->level << "!\n\n";

	}
	else 
	{
		cout << "Not enough EXP! \n\n";
	}
}

string Character::getAsString() const
{
	return name + " " +
		to_string(distanceTravelled) + " " +
		to_string(gold) + " " +
		to_string(level) + " " +
		to_string(exp) + " " +
		to_string(strength) + " " +
		to_string(vitality) + " " +
		to_string(dexterity) + " " +
		to_string(intelligence) + " " +
		to_string(hp) + " " +
		to_string(stamina) + " " +
		to_string(statPoints) + " " +
		to_string(skillPoints) ;
}

void Character::updateStatus()
{
	this->expNext =
		static_cast<int>((50 / 3)*((pow(this->level, 3) -
			6 * pow(this->level, 2)) +
			(17 * this->level) - 12)) + 100;


	this->hpMax = (this->vitality * 2) + (this->strength / 2);
	this->staminaMax = this->vitality + (this->strength / 2) + (this->dexterity / 3);
	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;
	this->defence = this->dexterity + (this->intelligence / 2);
	this->accuracy = (this->dexterity / 2);
	this->luck = this->intelligence;
}

void Character::addStat(int stat, int value)
{
	if (this->statPoints < value)
		cout << "ERROR! Not enough Satpoints! \n";
	else
	{ 
		switch (stat)
		{
		case 0:
			this->strength += value;
			break;
		case 1:
			this->vitality += value;
			break;
		case 2:
			this->dexterity += value;
			break;
		case 3:
			this->intelligence += value;
			break;
		default:
			cout << "No SUCH STAT! \n";
			break;
		}

		this->statPoints -= value;
	}

}

