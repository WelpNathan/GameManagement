#pragma once
#include <string>

class date
{
public:
	date(int, int, int);
	//~date();

	const int get_day() const;
	const int get_month() const;
	const int get_year() const;

private:
	int day_;
	int month_;
	int year_;
};
