#pragma once
#include "Menu.h"

class account_menu final : public menu
{
	public:
		account_menu(const std::string& title, application* app);
		void output_options() final;
		bool handle_choice(char choice) final;
		bool check_password(std::string this_username, std::string stored_password);

	private:
};

