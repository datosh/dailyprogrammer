#pragma once

#include <algorithm>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

#include "WordReader.h"

struct LUTEntry {
	int num;
	int len;
	int tries;
}

static const MODE_LUT[5] = {
	{ 8, 4, 5 },
	{ 8, 6, 5 },
	{ 8, 9, 5 },
	{ 8, 11, 5 },
	{ 8, 13, 5 },
};

class HackingGame
{
public:
	HackingGame(size_t difficulty = 1);
	~HackingGame();

	void run();

private:

	void init();
	void stringToUpper(std::string& s);
	int getRandom(int min, int max);
	int scoreWords(const std::string& s1, const std::string& s2);

	size_t m_difficulty = 0;
	size_t m_numWords = 0;
	size_t m_lengthWords = 0;
	int m_tries = 0;

	bool m_win = false;

	std::string m_answer;
	std::vector<std::string> m_words;

	WordReader m_wr;
};

