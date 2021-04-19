#include "AccountMenu.h"
#include "loginMenu.h"


account_menu::account_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}


void account_menu::output_options()
{
	std::string this_accountname = app_->accounts[0]->get_account_name();
	option((1), this_accountname);
	//for (int i = 0; i < 3; i++) // TODO: Us loop when more than one account
	//{
	//	std::string this_accountname = app_->accounts[i]->get_account_name();
		//option((i + 1), this_accountname);
	//}
}

bool account_menu::handle_choice(const char choice)
{
	std::string stored_password = "password";//TODO: change to link to stored password for each account

	switch (choice) {

	case '1': // TODO: refine this process
	{
		std::string this_username = app_->accounts[0]->get_account_name();
		check_password(this_username, stored_password);
	}

	break;
	case '2': // TODO: refine this process
	{
		std::string this_username = app_->accounts[0]->get_account_name();
		account_menu::check_password(this_username, stored_password);
	}
	break;
	default:;
	}
	return false;
}


bool account_menu::check_password(std::string this_username, std::string stored_password) {
	std::string entered_password;
	std::cout << "  Enter password for " << this_username << ": ";
	std::cin >> entered_password;

	if (entered_password == stored_password) {

		app_->login_account(this_username, entered_password);
		login_menu this_login_menu("LOGIN - USER", app_);
		return true;
	}
	else
	{
		std::cout << "Password incorrect";
		return false; //invalid password
	}
}
