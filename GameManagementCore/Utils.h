#pragma once

#include <string>
#include <iostream>

class utils
{
public:
	static std::string get_line_from_user();
	static char get_char_from_user();
	static std::string utils::string_to_upper(std::string data); //standard
	static std::string utils::string_to_upper_rec(std::string data); //recurrsive
};
