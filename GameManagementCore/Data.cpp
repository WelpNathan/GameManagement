#include "Data.h"

#include <fstream>
#include <iostream>

#include "Game.h"
#include "ListT.h"

/*
 * Data information
 * -----
 * Can be saved as:
 * - GAME
 * - ACCOUNT
 * - ACCOUNT-PLAYER
 * - ACCOUNT-ADMIN
 */

data::data()
{
	filew_.open("C:\\data\\data.txt", std::ios_base::app);
	filer_ = std::ifstream("C:\\data\\data.txt");

	if (!filew_.is_open() || !filer_.is_open())
	{
		std::cout << " Failed to open" << std::endl;
	}
}

data::~data()
{
	filew_.close();
	filer_.close();
}

List<game*> data::get_games()
{
	List<game*> games;

	std::string text;
	while (std::getline(filer_, text))
	{
		if (text == "GAME")
		{
			std::string name;
			std::string desc;
			std::string cost_temp;
			std::string rating_temp;

			// remove index
			std::getline(filer_, text);

			// set name and description
			std::getline(filer_, name);
			std::getline(filer_, desc);

			// set cost and rating
			std::getline(filer_, cost_temp);
			std::getline(filer_, rating_temp);

			// convert string to int
			const int cost = std::stoi(cost_temp);
			const int rating = std::stoi(rating_temp);

			games.addAtEnd(new game(name, desc, cost, rating));
		}
	}

	return games;
}

void data::get_accounts()
{
}
