#include "Utils.h"
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

int utils::string_to_int(std::string input)
{
	int output = stoi(input);
	return output;
}

bool utils::char_is_num(char c)
{
	if (isdigit(c))
	{
		return true;
	}
	return false;
}

int utils::get_current_day() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int day = ltm->tm_mday;
	return day;
}
int utils::get_current_month() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int month = 1 + ltm->tm_mon;
	return month;
}
int utils::get_current_year() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int year = 1900 + ltm->tm_year;
	return year;
}

int utils::char_to_int(char c)
{
	int i = c - 48;
	return i;
}