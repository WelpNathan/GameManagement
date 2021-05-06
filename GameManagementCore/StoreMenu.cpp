#include "StoreMenu.h"

#include "Utils.h"

store_menu::store_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void store_menu::output_options()
{
	const int game_size = app_->get_store()->games.length();
	for (int i = 0; i < game_size; i++)
	{
		std::string game_title = app_->get_store()->games[i]->get_name();
		const int len = game_title.length();
		const int likes = app_->get_store()->games[i]->get_likes();
		const int dislikes = app_->get_store()->games[i]->get_likes();
		std::string game_rating = app_->get_store()->games[i]->calculate_rating(likes, dislikes);
		std::string spaces = utils::spaces_in_menu_list(len, 15);

		std::string output = game_title + spaces + game_rating + "% Rating";

		option(i + 1, output);
	}
}

bool store_menu::handle_choice(const char choice)
{
	const int index = choice - '1';
	const int game_size = app_->get_store()->games.length();
	if (index >= 0 && index < game_size)
	{
		const std::string game_title = choice + " " + (app_->set_game(index))->get_name();
		view_game_menu this_game(game_title, app_);
	}

	return false;
}
