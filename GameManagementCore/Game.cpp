#include "Game.h"

#include <utility>

game::game(std::string name, std::string desc, const int cost, const int age_rating, const int id, const int likes,
           const int dislikes)
	: name_(std::move(name)), description_(std::move(desc)), cost_(cost), age_rating_(age_rating), id_(id),
	  likes_(likes), dislikes_(dislikes)
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

int game::get_likes() const
{
	return likes_;
}

int game::set_likes(const int new_val, const int likes)
{
	int* ptr = &likes_;
	*ptr = new_val;
	return likes;
}

int game::get_dislikes() const
{
	return dislikes_;
}

int game::set_dislikes(const int new_val, const int dislikes)
{
	int* ptr = &dislikes_;
	*ptr = new_val;
	return dislikes;
}

std::string game::calculate_rating(const int likes, const int dislikes) const
{
	const int total_number_of_ratings = likes + dislikes;

	float rating;

	if (total_number_of_ratings == 0)
	{
		rating = 0.00;
	}
	else { rating = (100 / total_number_of_ratings) * likes; }

	const std::string rating_temp = std::to_string(rating);

	std::string rating_ = rating_temp.substr(0, 4);

	return rating_;
}
