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

std::string utils::string_to_upper(std::string data)
{
	int i = 0;

	while (data[i])
	{
		char c = data[i];
		data[i] = (toupper(c));
		i++;
	}
	return data;
}
