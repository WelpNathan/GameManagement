#include "Utils.h"

std::string utils::GetLineFromUser()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}

char utils::GetCharFromUser()
{
	return toupper(GetLineFromUser()[0]);
}
