#include "Game.h"

game::game(const std::string& name, const std::string& desc, const int cost, const int rating)
	: name_(name), description_(desc), cost_(cost), age_rating_(rating)
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
