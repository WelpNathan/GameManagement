#include "viewGameMenu.h"

viewGameMenu::viewGameMenu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void viewGameMenu::output_options()
{
	std::string description = app_->get_game()->get_description();
	int rating = app_->get_game()->get_rating();
	int cost = app_->get_game()->get_cost();

	std::cout << "  " << description << "\n\n"
		<< "  Rating: " << rating << "\n"
		<< "  Cost: " << cost << "\n\n";

	if (app_->is_user_logged_in())
	{
		float balance = app_->get_current_user()->get_credbalance();
		if (already_purchased() == true)
		{
			std::cout << "  Game already purchased" << "\n\n";
			option('L', "View in library");
		}
			if (check_enough_credits(balance, cost) == true)
			{
				option('G', "Purchase this game");
			}
			else {
				std::cout << "  Not enough credits" << "\n\n";
				option('P', "Purchase more credits");
			}
	}
	else {
		std::cout << "  Login to purchase games." << "\n\n";
	}
}


bool viewGameMenu::handle_choice(char choice)
{


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
	}
	return false;
}

bool viewGameMenu::already_purchased()
{
	//if (game[i] exists in library[] return true)
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

void viewGameMenu::purchase_game(game* thisGame, float balance, int cost) {
	//add game to library
	
	//update balance
	float new_balance = (balance - cost);
	app_->get_current_user()->set_credbalance(new_balance);

	//display confirmation message and option to go to profile - y/n question.
	std::cout << "  "<< app_->get_game()->get_name() <<" has been purchased."<<"\n";
	const std::string answer = question("View game in library?");
	if (answer == "y" || answer == "Y")
	{
		std::string profile_title = (app_->get_current_user()->get_username()) +
			"'S PROFILE";
		profile this_profile(profile_title, app_);
	}
}


