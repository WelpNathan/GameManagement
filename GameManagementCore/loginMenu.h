#pragma once

#include "Menu.h"
#include "Utils.h"

class login_menu final : public menu
{
public:
	login_menu(const std::string& title, application* app);
	void output_options() override;
	bool handle_choice(char choice) override;

private:
};
