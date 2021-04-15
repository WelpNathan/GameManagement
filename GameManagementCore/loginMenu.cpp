#include "LoginMenu.h"

LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}


void LoginMenu::OutputOptions()
{
	// list valid users to choose from

}



bool LoginMenu::HandleChoice(char choice)
{

	//whichever choice, ask for password...and check that it matches.
	return true;
}


