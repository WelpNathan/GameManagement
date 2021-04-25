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

//string to upper
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


//recurrsive string to upper
std::string string_to_upper_rec(std::string data)
{
	size_t len = data.length();

	if (len != 0)
	{
		char thisChar = toupper(data[0]);

		std::string rest = data.substr(1);
		data[0] = thisChar;
		return data[0] + string_to_upper_rec(rest);
	}
	return data;
}
