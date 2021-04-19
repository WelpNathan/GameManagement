#pragma once

#include <string>
#include <iostream>

class utils
{
public:
	static std::string get_line_from_user();
	static char get_char_from_user();

	static std::string utils::string_to_upper(std::string data);
	// TODO: 2 versions of ToUpper
};
