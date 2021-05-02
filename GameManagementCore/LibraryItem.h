#pragma once

#include "Game.h"
#include "Store.h"
#include "Date.h"

class library_item
{
public:
	library_item(date*, int index, int play_time);
	~library_item();
	const int get_index() const;
	date* get_purchased_date();
	const int get_played_time() const;

private:
	int index_;
	date* purchased_;
	int played_;
	

};
