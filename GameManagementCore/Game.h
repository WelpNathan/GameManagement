#pragma once

#include <string>

class game
{
public:
	game(std::string, std::string, int, int, int, int, int);
	~game();

	const std::string& get_name() const;
	const std::string& get_description() const;
	int get_cost() const;
	int get_age_rating() const;
	int get_id() const;
	int get_likes();
	int get_dislikes();
	float get_rating();
	float calculate_rating(int likes, int dislikes);

private:
	std::string name_;
	std::string description_;
	int cost_;
	int age_rating_;
	int id_;
	float rating_;
	int likes_;
	int dislikes_;
};
