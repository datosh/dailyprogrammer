#include "HackingGame.h"

HackingGame::HackingGame(size_t difficulty) :
	m_difficulty(difficulty),
	m_wr("enable1.txt")
{
	if (m_difficulty < 1 || m_difficulty > 5) {
		std::cerr << "Only difficulties in range [1;5] are allowed" << std::endl;
	}

	m_lengthWords = MODE_LUT[difficulty - 1].len;
	m_numWords = MODE_LUT[difficulty - 1].num;
	m_tries = MODE_LUT[difficulty - 1].tries;
	m_words.reserve(m_numWords);
}

HackingGame::~HackingGame()
{
}

void HackingGame::run()
{
	init();

	for (const auto& word : m_words) {
		std::cout << word << std::endl;
	}
	
	std::string inBuffer;
	while (!m_win && m_tries != 0) {
		// Print state
		std::cout << "Guess (" << m_tries << " left)?";

		// Get user input and score
		std::getline(std::cin, inBuffer);
		stringToUpper(inBuffer);
		auto score = scoreWords(inBuffer, m_answer);

		// Print score
		std::cout << score << "/" << m_answer.size() << " correct" << std::endl;

		if (score == m_answer.size()) {
			m_win = true;
		}

		m_tries--;
	}

	if (m_win) {
		std::cout << "You win!" << std::endl;
	}
	else if (m_tries == 0) {
		std::cout << "You loose!" << std::endl;
	}
}

void HackingGame::init()
{
	// Get words and use the last one as the answer
	m_wr.getNWords(m_numWords, m_words, m_lengthWords);

	// Convert all to upper case
	for (auto& word : m_words) {
		stringToUpper(word);
	}

	// Copy answer to buffer
	m_answer = m_words[getRandom(0, m_words.size() - 1)];
}

void HackingGame::stringToUpper(std::string & s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);
}

int HackingGame::getRandom(int min, int max)
{
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 mt(seed);
	return std::uniform_int_distribution<int>(min, max)(mt);
}

int HackingGame::scoreWords(const std::string & s1, const std::string & s2)
{
	int score = 0;
	size_t len = std::min(s1.length(), s2.length());
	for (size_t i = 0; i < len; ++i) {
		if (s1[i] == s2[i]) {
			score++;
		}
	}
	return score;
}
