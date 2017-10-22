#pragma once

#include "Item.h"


class Inventory
{
private:
	int cap;
	int nrOfItems;

	Item **itemArr;

	// Functions
	void expand();
	void initialize(const int from);


public:
	Inventory();
	virtual ~Inventory();

	// Operators

	// Functions
	void addIten(const Item &item);
	void removeItem(int index);

	inline void debugPrint() const 
	{
		for (size_t i = 0; i < this->nrOfItems; i++)
		{
			std::cout << this->itemArr[i]->debugPrint() << std::endl;
		}
	};


	// Accessors

	// Modifiers




};

