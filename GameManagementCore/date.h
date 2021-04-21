#pragma once
#include <string>

class date
{
public:
	date(std::string, int, int, int);
	//~date();

	const int get_day() const;
	const int get_month() const;
	const int get_year() const;

private:
	static int split_date_string(std::string input_date);
	std::string input_date_;
	int day_;
	int month_;
	int year_;
};
