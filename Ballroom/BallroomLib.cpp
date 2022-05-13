#include "BallroomLib.h"
#include <map>
#include <vector>

std::string LoadStringFromFile(const std::string& fileName)
{
	std::ifstream inputFile(fileName);
	std::string line{};

	if (!inputFile.is_open())
	{
		throw std::runtime_error("Unable to open file");
	}

	std::getline(inputFile, line);
	std::getline(inputFile, line);

	return line;
}

int CountNumberOfGroups(const std::string& line)
{
	int difference{}, count{};
	std::vector<int> prefixes(5'000'000, 0);
	prefixes[0 + 1'000'001]++;

	for (size_t i = 0; i < line.size(); i++)
	{
		switch (line[i])
		{
		case 'a':
			difference++;
			break;
		case 'b':
			difference--;
			break;
		default:
			throw std::runtime_error("Unexpected symbol");
			break;
		}

		count += prefixes[difference + 1'000'001];
		prefixes[difference + 1'000'001]++;
	}

	return count;
}