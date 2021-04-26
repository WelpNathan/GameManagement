#pragma once

#include "Menu.h"

#include <string>
#include <vector>

class store_menu final : public menu
{
public:
	store_menu(const std::string& title, application* app);
	void output_options() override;
	bool handle_choice(char choice) override;
private:
	
};
