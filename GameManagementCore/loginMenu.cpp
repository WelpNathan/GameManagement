#include "LoginMenu.h"

login_menu::login_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}


void login_menu::output_options()
{
	for (int i = 0; i < 3; i++) // TODO: Hardcoded, change when using List<T>
	{
		std::string this_username = app_->get_current_account()->users[i]->get_username();
		option((i+1), this_username);
	}
}

bool login_menu::handle_choice(const char choice)
{
	std::string stored_password = "password";//TODO: change to link to stored password for each player

	switch (choice) {

		case '1': // TODO: refine this process
		{
			std::string this_username = app_->get_current_account()->users[0]->get_username();
			login_menu::check_password(this_username, stored_password);		
		}
			break;
		case '2': // TODO: refine this process
		{
			std::string this_username = app_->get_current_account()->users[1]->get_username();
			login_menu::check_password(this_username, stored_password);
		}
		break;
		case '3': // TODO: refine this process
		{
			std::string this_username = app_->get_current_account()->users[2]->get_username();
			login_menu::check_password(this_username, stored_password);
		}
		break;
		default:;
	}
	
	return false;
}					


bool login_menu::check_password(std::string this_username, std::string stored_password) {
	std::string entered_password;
	std::cout << "Enter password for " << this_username << ": ";
	std::cin >> entered_password;

	if (entered_password == stored_password) {
		
		app_->login_user(this_username, entered_password);
		main_menu this_menu("MAIN MENU", app_);
		return true;
	}
	else 
	{
		std::cout << "Password incorrect";
		return false; //invalid password
	}

}