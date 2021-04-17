#include "LoginMenu.h"

login_menu::login_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}


void login_menu::output_options()
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

bool login_menu::handle_choice(const char choice)
{
	const std::string user_name_chosen = app_->accounts[0]->users[0]->get_username();

	switch (choice)
	{
	case '1':
		{
			//user 1 chosen

			std::cout << "Enter Password for " << user_name_chosen << ":";

			return true;
			//app.accounts[0]->users[1] = u2;
		}
	case '2':
		{
			//user 2 chosen
			return true;
		}
	case '3':
		{
			//user 2 chosen
			return true;
		}
	default: return false;
	}
}
