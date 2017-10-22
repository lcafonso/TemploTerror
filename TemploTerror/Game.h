#pragma once


#include "Functions.h"
#include "Character.h"
#include <vector>

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
	void saveCharacters();
	void loadCharacters();


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

