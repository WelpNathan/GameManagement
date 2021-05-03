#include "Game.h"

#include <utility>

game::game(std::string name, std::string desc, const int cost, const int rating, const int id)
	: name_(std::move(name)), description_(std::move(desc)), cost_(cost), age_rating_(rating), id_(id)
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

int game::get_rating() const
{
	return age_rating_;
}

int game::get_id() const
{
	return id_;
}


