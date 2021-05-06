#pragma once

#include "Menu.h"
#include "Utils.h"

class profile final : public menu
{
public:
	profile(const std::string& title, application* app);
	void output_options() override;
	bool handle_choice(char choice) override;
	float purchase_credits(float balance, float add) const;
	static date* get_date_created();
	void add_new_user();

private:
	//date* created_date;
};
