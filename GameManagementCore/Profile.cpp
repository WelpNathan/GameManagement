#include "MainMenu.h"
#include "AccountMenu.h"
#include "LoginMenu.h"
#include "StoreMenu.h"
#include "Profile.h"
#include "Menu.h"

profile::profile(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void profile::output_options()
{
	float balance = app_->get_current_user()->get_credbalance();
	std::cout.precision(2);
	std::cout.setf(std::ios::fixed);
	std::cout << "  Credits: " << balance << "\n\n";

	option('I', "Purchase 1 credit");
	option('O', "Purchase 10 credits");
	option('P', "Purchase 100 credits");


	std::cout << "\n\n" << "  GAMES" << "\n";
	//list of library items
	int len = (app_->get_current_player()->library.length())-1;

	for (int i = 0; i <= len; i++)
	{
		int index = app_->get_current_player()->library[i]->get_index();
		game* this_game = app_->set_game(index);
		std::string this_library_item_title = this_game->get_name();
		app_->get_current_player()->library[i];
		option((i + 1), this_library_item_title);
	}

	std::cout << "\n";

	if (app_->is_user_admin() == true)
	{
		std::cout << "  ADMINISTRATOR" << "\n";
		option('A', "Add new user");
		option('R', "Remove user");
		option('G', "Guest per-game access");
	}

	std::cout << "\n\n";
}

bool profile::handle_choice(const char choice)
{
	//LIBRARY OPTIONS
	if (utils::char_is_num(choice) == true)
	{
		const int index = app_->get_current_player()->library[choice - '1']->get_index();
		int game_size = app_->get_store()->games.length();
		if (index >= 0 && index < game_size)
		{
			std::string gameTitle = choice + " " + (app_->set_game(index))->get_name();
			viewGameMenu this_game(gameTitle, app_);
		}
	}
	else {
		//PURCHASE CREDITS
		switch (choice)
		{
		case 'I':
		{
			float add = 1.00;
			float balance = app_->get_current_user()->get_credbalance();
			float new_balance = purchase_credits(balance, add);
			balance = new_balance;
		}
		break;
		case 'O':
		{
			float add = 10.00;
			float balance = app_->get_current_user()->get_credbalance();
			float new_balance = purchase_credits(balance, add);
			balance = new_balance;
		}
		break;
		case 'P':
		{
			float add = 100.00;
			float balance = app_->get_current_user()->get_credbalance();
			float new_balance = purchase_credits(balance, add);
			balance = new_balance;
		}
		break;

		//ADMIN OPTIONS
		if (app_->is_user_admin() == true)
		{
		case 'A':
		{
			add_new_user();
		}
		break;
		case 'R':
		{
			//remove user
		}
		break;
		case 'G':
		{
			//guest per-game access
		}
		break;
		}
		}
	}

	return false;
}


float profile::purchase_credits(float balance, float add)
{
	std::cout << "  You have chosen to purchase " << add << " credit.";
	float new_balance = balance + add;
	float set_new = app_->get_current_user()->set_credbalance(new_balance);
	return set_new;
}

void profile::add_new_user()
{
	std::string username_;
	std::string password_;
	char answer;
	bool confirm_user = false;

	while (confirm_user == false)
	{
		std::cout << "\n" << "  Enter username for new User: ";
		std::cin >> username_;

		std::cout << "\n" << "  Enter password for new User: ";
		std::cin >> password_;

		std::cout << "\n" << "  Are you sure you want to create this new user? >>";
		std::cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			//create user;
			player* this_player = new player(username_, password_, "01-05-2021", 0.00);
			app_->get_current_account()->users.addAtEnd(this_player);
			std::cout << "  New user " << username_ << " has now been created";
			confirm_user = true;
		}
	}
}

date* profile::get_date_created()
{
	std::string date_as_string = "01-05-2021";
	int day = 1;
	int month = 5;
	int year = 2021; //TODO: ammend these values to link to todays day, month and year;

	date* todays_date = new date(day, month, year);

	return todays_date;
}