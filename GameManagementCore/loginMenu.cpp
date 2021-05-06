#include "LoginMenu.h"

#include "MainMenu.h"

login_menu::login_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); 
}

void login_menu::output_options()
{
	for (int i = 0; i < app_->get_current_account()->users.length(); i++)
	{
		const auto user = app_->get_current_account()->users[i];
		if (user != nullptr)
		{
			const auto& username = user->get_username();
			option((i + 1), username);
		}
	}
}

bool login_menu::handle_choice(const char choice)
{
	std::string entered_password;
	switch (choice)
	{
	case '1':
	{
		const std::string this_username = app_->get_current_account()->users[0]->get_username();
		const std::string stored_password = app_->get_current_account()->users[0]->get_password();
		std::string entered_password;
		std::cout << "  Enter password for " << this_username << ": ";
		std::cin >> entered_password;
		if (utils::check_password(entered_password, stored_password) == true)
		{
			app_->login_user(0, this_username, stored_password);
			main_menu this_menu("MAIN MENU", app_);
		}

	}
	break;
	case '2':
	{
		const std::string this_username = app_->get_current_account()->users[1]->get_username();
		const std::string stored_password = app_->get_current_account()->users[1]->get_password();
		std::cout << "  Enter password for " << this_username << ": ";
		std::cin >> entered_password;
		utils::check_password(entered_password, stored_password);
		if (utils::check_password(entered_password, stored_password) == true)
		{
			app_->login_user(0, this_username, stored_password);
			main_menu this_menu("MAIN MENU", app_);
		}
	}
	break;
	case '3':
	{
		const std::string this_username = app_->get_current_account()->users[2]->get_username();
		const std::string stored_password = app_->get_current_account()->users[2]->get_password();
		std::cout << "  Enter password for " << this_username << ": ";
		std::cin >> entered_password;
		utils::check_password(entered_password, stored_password);
		if (utils::check_password(entered_password, stored_password) == true)
		{
			app_->login_user(0, this_username, stored_password);
			main_menu this_menu("MAIN MENU", app_);
		}
	}
	break;
	default:;
	}

	return false;
}


