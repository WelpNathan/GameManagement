#include "AccountMenu.h"
#include "loginMenu.h"


account_menu::account_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}


void account_menu::output_options()
{
	for (int i = 0; i < app_->accounts.length(); i++)
	{
		std::string this_accountname = app_->accounts[i]->get_account_name();
		option((i+1), this_accountname);
	}
}

bool account_menu::handle_choice(const char choice)
{
	const int index = choice - '1';
	std::string stored_password = app_->accounts[index]->get_account_password();

	int size = app_->accounts.length();
	if (index >= 0 && index < size)
	{
		std::string this_username = app_->accounts[0]->get_account_name();
		check_password(index, this_username, stored_password);
	}
	return false;
}


bool account_menu::check_password(int index, std::string this_username, std::string stored_password)
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
