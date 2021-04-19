#pragma once

#include "Menu.h"
#include "MainMenu.h"

class login_menu final : public menu
{
public:
	login_menu(const std::string& title, application* app);
	void output_options() final;
	bool handle_choice(char choice) final;
	bool check_password(int i, std::string this_username, std::string stored_password);

private:
	
};
