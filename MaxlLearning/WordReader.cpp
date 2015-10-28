#include "WordReader.h"

WordReader::WordReader(std::string fileName) :
	m_fileName(fileName)
{
	m_fileReader = std::ifstream(fileName);
	
	if (m_fileReader.fail()) {
		std::cerr << "Can't open file " << fileName << std::endl;
	}
}

WordReader::~WordReader()
{
}

int WordReader::getNWords(size_t n, std::vector<std::string>& words, size_t size)
{
	std::string input;

	// Get all the words that have the correct length
	while (std::getline(m_fileReader, input)) {
		if (input.size() == size) {
			words.push_back(input);
		}
	}

	// Shuffle the list of words
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	auto engine = std::default_random_engine(seed);
	std::shuffle(words.begin(), words.end(), engine);

	// Only keep the first n strings
	words.erase(words.begin() + n, words.end());

	// Use return value to indicate how many string were chosen
	return words.size();
}
