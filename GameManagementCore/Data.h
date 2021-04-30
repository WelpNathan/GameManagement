#pragma once
#include <fstream>

#include "Account.h"
#include "Admin.h"
#include "Game.h"
#include "ListT.h"
#include "Player.h"
#include "Utils.h"


class data
{
public:
	data();
	~data();
	List<game*> get_games();
	List<account*> get_accounts();
	List<player*> get_players();
	List<library_item*> get_library_items();
private:
	std::ofstream filew_;
	std::ifstream filer_;
};
