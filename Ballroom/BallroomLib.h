#pragma once
#include <fstream>
#include <string>

std::string LoadStringFromFile(const std::string& fileName);

unsigned long long CountNumberOfGroups(const std::string& line);