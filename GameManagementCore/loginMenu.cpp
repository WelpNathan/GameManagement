#include "LoginMenu.h"

LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}


void LoginMenu::OutputOptions()
{
	for (int i = 0; i < 3; i++) // TODO: Hardcoded, change when using List<T>
	{
		std::cout << "  " << (i + 1) << ") " << account->users[i]->GetUsername() << "\n";

		
	}

}



bool LoginMenu::HandleChoice(char choice)
{
	int index = choice - '1';

	if (index >= 0 && index < 3) // TODO: Hardcoded numbers, change when using List<T>
	{
		std::string username = app->GetCurrentAccount()->users[index]->get_username();

		std::cout << "  Enter password for " << username << ": ";
		if (app->LoginUser(username, utils::GetLineFromUser()))
		{
			
			
			/*return true;*/
		}
		return false;
	}
	
	return true;
}

//bool checkPassword(std::string& username, std::string& password, char choice) {
//	return true;
//}


