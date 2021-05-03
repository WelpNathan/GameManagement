#pragma once

#include <string>

class game
{
public:
	game(std::string, std::string, int, int, int);
	~game();

	const std::string& get_name() const;
	const std::string& get_description() const;
	int get_cost() const;
	int get_rating() const;
	int get_id() const;

private:
	std::string name_;
	std::string description_;
	int cost_;
	int age_rating_;
	int id_;
};
