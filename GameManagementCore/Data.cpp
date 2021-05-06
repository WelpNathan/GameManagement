#include "Data.h"

#include <fstream>
#include <iostream>
#include <vector>

#include "Utils.h"

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
			std::string likes_temp;
			std::string dislikes_temp;

			// remove index
			std::getline(filer_, temp_index);

			// set name and description
			std::getline(filer_, name);
			std::getline(filer_, desc);

			// set cost and rating
			std::getline(filer_, cost_temp);
			std::getline(filer_, rating_temp);
			std::getline(filer_, likes_temp);
			std::getline(filer_, dislikes_temp);

			// convert string to int
			const int index = std::stoi(temp_index);
			const int cost = std::stoi(cost_temp);
			const int age_rating = std::stoi(rating_temp);
			const int likes = std::stoi(likes_temp);
			const int dislikes = std::stoi(dislikes_temp);

			games.addAtEnd(new game(name, desc, cost, age_rating, index, likes, dislikes));
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
			std::string main_date;
			std::string email;
			std::string password;

			// set name and description
			std::getline(filer_, temp_index);
			std::getline(filer_, main_date);
			std::getline(filer_, email);
			std::getline(filer_, password);

			// TODO: use account-index
			const int index = std::stoi(temp_index);

			day_ = split_date_string_day(main_date);
			month_ = split_date_string_month(main_date);
			year_ = split_date_string_year(main_date);
			const auto this_date = new date(day_, month_, year_);

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
	int player_count = 0;

	while (std::getline(filer_, text))
	{
		std::string temp_index;
		std::string date_;
		std::string name;
		std::string password;
		std::string credit;

		if (player_count > 0 && player_count < 5)
		{
			temp_index = text;
			while (next_ != "ACCOUNT-PLAYER")
			{
				std::getline(filer_, next_);
			}
			text = next_;
		}

		if (text == "ACCOUNT-PLAYER")
		{
			if (player_count == 0 || player_count == 3)
			{
				std::getline(filer_, temp_index);
			}
			std::getline(filer_, date_);
			std::getline(filer_, name);
			std::getline(filer_, password);
			std::getline(filer_, credit);
			std::getline(filer_, next_);

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
				std::string rating_temp;

				// set name and description
				std::getline(filer_, index);
				std::getline(filer_, date_);
				std::getline(filer_, time_played);
				std::getline(filer_, rating_temp);

				int index_ = utils::string_to_int(index);
				int time_played_ = utils::string_to_int(time_played);
				char rating_ = utils::string_to_char(rating_temp);

				day_ = split_date_string_day(date_);
				month_ = split_date_string_month(date_);
				year_ = split_date_string_year(date_);
				auto this_date = new date(day_, month_, year_);

				lib_items.addAtEnd(new library_item(this_date, index_, time_played_, rating_));
				std::getline(filer_, next_);
			}
			//link library items to this player:
			List<library_item*> saved_lib_items = lib_items;

			for (int i = 0; i < saved_lib_items.length(); ++i)
			{
				this_player->library.push_back(saved_lib_items[i]);
			}

			players.addAtEnd(this_player);
			player_count++;
		}
	}
	return players;
}

int data::split_date_string_year(std::string input_date)
{
	//places 0-3 = year
	const int a = (input_date[0] - 48) * 1000;
	const int b = (input_date[1] - 48) * 100;
	const int c = (input_date[2] - 48) * 10;
	const int d = (input_date[3] - 48);

	const int year = a + b + c + d;
	return year;
}

int data::split_date_string_month(std::string input_date)
{
	//places 5 and 6 = month
	const int e = (input_date[5] - 48) * 10;
	const int f = (input_date[6] - 48);
	const int month = e + f;
	return month;
}

int data::split_date_string_day(std::string input_date)
{
	//places 8 and 9 = day
	const int g = (input_date[8] - 48) * 10;
	const int h = (input_date[9]) - 48;
	const int day = g + h;
	return day;
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
			auto plr = dynamic_cast<player*>(account->users[y]);

			final_string += "ACCOUNT-PLAYER\n";
			final_string += std::to_string(plr->get_id()) + "\n";
			final_string += plr->get_created_date()->get_formatted() + "\n";
			final_string += plr->get_username() + "\n";
			final_string += plr->get_password() + "\n";
			final_string += std::to_string(plr->get_credit_balance()) + "\n";

			for (int z = 0; z < 4; z++)
			{
				//library items
				library_item* lib = plr->library[z];

				final_string += "LIBRARY-ITEM\n";
				final_string += std::to_string(lib->get_index()) + "\n";
				final_string += std::to_string(lib->get_played_time()) + "\n";
				final_string += lib->get_purchased_date()->get_formatted() + "\n";
				final_string += lib->get_rating();
			}
		}
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
		final_string += std::to_string(game->get_likes()) + "\n";
		final_string += std::to_string(game->get_dislikes()) + "\n";
	}

	return final_string;
}
