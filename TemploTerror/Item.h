#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

class Item
{
private:
	std::string name;
	int level;
	int buyValue;
	int sellValue;
	int rarity;


public:
	Item(std::string name = "NONE", int level = 0,
		int buyValue = 0,
		int sellValue = 0,
		int rarity = 0);

	virtual ~Item();

	// Operators

	// Functions
	inline std::string debugPrint() const
	{
		return this->name;
	}
	virtual Item* clone() const = 0;

	// Accessors
	inline const std::string& getName() const { return this->name; };
	inline const int& getLevel() const { return this->level; };
	inline const int& getBuyValue() const { return this->buyValue; };
	inline const int& getSellvalue() const { return this->sellValue; };
	inline const int& getRarity() const { return this->rarity; };
	
	
	// Modifiers




};

