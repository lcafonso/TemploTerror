#pragma once


#include "Functions.h"
#include "Event.h"

#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

class Game
{
public:
	Game();
	virtual ~Game();

	// Operators

	// Functions
	void initGame();
	void mainMenu();
	void createNewCharacter();
	void levelUpCharacter();
	void saveCharacters();
	void loadCharacters();
	void travel();

	// Accessors
	bool getPlaying() const {
		return this->playing;
	}


	// Modifiers


private:
	int choice;
	bool playing;

	//Character related
	int activeCharacter;
	vector<Character> characters;
	string fileName;
};

