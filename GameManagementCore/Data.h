#pragma once
#include <fstream>

#include "Game.h"
#include "ListT.h"

class data
{
public:
	data();
	~data();
	List<game*> get_games();
	void get_accounts();
private:
	std::ofstream filew_;
	std::ifstream filer_;
};
