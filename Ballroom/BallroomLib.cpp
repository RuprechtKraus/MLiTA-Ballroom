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

unsigned long long CountNumberOfGroups(const std::string& line)
{
	unsigned long long difference{}, count{};
	std::vector<int> prefixes(5'000'000, 0);
	prefixes[0 + 2'500'001]++;

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

		count += prefixes[difference + 2'500'001];
		prefixes[difference + 2'500'001]++;
	}

	return count;
}