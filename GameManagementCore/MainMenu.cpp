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
				//accountMenu thisAccountMenu("LOGIN ACCOUNT", app);
				LoginMenu thisLoginMenu("LOGIN - USER", app);

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