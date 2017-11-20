#pragma once

#include "Weapon.h"
#include "Armor.h"

using namespace std;

class Inventory
{
private:
	int cap;
	int nrOfItems;

	Item **itemArr;

	// Functions
	void expand();
	void initialize(const int from = 0);


public:
	Inventory();
	virtual ~Inventory();
	Inventory(const Inventory &obj);

	// Operators
	Item& operator[](const int index);

	// Functions
	inline int size() const { return this->nrOfItems; };
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

