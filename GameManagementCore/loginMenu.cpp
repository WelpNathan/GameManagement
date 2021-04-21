#include "LoginMenu.h"

login_menu::login_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}


void login_menu::output_options()
{
	for (int i = 0; i < 3; i++)
	{
		std::string this_username = app_->get_current_account()->users[i]->get_username();
		option((i + 1), this_username);
	}
}

bool login_menu::handle_choice(const char choice)
{
	switch (choice)
	{
	case '1':
		{
			int i = 0;
			std::string this_username = app_->get_current_account()->users[i]->get_username();
			std::string stored_password = app_->get_current_account()->users[i]->get_password();
			check_password(i, this_username, stored_password);
		}
		break;
	case '2':
		{
			int i = 1;
			std::string this_username = app_->get_current_account()->users[i]->get_username();
			std::string stored_password = app_->get_current_account()->users[i]->get_password();
			check_password(i, this_username, stored_password);
		}
		break;
	case '3':
		{
			int i = 2;
			std::string this_username = app_->get_current_account()->users[i]->get_username();
			std::string stored_password = app_->get_current_account()->users[i]->get_password();
			check_password(i, this_username, stored_password);
		}
		break;
	default: ;
	}

	return false;
}


bool login_menu::check_password(int i, std::string this_username, std::string stored_password)
{
	int count = 0;
	std::string entered_password;

	std::cout << "  Enter password for " << this_username << ": ";
	std::cin >> entered_password;

	if (entered_password == stored_password)
	{
		app_->login_user(i, this_username, entered_password);
		app_->get_current_user();
		main_menu this_menu("MAIN MENU", app_);
		return true;
	}
	return false; //invalid password
	return false;
}
