#include "date.h"


date::date(const int day, const int month, const int year)
	: day_(day), month_(month), year_(year)
{
};

int date::get_day() const
{
	return day_;
}

int date::get_month() const
{
	return month_;
}

int date::get_year() const
{
	return year_;
}

std::string date::get_formatted() const
{
	return std::to_string(year_) + "-" + std::to_string(month_) + "-" + std::to_string(day_);
}
