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


bool application::login_account(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	current_account_ = accounts[0];
	account_is_logged_in_ = true;
	return true;
}

bool application::login_user(int i, const std::string& username, const std::string& password)
{
	current_user_ = current_account_->users[i];
	current_player_ = dynamic_cast<player*>(this->accounts[0]->users[i]);
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
	std::cout << "TODO: SAVE APPLICATION DATA.";

}

void application::setup_data()
{
	store_ = new store();
	data_ = new data();

	// add saved games from data
	List<game*> saved_games = data_->get_games();
	for (int i = 0; i < saved_games.length(); ++i)
	{
		store_->games.addInFront(saved_games[i]);
	}

	// add accounts from data
	List<account*> saved_accounts = data_->get_accounts();
	for (int i = 0; i < saved_accounts.length(); ++i)
	{
		this->accounts.addInFront(saved_accounts[i]);
	}

	// add players from data
	List<player*> saved_players = data_->get_players();
	for (int i = 0; i < saved_players.length(); ++i)
	{
		this->accounts[0]->users.addAtEnd(saved_players[i]);
	}

	// add library data
	List<library_item*> saved_lib_items = data_->get_library_items();
	for (int i = 0; i < saved_lib_items.length(); ++i)
	{
		auto plr = dynamic_cast<player*>(this->accounts[0]->users[0]);
		plr->library.addAtEnd(saved_lib_items[i]);
	}
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
