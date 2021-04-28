#pragma once
#include "Menu.h"

#include <string>
#include <vector>

class viewGameMenu : public menu
{
public:
	viewGameMenu(const std::string& title, application* app);
	void output_options() override;
	bool handle_choice(char choice) override;
private:
};

