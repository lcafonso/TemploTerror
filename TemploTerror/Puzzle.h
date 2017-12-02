#pragma once

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Puzzle
{
private:
	std::string question;
	std::vector<std::string> answers;
	int correctAnswer;

public:
	Puzzle(std::string fileName);
	virtual ~Puzzle();

	// Operators

	// Functions
	std::string getAsString();

	// Accessors
	inline const int& getCorrectAns()const { return this->correctAnswer; };
	
	// Modifiers

};

