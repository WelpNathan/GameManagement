#include "Profile.h"

profile::profile(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void profile::output_options()
{
	float balance = app_->get_current_user()->get_credbalance();
	std::cout.precision(2);
	std::cout.setf(std::ios::fixed);
	std::cout << "  Credits: " << balance;

	//purchase 1 credit
	//purchase 10 credits
	//purchase 100 credits

	//GAMES
	//list of library items

	//if admin: adminMenu


}

bool profile::handle_choice(const char choice)
{
	return false;
}