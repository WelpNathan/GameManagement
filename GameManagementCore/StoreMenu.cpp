#include "StoreMenu.h"

#include "Utils.h"

store_menu::store_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void store_menu::output_options()
{
	if (!search_data_name_.empty())
	{
		// search by name
		int master_index = 1;
		for (int i = 0; i < app_->get_store()->games.length(); ++i)
		{
			const auto game = app_->get_store()->games[i];
			if (utils::starts_with(game->get_name(), search_data_name_))
			{
				option(master_index, game->get_name());
				master_index++;
			}
		}
		search_data_name_.clear();
	} else if (search_data_price_ >= 0)
	{
		// search by price
		int master_index = 1;
		for (int i = 0; i < app_->get_store()->games.length(); ++i)
		{
			const auto game = app_->get_store()->games[i];
			if (game->get_cost() < search_data_price_)
			{
				option(master_index, game->get_name());
				master_index++;
			}
		}
		search_data_price_ = -1;
	} else if (search_data_rating_ >= 0)
	{
		// search by rating
		int master_index = 1;
		for (int i = 0; i < app_->get_store()->games.length(); ++i)
		{
			const auto game = app_->get_store()->games[i];
			if (game->get_age_rating() < search_data_rating_)
			{
				option(master_index, game->get_name());
				master_index++;
			}
		}
		search_data_rating_ = -1;
	}
	else {
		// search by all
		const int game_size = app_->get_store()->games.length();
		for (int i = 0; i < game_size; i++)
		{
			std::string game_title = app_->get_store()->games[i]->get_name();
			const size_t len = game_title.length();
			const int likes = app_->get_store()->games[i]->get_likes();
			const int dislikes = app_->get_store()->games[i]->get_likes();
			std::string game_rating = app_->get_store()->games[i]->calculate_rating(likes, dislikes);
			std::string spaces = utils::spaces_in_menu_list(len, 15);

			std::string output = game_title + spaces + game_rating + "% Rating";

			option(i + 1, output);
		}
	}

	std::cout << "\n";
	option('N', "Search for game by name");
	option('P', "Search for game by price");
	option('R', "Search for game by rating");
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

	switch(choice)
	{
	case 'N': {
		// search by name
		const std::string answer = question("Input the title");
		search_data_name_ = answer;
		break;
	}
	case 'P': {
		// search by price
		const std::string answer = question("Input the price");
		search_data_price_ = std::stoi(answer);
		break;
	}
	case 'R': {
		// search by rating
		const std::string answer = question("Input the rating");
		search_data_rating_ = std::stoi(answer);
		break;
	}
	default: ;
	}
	
	
	return false;
}
