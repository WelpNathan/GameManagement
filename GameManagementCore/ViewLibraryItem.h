#pragma once
#include "Menu.h"
#include "Profile.h"
#include "Application.h"
#include <string>
#include <vector>

class view_library_item final : public menu
{
public:
	view_library_item(const std::string& title, application* app);
	void output_options() override;
	bool handle_choice(char choice) override;

private:
};

