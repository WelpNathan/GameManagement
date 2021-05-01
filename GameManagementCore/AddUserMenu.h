#pragma once
#include "Menu.h"


class add_user_menu :  public menu
{
public:
	add_user_menu(const std::string& title, application* app);
	void output_options();
	bool handle_choice(const char choice);

private:

};

