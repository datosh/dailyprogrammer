#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "HackingGame.h"

int main() {

	std::cout << "Difficulty (1-5)? ";
	std::string inBuffer;
	std::getline(std::cin, inBuffer);
	int difficulty = std::stoi(inBuffer);

	HackingGame hg(difficulty);
	hg.run();

	return 0;
}