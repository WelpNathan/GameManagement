#include "Data.h"

#include <fstream>
#include <iostream>


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
			std::string text_;

			// set name and description
			std::getline(filer_, date);
			std::getline(filer_, name);
			std::getline(filer_, password);
			std::getline(filer_, credit);
			std::getline(filer_, text_);
			if (text == "ACCOUNT-PLAYER")
			{
				//create player
				player* this_player = new player(name, password, date, std::stof(credit));

				//add library items
				List<library_item*> lib_items;
				while (text_ == "LIBRARY-ITEM")
				{
					std::string index;
					std::string date_;
					std::string time_played;

					// set name and description
					std::getline(filer_, index);
					std::getline(filer_, date_);
					std::getline(filer_, time_played);

					int index_ = utils::string_to_int(index);
					int time_played_ = utils::string_to_int(time_played);

					lib_items.addAtEnd(new library_item(date_, index_, time_played_));
					std::getline(filer_, text_);
				}
				//link library items to this player:
				List<library_item*> saved_lib_items = lib_items;

				for (int i = 0; i < saved_lib_items.length(); ++i)
				{
					auto plr = dynamic_cast<player*>(this_player);
					plr->library.addAtEnd(saved_lib_items[i]);
				}
				players.addAtEnd(this_player);
			}
			else
			{
				//create admin player
				admin* this_admin = new admin(name, password, date, std::stof(credit));

				//add library items
				List<library_item*> lib_items;
				while (text_ == "LIBRARY-ITEM")
				{
					std::string index;
					std::string date_;
					std::string time_played;

					// set name and description
					std::getline(filer_, index);
					std::getline(filer_, date_);
					std::getline(filer_, time_played);

					int index_ = utils::string_to_int(index);
					int time_played_ = utils::string_to_int(time_played);

					lib_items.addAtEnd(new library_item(date_, index_, time_played_));
					std::getline(filer_, text_);
				}
				//link library items to this player:
				List<library_item*> saved_lib_items = lib_items;

				for (int i = 0; i < saved_lib_items.length(); ++i)
				{
					auto plr = dynamic_cast<player*>(this_admin);
					plr->library.addAtEnd(saved_lib_items[i]);
				}
				players.addAtEnd(this_admin);
			}
		}
	}
	return players;
}

