#include "viewGameMenu.h"

view_game_menu::view_game_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void view_game_menu::output_options()
{
	bool has_been_rated = false;
	char game_rating = 32;
	std::string description = app_->get_game()->get_description();
	int age_rating = app_->get_game()->get_age_rating();
	int cost = app_->get_game()->get_cost();
	std::string rating = app_->get_game()->calculate_rating((app_->get_game()->get_likes()),
	                                                        (app_->get_game()->get_dislikes()));
	int id = app_->get_game()->get_id();

	std::cout << "  " << description << "\n\n"
	<< "  Age Rating: " << age_rating << "\n"
	<< "  Cost: " << cost << "\n"
	<< "  Average Rating: " << rating << "\n";

	if (app_->is_user_logged_in())
	{
		float balance = app_->get_current_user()->get_credit_balance();
		if (already_purchased() == true)
		{
			std::cout << "- - - - - - - - - - - - - -" << "\n";
			std::cout << "  Game already purchased" << "\n\n";
			std::cout << "- - - - - - - - - - - - - -" << "\n";
			option('L', "View game in library");
			
		}
		else
		{
			if (check_enough_credits(balance, cost) == true)
			{
				std::cout << "- - - - - - - - - - - - - -" << "\n";
				option('G', "Purchase this game");
			}
			else
			{
				std::cout << "- - - - - - - - - - - - - -" << "\n";
				std::cout << "  Not enough credits" << "\n\n";
				std::cout << "- - - - - - - - - - - - - -" << "\n";
				option('P', "Purchase more credits");
			}
		}
	}
	else
	{
		std::cout << "  Login to purchase games." << "\n\n";
	}
}


bool view_game_menu::handle_choice(char choice)
{
	char game_rating = 32;

	switch (choice)
	{
	case 'L':
		{
		const std::string profile_title = (app_->get_current_user()->get_username()) +
			"'S PROFILE";
		profile this_profile(profile_title, app_);
		}
		break;
	case 'G':
		{
			game* thisGame = app_->get_game();
			int cost = app_->get_game()->get_cost();
			float balance = app_->get_current_user()->get_credit_balance();
			purchase_game(thisGame, balance, cost);
		}
		break;
	case 'P':
		{
			std::string profile_title = (app_->get_current_user()->get_username()) +
				"'S PROFILE";
			profile this_profile(profile_title, app_);
		}
		break;
	}
	return false;
}

bool view_game_menu::already_purchased()
{
	std::string this_game = app_->get_game()->get_name();

	int len = (app_->get_current_player()->library.length()) - 1;

	for (int i = 0; i <= len; i++)
	{
		int lib_index = app_->get_current_player()->library[i]->get_index();
		std::string lib_game = app_->get_store()->games[lib_index]->get_name();

		if (lib_game == this_game)
		{
			return true;
		}
	}

	return false;
}

bool view_game_menu::check_enough_credits(float balance, int cost)
{
	if (balance >= cost)
	{
		return true;
	}
	return false;
}

void view_game_menu::purchase_game(game* thisGame, float balance, int cost)
{
	int day = utils::get_current_day();
	int month = utils::get_current_month();
	int year = utils::get_current_year();
	auto today = new date(day, month, year);

	//add game to library
	int index = app_->get_game_index(thisGame);
	auto new_item = new library_item(today, index, 0, false);
	app_->get_current_player()->library.addAtEnd(new_item);

	//update balance
	float new_balance = (balance - cost);
	app_->get_current_user()->set_credit_balance(new_balance);

	//display confirmation message and option to go to profile - y/n question.
	std::cout << "  " << app_->get_game()->get_name() << " has been purchased." << "\n";
	const std::string answer = question("View game in library?");
	if (answer == "y" || answer == "Y")
	{
		std::string profile_title = (app_->get_current_user()->get_username()) +
			"'S PROFILE";
		profile this_profile(profile_title, app_);
	}
}
