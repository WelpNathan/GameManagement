#include "LoginMenu.h"

LoginMenu::LoginMenu(const std::string& title, Application* app) : Menu(title, app)
{
	Paint(); // required in constructor
}


void LoginMenu::OutputOptions()
{
	///int choice = userList(app->GetCurrentAccount());
	std::cout << "1) Alice" << "/n";
	std::cout << "2) Bob" << "/n";
	std::cout << "3) Charlie" << "/n";
}

//char LoginMenu::userList(account* account)
//{
	//for (int i = 0; i < 3; i++) // TODO: Hardcoded, change when using List<T>
	//{
	//	std::cout << "  " << (i + 1) << ") " << account->users[i]->get_username() << "\n";
	//}
	//return utils::GetCharFromUser();
//}

bool LoginMenu::HandleChoice(char choice)
{
	std::string userNameChosen = app->accounts[0]->users[0]->get_username(); ;

	switch (choice)
	{
		case '1':
		{
			//user 1 chosen

			std::cout << "Enter Password for " << userNameChosen << ":";

			return true;
			//app.accounts[0]->users[1] = u2;
		} break;
		case '2':
		{
			//user 2 chosen
			return true;
		} break;
		case '3':
		{
			//user 2 chosen
			return true;
		} break;
		default: return false;
	}

}