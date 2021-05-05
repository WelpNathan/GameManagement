#pragma once

#include "Game.h"
#include "Store.h"
#include "Date.h"

class library_item
{
public:
	library_item(date*, int, int, char);
	~library_item();
	const int get_index() const;
	date* get_purchased_date();
	const int get_played_time() const;
	char get_rating();
	char set_rating(char,char);
	bool has_been_rated(char rating);	

private:
	int index_;
	date* purchased_;
	int played_;
	char ind_rating_;
};
