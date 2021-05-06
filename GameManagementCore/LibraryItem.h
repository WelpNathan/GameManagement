#pragma once

#include "Date.h"

class library_item
{
public:
	library_item(date*, int, int, char);
	~library_item() = default;
	int get_index() const;
	date* get_purchased_date() const;
	int get_played_time() const;
	int set_played_time(int, int) const;
	int add_play_time(int);
	char get_rating() const;
	static char set_rating(char, char);
	static bool has_been_rated(char);
	int add_play_time(const int);

private:
	int index_;
	date* purchased_;
	int played_;
	char ind_rating_;
};
