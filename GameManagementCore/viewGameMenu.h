#pragma once
#include "Menu.h"
#include "Profile.h"
#include <string>
#include <vector>

class viewGameMenu : public menu
{
public:
	viewGameMenu(const std::string& title, application* app);
	void output_options() override;
	bool handle_choice(char choice) override;
	int get_game_index();
	
private:
	bool already_purchased();
	bool check_enough_credits(float balance, int cost);
	void purchase_game(game* thisGame, float balance, int cost);
};

