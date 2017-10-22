#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

class Item
{
private:
	std::string name;
	int buyValue;
	int sellValue;


public:
	Item();
	virtual ~Item();

	// Operators

	// Functions
	inline std::string debugPrint() const 
	{
		return this->name;
	}

	// Accessors

	// Modifiers




};

