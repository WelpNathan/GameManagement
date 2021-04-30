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
		

		std::string this_library_item_title = app_->get_current_player()->library[i]->get_game()->get_name();
		option((i + 1), this_library_item_title);
	}



	std::cout << "\n\n";

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

		//LIBRARY OPTIONS.


		//ADMIN OPTIONS
		if (app_->is_user_admin() == true)
		{
		case 'A':
			{
				//add new user
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

	return false;
}


float profile::purchase_credits(float balance, float add)
{
	std::cout << "  You have chosen to purchase " << add << " credit.";
	float new_balance = balance + add;
	float set_new = app_->get_current_user()->set_credbalance(new_balance);
	return set_new;
}
