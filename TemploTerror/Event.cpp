#include "Event.h"

Event::Event()
{
	this->nrOfEvents = 2;

}


Event::~Event()
{
}

void Event::generateEvent(Character &character, dArr<Enemy>& enemies)
{
	int i = rand() % this->nrOfEvents ;

	switch (i)
	{
	case 0:
		//Enemy encounter
		enemyEncounter(character, enemies);
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
void Event::enemyEncounter(Character & character, dArr<Enemy>& enemies)
{
	bool escape = false;
	bool playerDefeated = false;
	bool enemyDefeated = false;

	while (!escape && !playerDefeated && !enemyDefeated)
	{

	}
}

void Event::puzzleEncounter(Character & character)
{
	bool completed = false;
	int userAns = 0;
	int chances = 3;
	int gainExp = (rand() % (chances * (character.getLevel() * rand() % 10 + 1)))+10;

	Puzzle puzzle("puzzles/1.txt");
	
	while (!completed && chances > 0)
	{
		cout << "you have " << chances << " chances\n\n";
		chances--;
		cout << puzzle.getAsString() << "\n";

		cout << "Your Answer: ";
		cin >> userAns;
		cout << "\n";

		while (cin.fail())
		{
			cout << "Faulty input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Your Answer: ";
			cin >> userAns;
		}

		cin.ignore(100, '\n');
		cout << endl;

		if (puzzle.getCorrectAns() == userAns)
		{
			completed = true;
			// GIVE USER EXP ETC AND CONTINUE
			character.gainExp(gainExp);
			cout << "You Gained " << gainExp << " EXP! \n\n";
		}


	}

	if (completed)
	{
		cout << "Congratulation you succeded! \n\n";
	}
	else
	{
		cout << "You failed! \n\n";
	}
}
