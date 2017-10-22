
#include "Game.h"
#include <fstream>



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

void Game::initGame()
{
	createNewCharacter();
}

// Functions
void Game::mainMenu()
{
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
	cin >> choice;

	switch (choice)
	{
	case 0:
		playing = false;
		break;
	case 5:
		characters[activeCharacter].printStatus();
		break;
	case 6:
		cin.ignore();
		createNewCharacter();
		saveCharacters();
		break;
	case 7:
		saveCharacters();
		break;
	case 8:
		loadCharacters();
		break;

	default:
		break;
	}



}

void Game::createNewCharacter()
{
	std::string name = "";
	std::cout << "Enter name for character: ";
	getline(std::cin, name);

	characters.push_back(Character());
	activeCharacter = characters.size() - 1;
	characters[activeCharacter].initialize(name);
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

}
