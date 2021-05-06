#include "Utils.h"

#include <algorithm>
#include <iostream>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS

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
		const char c = data[i];
		data[i] = (toupper(c));
		i++;
	}
	return data;
}

//recurrsive string to upper
std::string utils::string_to_upper_rec(std::string data)
{
	const size_t len = data.length();

	if (len != 0)
	{
		const char this_char = toupper(data[0]);
		const std::string rest = data.substr(1);
		data[0] = this_char;
		return data[0] + string_to_upper_rec(rest);
	}
	return data;
}

int utils::string_to_int(const std::string& input)
{
	const int output = stoi(input);
	return output;
}

bool utils::char_is_num(const char c)
{
	if (isdigit(c))
	{
		return true;
	}
	return false;
}

int utils::get_current_day()
{
	time_t now = time(nullptr);
	tm* ltm = localtime(&now);
	const int day = ltm->tm_mday;
	return day;
}

int utils::get_current_month()
{
	time_t now = time(nullptr);
	tm* ltm = localtime(&now);
	const int month = 1 + ltm->tm_mon;
	return month;
}

int utils::get_current_year()
{
	time_t now = time(nullptr);
	tm* ltm = localtime(&now);
	const int year = 1900 + ltm->tm_year;
	return year;
}

int utils::char_to_int(const char c)
{
	const int i = c - 48;
	return i;
}

char utils::string_to_char(const std::string& input)
{
	const char* c = input.c_str();

	return *c;
}

std::string utils::spaces_in_menu_list(const int len, const int gap)
{
	const int num_spaces = gap - len;
	const std::string space = " ";
	std::string old_string = "-  ";
	std::string new_string;

	for (int x = 0; x <= num_spaces; x++)
	{
		new_string = old_string.insert(0, space);
	}
	return new_string;
}

bool utils::starts_with(const std::string& main, const std::string& search)
{
	const std::string new_main = to_lower(main);
	const std::string new_search = to_lower(search);
	return (new_main.rfind(new_search, 0) == 0);
}

std::string utils::to_lower(std::string data)
{
	std::transform(data.begin(), data.end(), data.begin(),
	               [](const unsigned char c) { return std::tolower(c); });
	return data;
}


int utils:: random_integer(int a, int b)
{
	int output = rand() % (b - a) + a;
	return output;
}

void utils::format_playing_time(int input)
{
	if (input < 60)
	{
		std::cout << "  Game played for : " << input << " mins" << "\n\n"; // us utils:
	}
	else if (input >= 300)
	{
		double d = (input / 60);
		int output = rint(d);
		std::cout << "  Game played for : " << output << " hours" << "\n\n"; // us utils:
	}
	else
	{
		float a = (input); 
		double d = (a / 60); 
		std::cout << std::fixed;
		std::cout << std::setprecision(1);
		std::cout << "  Game played for : " << d << " hours" << "\n\n"; // us utils:
	}
}


bool utils::check_password(std::string entered_password, std::string stored_password)
{
	if (entered_password == stored_password)
	{
		return true;
	}
	return false;
}