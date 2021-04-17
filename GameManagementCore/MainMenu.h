#pragma once

#include "Menu.h"

class main_menu final : public menu
{
public:
	main_menu(const std::string& title, application* app);
	void output_options() final;
	bool handle_choice(char choice) final;
};
