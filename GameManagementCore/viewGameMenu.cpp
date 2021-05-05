#include "viewGameMenu.h"

viewGameMenu::viewGameMenu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void viewGameMenu::output_options()
{
	bool has_been_rated = false;
	char game_rating = 32;
	std::string description = app_->get_game()->get_description();
	int age_rating = app_->get_game()->get_age_rating();
	int cost = app_->get_game()->get_cost();
	std::string rating = app_->get_game()->calculate_rating((app_->get_game()->get_likes()), (app_->get_game()->get_dislikes()));
	int id = app_->get_game()->get_id();

	if (already_purchased() == true)
	{
		char game_rating = app_->get_current_player()->library[id]->get_rating();
		bool has_been_rated = app_->get_current_player()->library[app_->get_game()->get_id()]->has_been_rated(game_rating);
	}

	std::cout << "  " << description << "\n\n"
		<< "  Age Rating: " << age_rating << "\n"
		<< "  Cost: " << cost << "\n"
		<< "  Average Rating: " << rating <<"\n\n";


	if (app_->is_user_logged_in())
	{
		float balance = app_->get_current_user()->get_credbalance();
		if (already_purchased() == true)
		{
			std::cout << "- - - - - - - - - - - - - -" << "\n";
			std::cout << "  Game already purchased" << "\n\n";
			std::cout << "- - - - - - - - - - - - - -" << "\n";
			option('L', "View in library");
			if(has_been_rated==false)
			{
				option('R', "Rate this Game");
			}
			else
			{
				if (game_rating == 'L')
				{
					std::cout << "  You LIKED this game";
					option('C', "Change Rating for this game");
				}
				else if (game_rating =='D')
				{
					std::cout << "  You DISLIKED this game";
					option('C', "Change Rating for this game");
				}
			}
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


bool viewGameMenu::handle_choice(char choice)
{
	char game_rating = 32;
	
	if (already_purchased() == true)
	{
		char game_rating = app_->get_current_player()->library[app_->get_game()->get_id()]->get_rating();
	}
	switch (choice)
	{
	case 'L':
		{
			std::string profile_title = (app_->get_current_user()->get_username()) +
				"'S PROFILE";
			profile this_profile(profile_title, app_);
		}
		break;
	case 'G':
		{
			game* thisGame = app_->get_game();
			int cost = app_->get_game()->get_cost();
			float balance = app_->get_current_user()->get_credbalance();
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
	case 'R':
		{
			//rate game
			bool has_been_rated = false;

			while (has_been_rated == false)
			{
				std::cout << "  Do you LIKE (L) or DISLIKE (D) this game? >> ";
				char reply;
				std::cin >> reply;

				if (reply == 'L')
				{
					app_->get_game()->set_likes((app_->get_game()->get_likes())+1, (app_->get_game()->get_likes()));
					app_->get_current_player()->library[app_->get_game()->get_id()]->set_rating(game_rating, reply);
				}
				else if(reply =='D') {
					int dislikes = (app_->get_game()->get_dislikes()) + 1;
					app_->get_game()->set_dislikes((app_->get_game()->get_dislikes()) + 1, (app_->get_game()->get_dislikes()));
					app_->get_current_player()->library[app_->get_game()->get_id()]->set_rating(game_rating, reply);
				}
			}
		}
		break;
	case 'C':
	{
		std::cout << "  Do you LIKE (L) or DISLIKE (D) this game? >> ";
		char input;
		std::cin >> input;
		if (input == 'L' || input == 'D')
		{
			app_->get_current_player()->library[app_->get_game()->get_id()]->set_rating(game_rating, input);
		}
	}
		break;
	}
	return false;
}

bool viewGameMenu::already_purchased()
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

bool viewGameMenu::check_enough_credits(float balance, int cost)
{
	if (balance >= cost)
	{
		return true;
	}
	return false;
}

void viewGameMenu::purchase_game(game* thisGame, float balance, int cost)
{
	int day = utils::get_current_day();
	int month = utils::get_current_month();
	int year = utils::get_current_year();
	auto today = new date(day, month, year);

	//add game to library
	int index = app_->get_game_index(thisGame);
	auto new_item = new library_item(today, index, 0,false);
	app_->get_current_player()->library.addAtEnd(new_item);

	//update balance
	float new_balance = (balance - cost);
	app_->get_current_user()->set_credbalance(new_balance);

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
