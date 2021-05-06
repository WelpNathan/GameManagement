#pragma once

#include "Menu.h"

class login_menu final : public menu
{
public:
	login_menu(const std::string& title, application* app);
	void output_options() override;
	bool handle_choice(char choice) override;
	bool check_password(int i, int j, const std::string& this_username, std::string stored_password) const;

private:
};
