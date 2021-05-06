#pragma once

#include "Menu.h"

#include <string>
#include "viewGameMenu.h"

class store_menu final : public menu
{
public:
	store_menu(const std::string& title, application* app);
	void output_options() override;
	bool handle_choice(char choice) override;
private:
	std::string search_data_name_;
	int search_data_price_ = -1;
	int search_data_rating_ = -1;
};
