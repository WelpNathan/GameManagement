#include "Data.h"

#include <fstream>
#include <iostream>

#include "Account.h"
#include "Admin.h"
#include "Game.h"
#include "ListT.h"
#include "Player.h"

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
	filer_.clear();
	filer_.seekg(0);
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

List<account*> data::get_accounts()
{
	filer_.clear();
	filer_.seekg(0);
	List<account*> accounts;

	std::string text;
	while (std::getline(filer_, text))
	{
		if (text == "ACCOUNT")
		{
			std::string date;
			std::string email;
			std::string password;

			// set name and description
			std::getline(filer_, date);
			std::getline(filer_, email);
			std::getline(filer_, password);

			accounts.addAtEnd(new account(email, password, date));
		}
	}

	return accounts;
}

List<player*> data::get_players()
{
	filer_.clear();
	filer_.seekg(0);

	List<player*> players;

	std::string text;
	while (std::getline(filer_, text))
	{
		if (text == "ACCOUNT-PLAYER" || text == "ACCOUNT-ADMIN")
		{
			std::string date;
			std::string name;
			std::string password;
			std::string credit;

			// set name and description
			std::getline(filer_, date);
			std::getline(filer_, name);
			std::getline(filer_, password);
			std::getline(filer_, credit);

			if (text == "ACCOUNT-PLAYER")
			{
				players.addAtEnd(new player(name, password, date, std::stof(credit)));
			} else
			{
				players.addAtEnd(new admin(name, password, date, std::stof(credit)));
			}
		}
	}

	return players;
}

List<library_item*> data::get_library_items()
{
	filer_.clear();
	filer_.seekg(0);

	List<library_item*> lib_items;

	std::string text;
	while (std::getline(filer_, text))
	{
		if (text == "LIBRARY-ITEM")
		{
			std::string index;
			std::string date;
			std::string time_played;

			// set name and description
			std::getline(filer_, index);
			std::getline(filer_, date);
			std::getline(filer_, time_played);

			lib_items.addAtEnd(new library_item(date, nullptr));
		}
	}

	return lib_items;
}