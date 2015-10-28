#pragma once

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <random>
#include <vector>

class WordReader
{
public:
	WordReader(std::string fileName);
	~WordReader();

	int getNWords(size_t n, std::vector<std::string>& words, size_t size = 5);

private:
	std::string m_fileName;
	std::ifstream m_fileReader;
};

