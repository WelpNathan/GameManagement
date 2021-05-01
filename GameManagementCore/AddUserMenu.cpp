#include "AddUserMenu.h"

add_user_menu::add_user_menu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void add_user_menu::output_options()
{

}

bool add_user_menu::handle_choice(const char choice)
{
	return false;
}
