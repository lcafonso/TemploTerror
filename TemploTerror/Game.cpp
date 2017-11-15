
#include "Game.h"



Game::Game()
{
	choice = 0;
	playing = true;
	activeCharacter = 0;
	fileName = "character.txt";

}


Game::~Game()
{
}


// Functions
void Game::initGame()
{
	createNewCharacter();

	dArr<int> ints;

	for (size_t i = 0; i < 20; i++)
	{
		ints.push(rand() % 10);
		cout << ints[i] << "\n";
	}
}


void Game::mainMenu()
{

	cout << "ENTER to continue...." << "\n";
	cin.get();
	if (system("cls")) system("clear");

	if (this->characters[activeCharacter].getExp() >= 
		this->characters[activeCharacter].getExpNext())
	{
		std::cout << "Level up Available! \n\n";
	}
	cout << "=== MAIN MENU ===" << endl;
	cout << "0: Quit" << endl;
	cout << "1: Travel" << endl;
	cout << "2: Shop" << endl;
	cout << "3: Level up" << endl;
	cout << "4: Rest" << endl;
	cout << "5: Character sheet" << endl;
	cout << "6: Create new Character" << endl;
	cout << "7: Save Character" << endl;
	cout << "8: Load Character" << endl;
	cout << endl << "Choice:";
	cin >> this->choice;

	while (cin.fail())
	{
		cout << "Faulty input!" << "\n";
		cin.clear();
		cin.ignore(100, '\n');

		cout << endl << "Choice: ";
		cin >> this->choice;
	}

	cin.ignore(100, '\n');
	cout << endl;

	switch (this->choice)
	{
	case 0: // quit
		playing = false;
		break;
	case 1: // travel
		travel();
		break;
	case 2: // shop
		break;
	case 3: // level up
		this->levelUpCharacter();
		break;
	case 4: // rest
		break;
	case 5: // char sheet
		characters[activeCharacter].printStatus();
		break;
	case 6: // crteate new character
		cin.ignore();
		createNewCharacter();
		saveCharacters();
		break;
	case 7: // save character
		saveCharacters();
		break;
	case 8: // load character
		loadCharacters();
		break;

	default:
		break;
	}



}

void Game::createNewCharacter()
{
	string name = "";
	cout << "Enter name for character: ";
	getline(cin, name);

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);
}

void Game::levelUpCharacter()
{
	this->characters[activeCharacter].levelUp();

	if(this->characters[activeCharacter].getStatPoints() > 0)
	{ 
		cout << "You have stat points to alocate!\n";
		cout << "Stat to upgrade: \n";
		cout << "0: Strength \n";
		cout << "1: Vitality \n";
		cout << "2: Dextrerity \n";
		cout << "3: Intelligence \n";

		cin >> this->choice;

		while (cin.fail() || this->choice > 3)
		{
			cout << "Faulty input!\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Stat to upgrade: \n";
			cin >> this->choice;
		}

		cin.ignore(100, '\n');
		cout << "\n";

		switch (this->choice)
		{
		case 0:
			this->characters[activeCharacter].addStat(0, 1);
			break;
		case 1:
			this->characters[activeCharacter].addStat(1, 1);
			break;
		case 2:
			this->characters[activeCharacter].addStat(2, 1);
			break;
		case 3:
			this->characters[activeCharacter].addStat(3, 1);
			break;
		default:
			break;
		}
	}
}

void Game::saveCharacters()
{
	ofstream outFile(fileName);

	if (outFile.is_open())
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			outFile << characters[i].getAsString() << "\n";
		}
	}

	outFile.close();
}

void Game::loadCharacters()
{
	ifstream inFile(fileName);
	
	this->characters.clear();

	string name = "";
	int gold = 0;
	int distanceTravelled = 0;
	int level = 0;
	int exp = 0;
	int strength = 0;
	int vitality = 0;
	int dexterity = 0;
	int intelligence = 0;
	int hp = 0;
	int stamina = 0;
	int statPoints = 0;
	int skillPoints = 0;

	string line = "";
	stringstream str;

	if (inFile.is_open())
	{
		while(getline(inFile, line))
		{
			str.str(line);
			str >> name;
			str >> distanceTravelled;
			str >> gold;
			str >> level;
			str >> exp;
			str >> strength;
			str >> vitality;
			str >> dexterity;
			str >> intelligence;
			str >> hp;
			str >> stamina;
			str >> statPoints;
			str >> skillPoints;

			Character temp(name,
				distanceTravelled,
				gold,
				level,
				exp,
				strength,
				vitality,
				dexterity,
				intelligence,
				hp,
				stamina,
				statPoints,
				skillPoints);

			this->characters.push_back(Character(temp));

			cout << "Character " << name << " loaded!" << endl;

			str.clear();
		}
	}

	inFile.close();

	if (this->characters.size() <= 0)
	{
		throw "ERROR! NO CHARACTERS LOADED OR EMPTY FILE!";
	}
}

void Game::travel()
{
	this->characters[activeCharacter].travel();

	Event ev;

	ev.generateEvent(this->characters[activeCharacter]);

}
