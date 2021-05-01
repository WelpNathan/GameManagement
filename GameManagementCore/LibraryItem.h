#pragma once

#include "Game.h"
#include "Store.h"

class library_item
{
public:
	library_item(std::string, int index, int play_time);
	~library_item();
	const int get_index() const;
	const std::string get_purchased_date() const;
	const int get_played_time() const;

private:
	int index_;
	std::string purchased_; // TODO: replace with custom Date class, currently YYYY-MM-DD
	int played_;
	

};
