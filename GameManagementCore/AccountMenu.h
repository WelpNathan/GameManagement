#pragma once
#include "Menu.h"

class account_menu final : public menu
{
public:
	account_menu(const std::string& title, application* app);
	void output_options() override;
	bool handle_choice(char choice) override;
	bool check_password(int index, const std::string& this_username, const std::string& stored_password) const;

private:
};
