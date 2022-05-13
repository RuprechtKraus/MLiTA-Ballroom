#include <fstream>
#include <iostream>
#include <random>
#include <string>

int main()
{
	std::string testName{ "ExtremeTest.txt" };
	int lineLength{ 1'000'000 };

	std::random_device r;
	std::default_random_engine el(r());
	std::uniform_int_distribution<int> uniformDist(0, 1);
	std::ofstream outputFile(testName);

	outputFile << lineLength << '\n';
	for (int i = 0; i < lineLength; i++)
	{
		if(uniformDist(el) == 0)
		{
			outputFile << 'a';
		}
		else
		{
			outputFile << 'b';
		}
	}
}