#include "LibraryItem.h"

library_item::library_item(date* date, const int index, const int play_time, const char ind_rating)
	: index_(index), purchased_(date), played_(play_time), ind_rating_(ind_rating)
{
}


int library_item::get_index() const
{
	return index_;
}

date* library_item::get_purchased_date() const
{
	return purchased_;
}

int library_item::get_played_time() const
{
	return played_;
}

char library_item::get_rating() const
{
	//rating L = Like, D = dislike
	return ind_rating_;
}

char library_item::set_rating(char rating, const char new_rating)
{
	char* ptr = &rating;
	*ptr = new_rating;
	return rating;
}

bool library_item::has_been_rated(const char rating)
{
	if (rating == 'L' || rating == 'D')
	{
		return true;
	}
	return false;
}
