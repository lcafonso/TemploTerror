#include "Event.h"



Event::Event()
{
	this->nrOfEvents = 2;

}


Event::~Event()
{
}

void Event::generateEvent(Character &character)
{
	int i = rand() % this->nrOfEvents ;

	switch (1)
	{
	case 0:
		//Enemy encounter
		enemyEncounter(character);
		break;
	case 1:
		//Puzzle
		puzzleEncounter(character);
		break;
	case 2:
		break;
	default:
		break;
	}

}

//Different events
void Event::enemyEncounter(Character & character)
{
}

void Event::puzzleEncounter(Character & character)
{
}
