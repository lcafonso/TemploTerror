
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
	cout << "=== MAIN MENU ===\n\n";
	cout << "= Active character: " << 
		this->characters[activeCharacter].getName() << " Nr: " <<
		this->activeCharacter+1 << "/" <<
		this->characters.size() << " =\n\n";
	cout << "0: Quit\n";
	cout << "1: Travel\n";
	cout << "2: Shop\n";
	cout << "3: Level up\n";
	cout << "4: Rest\n";
	cout << "5: Character sheet\n";
	cout << "6: Create new Character\n";
	cout << "7: Select Character\n";	
	cout << "8: Save Character\n";
	cout << "9: Load Character\n";
	
	cout << "\nChoice:";
	cin >> this->choice;

	while (cin.fail())
	{
		cout << "Faulty input! \n";
		cin.clear();
		cin.ignore(100, '\n');

		cout <<  "\nChoice: ";
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
		createNewCharacter();
		saveCharacters();
		break;
	case 7: // select character
		selectCharacters();
		break;	
	case 8: // save character
		saveCharacters();
		break;
	case 9: // load character
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

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		while (name == this->characters[i].getName())
		{
			cout << "\nError! Character already exists!\n";
			cout << "Enter name for character: ";
			getline(cin, name);
		}
	}

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

void Game::selectCharacters()
{
	cout << "Select Character: \n\n";

	for (size_t i = 0; i < this->characters.size(); i++)
	{
		cout << "Index: " << i << " = " <<
			this->characters[i].getName() <<
			" Level: " << this->characters[i].getLevel() << "\n";
	}

	cout << "\nChoice: ";
	
	cin >> this->choice;

	while (cin.fail() || this->choice >= this->characters.size() || this->choice < 0)
	{
		cout << "Faulty input!\n";
		cin.clear();
		cin.ignore(100, '\n');

		cout << "Select Character: \n";
		cin >> this->choice;
	}

	cin.ignore(100, '\n');
	cout << "\n";

	this->activeCharacter = this->choice;

	cout << this->characters[this->activeCharacter].getName() << " is SELECTED! \n\n";
}

void Game::travel()
{
	this->characters[activeCharacter].travel();

	Event ev;

	ev.generateEvent(this->characters[activeCharacter], this->enemies);

}
