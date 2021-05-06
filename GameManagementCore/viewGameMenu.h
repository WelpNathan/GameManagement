#pragma once
#include "Menu.h"
#include "Profile.h"
#include "Application.h"
#include <string>
#include <vector>

class view_game_menu final : public menu
{
public:
	view_game_menu(const std::string& title, application* app);
	void output_options() override;
	bool handle_choice(char choice) override;

private:
	bool already_purchased();
	bool check_enough_credits(float balance, int cost);
	void purchase_game(game* thisGame, float balance, int cost);
};
