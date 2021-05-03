#pragma once

#include <string>
#include <iostream>
#include "Date.h"
#include <ctime>

class utils
{
public:
	static std::string get_line_from_user();
	static char get_char_from_user();
	static int string_to_int(std::string input);
	static std::string utils::string_to_upper(std::string data); //standard
	static std::string utils::string_to_upper_rec(std::string data); //recurrsive
	static bool char_is_num(char c);
	static int get_current_day();
	static int get_current_month();
	static int get_current_year();
	static int char_to_int(char c);
	
};
