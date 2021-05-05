#include "Game.h"

#include <utility>

game::game(std::string name, std::string desc, const int cost, const int age_rating, const int id, int likes, int dislikes)
	: name_(std::move(name)), description_(std::move(desc)), cost_(cost), age_rating_(age_rating), id_(id), likes_(likes), dislikes_(dislikes)
{
}

game::~game()
= default;

const std::string& game::get_name() const
{
	return name_;
}

const std::string& game::get_description() const
{
	return description_;
}

int game::get_cost() const
{
	return cost_;
}

int game::get_age_rating() const
{
	return age_rating_;
}

int game::get_id() const
{
	return id_;
}

int game::get_likes()
{
	return likes_;
}
int game::set_likes(int new_val, int likes)
{
	int* ptr = &likes_;
	*ptr = new_val;
	return likes;
}

int game::get_dislikes()
{
	return dislikes_;
}

int game::set_dislikes(int new_val, int dislikes)
{
	int* ptr = &dislikes_;
	*ptr = new_val;
	return dislikes;
}

std::string game::calculate_rating(int likes, int dislikes)
{
	int total_number_of_ratings = likes + dislikes;
	std::string rating_;
	float rating;

	if (total_number_of_ratings == 0)
	{
		rating = 0.00;
	}
	else { rating = (100 / total_number_of_ratings) * likes; }

	std::string rating_temp = std::to_string(rating);

	rating_ = rating_temp.substr(0, 4);

	return rating_;
}


