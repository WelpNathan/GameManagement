#include "StoreMenu.h"

store_menu::store_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void store_menu::output_options()
{
	for (int i = 0; i < games.size(); i++)
	{
		// adding 1 so the display is nicer for the user
		option(i + 1, games[i]);
	}
}

bool store_menu::handle_choice(const char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	const int index = choice - '1';

	if (index >= 0 && index < games.size())
	{
		blocking_message("Not implemented, press return to continue");
		// go to game detail page
	}

	return false;
}
