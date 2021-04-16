#include "AccountMenu.h"

accountMenu::accountMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}


void accountMenu::OutputOptions()
{
	//for (int i = 0; i < 1; i++) // TODO: Hardcoded, change when using List<T>
	//{
	//	std::cout << "  " << (i + 1) << ") " << "alice@shu.ac.uk" << "\n"; //TODO: change to list collection of accounts
	//}
}



bool accountMenu::HandleChoice(char choice)
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



