#pragma once
#include <string>

class date
{
public:
	date(int, int, int);
	//~date();

	int get_day() const;
	int get_month() const;
	int get_year() const;
	std::string get_formatted() const;

private:
	int day_;
	int month_;
	int year_;
};
