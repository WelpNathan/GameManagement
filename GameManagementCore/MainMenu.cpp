#include "MainMenu.h"

#include "LoginMenu.h"
#include "StoreMenu.h"

main_menu::main_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void main_menu::output_options()
{
	option('S', "Browse Store");

	if (app_->is_user_logged_in())
	{
		option('P', "View Profile");
		option('L', "Logout");
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
				//accountMenu thisAccountMenu("LOGIN ACCOUNT", app);
				login_menu this_login_menu("LOGIN - USER", app_);
			}
		}
		break;
	case 'P':
		{
			if (app_->is_user_logged_in())
			{
				blocking_message("Not implemented, press return to continue");
				// this needs to go to a profile page - similar to StoreMenu
				// notice the if - this only works if somebody is logged in
			}
		}
		break;
	default: ;
	}

	return false;
}
