#include "date.h"


date::date(std::string input_date, int day, int month, int year)
	: input_date_(std::move(input_date)), day_(day), month_(month), year_(year)
{
	split_date_string(input_date);

	day = day_;
	month = month_;
	year = year_;
};


int date::split_date_string(std::string input_date)
{
	//places 0-3 = year
	const int a = input_date[0] * 1000;
	const int b = input_date[1] * 100;
	const int c = input_date[2] * 10;
	const int d = input_date[3];

	int year = a + b + c + d;

	//places 5 and 6 = month

	const int e = input_date[5] * 10;
	const int f = input_date[6];
	int month = e + f;
	//places 8 and 9 = day

	const int g = input_date[8] * 10;
	const int h = input_date[9];
	int day = g + h;

	return (day, month, year);
}

const int date::get_day() const
{
	return day_;
}

const int date::get_month() const
{
	return month_;
}

const int date::get_year() const
{
	return year_;
}
