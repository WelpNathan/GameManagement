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
	const int index = choice - '1';
	int game_size = app_->get_store()->games.length();
	if (index >= 0 && index < game_size)
	{
		std::string gameTitle = choice + " " + (app_->set_game(index))->get_name();
		viewGameMenu this_game(gameTitle, app_);
	}

	return false;
}
