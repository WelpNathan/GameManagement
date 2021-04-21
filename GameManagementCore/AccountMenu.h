#pragma once
#include "Menu.h"

class account_menu final : public menu
{
public:
	account_menu(const std::string& title, application* app);
	void output_options();
	bool handle_choice(char choice);
	bool check_password(std::string this_username, std::string stored_password);

private:
};
