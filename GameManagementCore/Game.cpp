#include "Game.h"

#include <utility>

game::game(std::string name, std::string desc, const int cost, const int age_rating, const int id, int likes, int dislikes)
	: name_(std::move(name)), description_(std::move(desc)), cost_(cost), age_rating_(age_rating), id_(id), 
			rating_(rating), likes_(likes), dislikes_(dislikes)
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

float game::get_rating()
{
	return rating_;
}
int game::get_likes()
{
	return likes_;
}
int game::get_dislikes()
{
	return dislikes_;
}

float game::calculate_rating(int likes, int dislikes)
{
	int total_number_of_ratings = likes + dislikes;
	float rating = (100 / total_number_of_ratings)* likes;

	return rating;
}


