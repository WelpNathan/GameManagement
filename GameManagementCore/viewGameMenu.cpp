#include "viewGameMenu.h"

viewGameMenu::viewGameMenu(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void viewGameMenu::output_options()
{
	int index = 0;
	std::string description = app_->get_store()->games[index]->get_description(); //change index
	int rating = app_->get_store()->games[index]->get_rating();
	int cost = app_->get_store()->games[index]->get_cost();

	std::cout << description << "\n\n" 
		<< "Average Rating: " << rating << "\n\n" 
		<< "Cost: " << cost;
}

bool viewGameMenu::handle_choice(char choice)
{
	return true;
}

int getindex()
{

}