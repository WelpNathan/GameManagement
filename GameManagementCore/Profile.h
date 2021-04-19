#pragma once

#include "Menu.h"

class profile final : public menu
{
public:
	profile(const std::string& title, application* app);
	void output_options() final;
	bool handle_choice(char choice) final;
};