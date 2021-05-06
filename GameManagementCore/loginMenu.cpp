#include "LoginMenu.h"

#include "MainMenu.h"

login_menu::login_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); 
}

void login_menu::output_options()
{
	for (int i = 0; i < app_->get_current_account()->users.length(); i++)
	{
		const auto user = app_->get_current_account()->users[i];
		if (user != nullptr)
		{
			const auto& username = user->get_username();
			option((i + 1), username);
		}
	}
}

bool login_menu::handle_choice(const char choice)
{
	const int index = utils::char_to_int(choice) - 1;
	account* this_account = app_->get_current_account();
	int count = 0;

	while (count < 3)
	{
		if (index >= 0)
		{
			const int size = this_account->users.length();

			if (index >= 0 && index < size)
			{
				const std::string this_username = this_account->users[index]->get_username();
				const std::string stored_password = this_account->users[index]->get_password();
				
				if (check_password(this_username, stored_password) == true)
				{
					app_->login_user(index, this_username, stored_password);
					main_menu this_menu("MAIN MENU", app_);
				}
				else
				{
					count++;
					std::cout << "\n\n" << "  Password incorrect - Please Try again..." << "\n\n";
				}
			}
		}
	}
	return false;
}

bool login_menu::check_password(const std::string& this_username,
	const std::string stored_password) const
{
	std::string entered_password;
	std::cout << "  Enter password for " << this_username << ": ";
	std::cin >> entered_password;

	if (entered_password == stored_password)
	{
		return true;
	}
	return false; //invalid password
}

