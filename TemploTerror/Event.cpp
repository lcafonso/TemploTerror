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
	bool playerTurn = false;
	int choice = 0;

	//Coin toss for turn
	int coinToss = rand() % 2 + 1;

	if (coinToss == 1)
		playerTurn = true;
	else
		playerTurn = false;

	bool escape = false;
	bool playerDefeated = false;
	bool enemiesDefeated = false;

	int nrOfEnemies = rand() % 5;

	for (size_t i = 0; i < nrOfEnemies; i++)
	{
		enemies.push(Enemy(character.getLevel()));
	}
	



	while (!escape && !playerDefeated && !enemiesDefeated)
	{
		if (playerTurn && !playerDefeated)
		{ 
			//Menu
			cout << "= Battle Menu = \n\n";

			cout << "0: Escape \n";
			cout << "1: Attack \n";
			cout << "2: Defend \n";
			cout << "3: Use Item \n";

			cout << "\nChoice: ";
			cin >> choice;

			while (cin.fail() || choice > 3 || choice < 0)
			{
				if (system("cls")) system("clear");

				cout << "Faulty input!\n";
				cin.clear();
				cin.ignore(100, '\n');

				

				cout << "= Battle Menu = \n\n";

				cout << "0: Escape \n";
				cout << "1: Attack \n";
				cout << "2: Defend \n";
				cout << "3: Use Item \n";

				cout << "Choice: \n";
				cin >> choice;
			}

			cin.ignore(100, '\n');
			cout << "\n";
			
			//Move
			switch (choice)
			{
			case 0:
				escape = true;
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				break;
			}

			

			//Leave turn
			playerTurn = false;


		}
		else if(!playerTurn && !escape && !enemiesDefeated)
		{
			// enemie attack
			for (size_t i = 0; i < enemies.size(); i++)
			{

			}

			//end turn
			playerTurn = true;

		}

		//Conditions


		if (!character.isAlive())
		{
			playerDefeated = true;
		} 
		else if (enemies.size() <= 0)
		{
			enemiesDefeated = true;
		}
			

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
