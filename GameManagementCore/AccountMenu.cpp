#include "AccountMenu.h"
#include "loginMenu.h"
#include "Utils.h"


account_menu::account_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}


void account_menu::output_options()
{
	for (int i = 0; i < app_->accounts.length(); i++)
	{
		std::string this_account_name = app_->accounts[i]->get_account_name();
		option((i + 1), this_account_name);
	}
}

bool account_menu::handle_choice(const char choice)
{
	const int index = utils::char_to_int(choice) - 1;

	if (index >= 0)
	{
		const std::string stored_password = app_->accounts[index]->get_account_password();

		const int size = app_->accounts.length();
		if (index >= 0 && index < size)
		{
			const std::string this_username = app_->accounts[index]->get_account_name();
			check_password(index, this_username, stored_password);
		}
	}

	return false;
}


bool account_menu::check_password(const int index, const std::string& this_username,
                                  const std::string& stored_password) const
{
	std::string entered_password;
	std::cout << "  Enter password for " << this_username << ": ";
	std::cin >> entered_password;

	if (entered_password == stored_password)
	{
		app_->login_account(index, this_username, entered_password);
		login_menu this_login_menu("LOGIN - USER", app_);
		return true;
	}
	std::cout << "Password incorrect";
	return false; //invalid password
}
