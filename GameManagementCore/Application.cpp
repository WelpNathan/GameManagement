#include "Application.h"

#include <iostream>

#include "Admin.h"

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

player* application::get_current_player()
{
	return current_player_;
}

store* application::get_store() const
{
	return store_;
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
	//current_player_;
	
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

void application::setup_data()
{
	store_ = new store();
	data_ = new data();

	// get stored game memory list
	auto& store_games = store_->games;

	// loop through data.txt and add games from
	List<game*> saved_games = data_->get_games();
	for (int i = 0; i < saved_games.length(); ++i)
	{
		const auto new_game = saved_games[i];
		const std::string& name = new_game->get_name();
		const std::string& desc = new_game->get_description();
		const int cost = new_game->get_cost();
		const int rating = new_game->get_rating();
		store_games.addInFront(new game(name, desc, cost, rating));
	}

	// Create some users
	player* u1 = new admin("Alice", "password", "2018-06-16", 5.00);
	auto* u2 = new player("Bob", "password", "2018-09-19", 6.00);
	auto* u3 = new player("Charlie", "password", "2018-09-24", 7.00);

	// With some games in their library
	u1->library.addAtEnd(new library_item("2018-06-17", store_games[7]));
	u1->library.addAtEnd(new library_item("2018-06-18", store_games[1]));

	u2->library.addAtEnd(new library_item("2018-09-19", store_games[2]));
	u2->library.addAtEnd(new library_item("2018-09-19", store_games[3]));

	u3->library.addAtEnd(new library_item("2018-09-24", store_games[3]));
	u3->library.addAtEnd(new library_item("2018-09-30", store_games[6]));

	// Make an account and attach the users
	this->accounts.addInFront(new account("alice@shu.com", "password", "2018-06-16"));
	this->accounts[0]->users.addAtEnd(u1);
	this->accounts[0]->users.addAtEnd(u2);
	this->accounts[0]->users.addAtEnd(u3);
}


