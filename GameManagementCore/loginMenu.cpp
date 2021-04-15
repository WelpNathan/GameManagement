#include "loginMenu.h"


LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}

void LoginMenu::outputUsers() {
	for (int i = 0; i < registeredUsers.size(); i++)
	{
		// adding 1 so the display is nicer for the user:
		Option(i + 1, registeredUsers[i]);
	}
}

bool LoginMenu::correctPassword(string& accountPassword, string inputPassword)
{
	//check that password matches stored value for selected user.
	if (accountPassword == inputPassword) {
		return true;
	}
	else {
		return false;
	}
	
}