#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application * app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	Option('S', "Browse Store");

	if (app->IsUserLoggedIn())
	{
		Option('P', "View Profile");
		Option('L', "Logout");
	}
	else
	{
		Option('L', "Login");
	}
}

bool MainMenu::HandleChoice(char choice)
{
	switch (choice)
	{
		case 'S':
		{
			StoreMenu thisStoreMenu("STORE", app);
		} break;

		case 'L':
		{
			if (app->IsUserLoggedIn())
			{
				std::string answer = Question("Are you sure?");
				if (answer == "y" || answer == "Y")
				{
					app->LogOut();
				}
			}
			else
			{
				// Goes to Login Menu
				//accountMenu("LOGIN ACCOUNT", app);   // once more than one account...use this
				LoginMenu thisLoginMenu("LOGIN ACCOUNT", app); //use while only 1 account to list users.

			}
		} break;
		case 'P':
		{
			if (app->IsUserLoggedIn())
			{
				BlockingMessage("Not implemented, press return to continue");
				// this needs to go to a profile page - similar to StoreMenu
				// notice the if - this only works if somebody is logged in
			}
		} break;
	}

	return false;
}