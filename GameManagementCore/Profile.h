#pragma once

#include "Menu.h"

class profile final : public menu
{
public:
	profile(const std::string& title, application* app);
	void output_options() override;
	bool handle_choice(char choice) override;
	float purchase_credits(float balance, float add);
};
