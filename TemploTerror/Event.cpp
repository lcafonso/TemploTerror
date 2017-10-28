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
	bool completed = false;
	int userAns = 0;
	int chances = 3;
	int gainExp = (rand() % (chances * (character.getLevel() * rand() % 10 + 1)))+1;

	Puzzle puzzle("puzzles/1.txt");
	
	while (!completed && chances > 0)
	{
		chances--;
		std::cout << puzzle.getAsString() << "\n";

		std::cout << "Your Answer: ";
		std::cin >> userAns;
		std::cout << "\n";

		if (puzzle.getCorrectAns() == userAns)
		{
			completed = true;
			// GIVE USER EXP ETC AND CONTINUE
			character.gainExp(gainExp);
			std::cout << "You Gained " << gainExp << "EXP! \n\n";
		}


	}

	if (completed)
	{
		std::cout << "Congratulation you succeded! \n\n";
	}
	else
	{
		std::cout << "You failed! \n\n";
	}
}
