#include "date.h"


date::date(int day, int month, int year)
	: day_(day), month_(month), year_(year)
{
	day = day_;
	month = month_;
	year = year_;
};

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

const std::string date::get_formatted() const
{
	return std::to_string(year_) + "-" + std::to_string(month_) + "-" + std::to_string(day_);
}
