/*#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	const int N(10);
	int count(0);
	char tmpStr[30];
	std::string str;
	std::vector <std::string> allWords;

	std::ofstream OFile("11.txt");
	for (size_t i = 0; i < N; i++)
	{
		std::cout << i;
		OFile << i;
	}

	std::ifstream IFile("voina_i_mir.txt");
	std::cout << "\n\n\n";

	while (!IFile.eof()) {
		// IFile.getline(str, 300, " ,.: \n\t");
		IFile >> tmpStr;
		allWords.push_back(tmpStr);
		count++;
		// OFile << tmpStr << "\n ";
	}
	std::cout << count << "--\n";
	std::cout << allWords[10];

	IFile.close();
	OFile.close();
}*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>

std::string cleanWord(const std::string& word) {
	std::string cleaned;
	std::locale loc("");
	for (char c : word) {
		if (std::isalpha(c, loc) || std::isdigit(c, loc)) {
			cleaned += std::tolower(c, loc);
		}
	}
	return cleaned;
}

int main() {
	// setlocale(LC_ALL, "Russian");
	std::ifstream IFile("voina_i_mir.txt", std::ios::binary);

	std::vector<std::string> words;
	std::string currentWord;
	int wordCount = 0;

	while (IFile >> currentWord) {
		std::string cleaned = cleanWord(currentWord);
		if (!cleaned.empty()) {
			words.push_back(cleaned);
			wordCount++;
		}
	}
	std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
		return a.length() > b.length();
		});

	std::ofstream OFile("result.txt");
	OFile << "Всего слов: " << wordCount << "\n";
	OFile << "Три самых длинных слова:\n";
	
	int topWords = std::min(3, static_cast<int>(words.size()));
	for (int i = 0; i < topWords; ++i) {
		OFile << i + 1 << ". " << words[i] << " (" << words[i].length() <<" букв)\n";
		// std::cout << i + 1 << ". " << words[i] << " (" << words[i].length() << " букв)" << "/n";
	}
	IFile.close();
	OFile.close();
	return 0;
}