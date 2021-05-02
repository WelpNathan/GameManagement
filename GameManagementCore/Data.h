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
	int split_date_string_year(std::string input_date);
	int split_date_string_month(std::string input_date);
	int split_date_string_day(std::string input_date);

private:
	std::ofstream filew_;
	std::ifstream filer_;
	int day_;
	int month_;
	int year_;
};
