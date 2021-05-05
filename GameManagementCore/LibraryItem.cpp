#include "LibraryItem.h"

#include <utility>

library_item::library_item(date* date, int index, int play_time, char ind_rating)
	: index_(index), purchased_(date), played_(play_time), ind_rating_(ind_rating)
{
}

library_item::~library_item()
= default;


const int library_item::get_index() const
{
	return index_;
}

date* library_item::get_purchased_date()
{
	return purchased_;
}

const int library_item::get_played_time() const
{
	return played_;
}

char library_item::get_rating()
{
	//rating L = Like, D = dislike
	return ind_rating_;
}
char library_item::set_rating(char rating_, char new_rating)
{
	char *ptr= &rating_;
	*ptr = new_rating;
	return rating_;
}

bool library_item::has_been_rated(char rating)
{
	if (rating == 'L' || rating == 'D')
	{
		return true;
	}
	return false;
}
