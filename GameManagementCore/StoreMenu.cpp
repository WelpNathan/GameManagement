#include "StoreMenu.h"

store_menu::store_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void store_menu::output_options()
{
	int game_size = app_->get_store()->games.length();
	for (int i = 0; i < game_size; i++)
	{
		std::string game_title = app_->get_store()->games[i]->get_name();
		option(i + 1, game_title);
	}
}

bool store_menu::handle_choice(const char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	const int index = choice - '1';
	int game_size = app_->get_store()->games.length();
	if (index >= 0 && index < game_size)
	{
		blocking_message("Not implemented, press return to continue");
		// go to game detail page
	}

	return false;
}
