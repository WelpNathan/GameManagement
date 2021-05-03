#include "Data.h"

#include <fstream>
#include <iostream>

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
			std::string temp_index;
			std::string name;
			std::string desc;
			std::string cost_temp;
			std::string rating_temp;

			// remove index
			std::getline(filer_, temp_index);

			// set name and description
			std::getline(filer_, name);
			std::getline(filer_, desc);

			// set cost and rating
			std::getline(filer_, cost_temp);
			std::getline(filer_, rating_temp);

			// convert string to int
			const int index= std::stoi(temp_index);
			const int cost = std::stoi(cost_temp);
			const int rating = std::stoi(rating_temp);

			games.addAtEnd(new game(name, desc, cost, rating, index));
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
			std::string temp_index;
			std::string date_;
			std::string email;
			std::string password;

			// set name and description
			std::getline(filer_, temp_index);
			std::getline(filer_, date_);
			std::getline(filer_, email);
			std::getline(filer_, password);

			// TODO: use account-index
			const int index = std::stoi(temp_index);

			day_ = split_date_string_day(date_);
			month_ = split_date_string_month(date_);
			year_ = split_date_string_year(date_);
			date* this_date = new date(day_, month_, year_);

			accounts.addAtEnd(new account(email, password, this_date, index));
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
	std::string next_;

	while (std::getline(filer_, text))
	{
		std::string temp_index;
		std::string date_;
		std::string name;
		std::string password;
		std::string credit;
		
		if (text == "ACCOUNT-PLAYER")
		{
			std::getline(filer_, temp_index);
			std::getline(filer_, date_);
			std::getline(filer_, name);
			std::getline(filer_, password);
			std::getline(filer_, credit);

			const int index = std::stoi(temp_index);

			day_ = split_date_string_day(date_);
			month_ = split_date_string_month(date_);
			year_ = split_date_string_year(date_);
			auto this_date = new date(day_, month_, year_);

			//create player
			auto this_player = new player(name, password, this_date, std::stof(credit), index);

			//add library items
			List<library_item*> lib_items;
			while (next_ == "LIBRARY-ITEM")
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
				day_ = split_date_string_day(date_);
				month_ = split_date_string_month(date_);
				year_ = split_date_string_year(date_);
				auto this_date = new date(day_, month_, year_);

				lib_items.addAtEnd(new library_item(this_date, index_, time_played_));
				std::getline(filer_, next_);
			}
			//link library items to this player:
			List<library_item*> saved_lib_items = lib_items;

			for (int i = 0; i < saved_lib_items.length(); ++i)
			{
				this_player->library.addAtEnd(saved_lib_items[i]);
			}
			
			players.addAtEnd(this_player);
		}
	}
	return players;
}

int data::split_date_string_year(std::string input_date)
{
	//places 0-3 = year
	const int a = input_date[0] * 1000;
	const int b = input_date[1] * 100;
	const int c = input_date[2] * 10;
	const int d = input_date[3];

	int year_ = a + b + c + d;
	return year_;
}
int data::split_date_string_month(std::string input_date) const
{
	//places 5 and 6 = month
	const int e = input_date[5] * 10;
	const int f = input_date[6];
	int month = e + f;
	return month_;
}

int data::split_date_string_day(std::string input_date) const
{
	//places 8 and 9 = day
	const int g = input_date[8] * 10;
	const int h = input_date[9];
	int day = g + h;
	return day_;
}

std::string data::save_accounts(List<account*> accounts) const
{
	std::string final_string;
	for (int i = 0; i < accounts.length(); ++i)
	{
		const auto account = accounts[i];

		final_string += "ACCOUNT\n";
		final_string += std::to_string(account->get_id()) + "\n";
		final_string += account->get_date()->get_formatted() + "\n";
		final_string += account->get_account_name() + "\n";
		final_string += account->get_account_password() + "\n";

		for (int y = 0; y < account->users.length(); ++y)
		{
			const auto player = account->users[y];
			final_string += "ACCOUNT-PLAYER\n";
			final_string += std::to_string(player->get_id()) + "\n";
			final_string += player->get_created_date()->get_formatted() + "\n";
			final_string += player->get_username() + "\n";
			final_string += player->get_password() + "\n";
			final_string += std::to_string(player->get_credbalance()) + "\n";
		}

		// TODO: Library items
	}
	
	return final_string;
}

std::string data::save_games(List<game*> games) const
{
	std::string final_string;
	for (int i = 0; i < games.length(); ++i)
	{
		const auto game = games[i];

		final_string += "GAME\n";
		final_string += std::to_string(game->get_id()) + "\n";
		final_string += game->get_name() + "\n";
		final_string += game->get_description() + "\n";
		final_string += std::to_string(game->get_cost()) + "\n";
		final_string += std::to_string(game->get_rating()) + "\n";
	}

	return final_string;
}
