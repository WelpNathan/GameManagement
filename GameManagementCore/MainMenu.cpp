#include "MainMenu.h"
#include "AccountMenu.h"
#include "LoginMenu.h"
#include "StoreMenu.h"
#include "Profile.h"

main_menu::main_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void main_menu::output_options()
{
	option('S', "Browse Store");

	if (app_->is_user_logged_in())
	{
		std::string this_username = app_->get_current_user()->get_username();

		option('P', "View Profile for " + this_username);

		option('L', "Logout of " + this_username);
	}
	else
	{
		option('L', "Login");
	}
}

bool main_menu::handle_choice(const char choice)
{
	switch (choice)
	{
	case 'S':
		{
			store_menu this_store_menu("STORE", app_);
		}
		break;

	case 'L':
		{
			if (app_->is_user_logged_in())
			{
				const std::string answer = question("Are you sure?");
				if (answer == "y" || answer == "Y")
				{
					app_->logout_user();
				}
			}
			else
			{
				account_menu this_account_menu("LOGIN - ACCOUNT", app_);
			}
		}
		break;
	case 'P':
		{
			if (app_->is_user_logged_in())
			{
				std::string profile_title = (app_->get_current_user()->get_username()) +
					"'S PROFILE";

				profile this_profile(profile_title, app_);
			}
		}
		break;
	default: ;
	}

	return false;
}
