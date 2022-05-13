#pragma once
#include <fstream>
#include <string>

std::string LoadStringFromFile(const std::string& fileName);

int CountNumberOfGroups(const std::string& line);