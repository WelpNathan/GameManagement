#pragma once

#include <string>
#include <iomanip>

class utils
{
public:
	static std::string get_line_from_user();
	static char get_char_from_user();
	static int string_to_int(const std::string& input);
	static std::string string_to_upper(std::string data);
	static std::string string_to_upper_rec(std::string data);
	static char string_to_char(const std::string& input);
	static bool char_is_num(char c);
	static int get_current_day();
	static int get_current_month();
	static int get_current_year();
	static int char_to_int(char c);
	static std::string spaces_in_menu_list(int, int);
	static bool starts_with(const std::string&, const std::string&);
	static std::string to_lower(std::string);
	static int utils::random_integer(int a, int b);
	static void format_playing_time(int input);
};
