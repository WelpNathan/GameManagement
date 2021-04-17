#include "AccountMenu.h"

account_menu::account_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}


void account_menu::output_options()
{
	//for (int i = 0; i < 1; i++) // TODO: Hardcoded, change when using List<T>
	//{
	//	std::cout << "  " << (i + 1) << ") " << "alice@shu.ac.uk" << "\n"; //TODO: change to list collection of accounts
	//}
}


bool account_menu::handle_choice(char choice)
{
	//std::string username = "alice@shu.ac.uk";
	//
	//std::cout << "  Enter password:" << username << ": ";
	//if (app->LoginUser(username, utils::GetLineFromUser()))
	//{
	//	return true;
	//}

	return false;
}
