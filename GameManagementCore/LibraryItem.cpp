#include "LibraryItem.h"

#include <utility>

library_item::library_item(date* date, int index, int play_time)
	: index_(index), purchased_(date), played_(play_time)
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
