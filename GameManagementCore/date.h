#pragma once
#include <string>

class date
{
public:
	int day, month, year;

	explicit date(std::string input_date);
	date();


private:
	static auto split_date_string(std::string input_date) -> int;
};
