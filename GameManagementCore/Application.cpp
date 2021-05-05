#include "Application.h"
#include <iostream>

application::application() : current_account_(get_current_account()), current_user_(get_current_user()),
                             user_is_logged_in_(false)
{
	setup_data();
}

application::~application()
{
	for (int i = 0; i < 1; ++i)
	{
		delete accounts[i];
	}
}

bool application::is_user_logged_in() const
{
	return current_user_ != nullptr;
}

bool application::is_account_logged_in() const
{
	return current_account_ != nullptr;
}

bool application::is_user_admin() const
{
	if (current_user_ == current_account_->users[0])
	{
		return true;
	}
	return false;
}

account* application::get_current_account() const
{
	return current_account_;
}

user* application::get_current_user() const
{
	return current_user_;
}

store* application::get_store() const
{
	return store_;
}

player* application::get_current_player() const
{
	return current_player_;
}


bool application::login_account(int i, const std::string& email, const std::string& password)
{
	current_account_ = accounts[i];
	account_is_logged_in_ = true;
	return true;
}

bool application::login_user(int i, int j, const std::string& username, const std::string& password)
{
	current_user_ = current_account_->users[i];
	current_player_ = dynamic_cast<player*>(this->accounts[j]->users[i]);
	user_is_logged_in_ = true;
	return true;
}

void application::logout_user()
{
	current_user_ = nullptr;
	user_is_logged_in_ = false;
}

void application::logout_account()

{
	current_account_ = nullptr;
	account_is_logged_in_ = false;
}

void application::log_out()
{
	user_is_logged_in_ = false;
}

void application::save()
{
	//save games
	std::string account_data = data_->save_accounts(this->accounts);
	

	//save account[0]
		//save player [0]
			//save library of player[0]

	
	//std::cout << "TODO: SAVE APPLICATION DATA.";

	//std::string game_data = data_->save_games(data_->get_games());

	//std::cout << "FINAL DATA.TXT FILE:\n\nACCOUNT\n\n";
	//std::cout << account_data << "\n\nGAME\n\n";
	//std::cout << game_data;
}

void application::setup_data()
{
	store_ = new store();
	data_ = new data();

	// add saved games from data
	List<game*> saved_games = data_->get_games();
	for (int i = 0; i < saved_games.length(); ++i)
	{
		store_->games.addAtEnd(saved_games[i]);
	}

	// add accounts from data
	List<account*> saved_accounts = data_->get_accounts();
	for (int i = 0; i < saved_accounts.length(); ++i)
	{
		this->accounts.addAtEnd(saved_accounts[i]);
	}

	// add players from data (with library items) and admin (with library items) into users[]
	List<player*> saved_players = data_->get_players();
	for (int i = 0; i < saved_players.length(); ++i)
	{
		if (i == 0)
		{
			admin* ad = create_admin(saved_players);
			this->accounts[saved_players[i]->get_id()]->users.addInFront(ad);
		}
		else
		{
			this->accounts[saved_players[i]->get_id()]->users.addAtEnd(saved_players[i]);
		}
	}
}

admin* application::create_admin(List<player*> saved_players)
{
	std::string password = saved_players[0]->get_password();
	std::string username = saved_players[0]->get_username();
	date* created = saved_players[0]->get_created_date();
	float credbalance = saved_players[0]->get_credbalance();

	// TODO: add index?
	auto this_admin = new admin(username, password, created, credbalance, 0);

	//add admin's library items
	List<library_item*> lib_items;
	for (int i = 0; i < (saved_players[0]->library.length()); i++)
	{
		int index = saved_players[0]->library[i]->get_index();
		int played_time = saved_players[0]->library[i]->get_played_time();
		date* purchased = saved_players[0]->library[i]->get_purchased_date();
		char rating = saved_players[0]->library[i]->get_rating();
		lib_items.addAtEnd(new library_item(purchased, index, played_time, rating));
	}
	//link library items to admin/player
	List<library_item*> saved_lib_items = lib_items;
	for (int i = 0; i < saved_lib_items.length(); ++i)
	{
		auto plr = this_admin;
		plr->library.addAtEnd(saved_lib_items[i]);
	}
	return this_admin;
}

game* application::set_game(int i)
{
	game_ = get_store()->games[i];
	return game_;
}

game* application::get_game()
{
	return game_;
}

int application::get_game_index(game* this_game)
{
	int len = this->get_store()->games.length();
	std::string this_game_name = this_game->get_name();
	index_ = 0;
	for (int i = 0; i < len; i++)
	{
		std::string store_game_name = this->get_store()->games[i]->get_name();
		if (this_game_name == store_game_name)
		{
			index_ = i;
		}
		else
		{
			index_ = 0;
		}
	}
	return index_;
}


void application::exit(bool ready_to_exit)
{
	while (ready_to_exit == true)
	{
		//save();
		//close//
	}
}