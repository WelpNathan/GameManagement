#include "Utils.h"

std::string utils::get_line_from_user()
{
	std::string input;
	std::getline(std::cin, input);
	return input;
}

char utils::get_char_from_user()
{
	return toupper(get_line_from_user()[0]);
}
