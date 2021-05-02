#pragma once
#include <fstream>

#include "Account.h"
#include "Admin.h"
#include "Game.h"
#include "ListT.h"
#include "Player.h"
#include "Utils.h"
#include "Date.h"


class data
{
public:
	data();
	~data();
	List<game*> get_games();
	List<account*> get_accounts();
	List<player*> get_players();
	int split_date_string(std::string input_date);
private:
	std::ofstream filew_;
	std::ifstream filer_;
};
