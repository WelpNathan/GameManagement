#include "Application.h"

#include "Admin.h"

application::application() : current_account_(get_current_account()), current_user_(nullptr), user_is_logged_in_(false)
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

bool application::login_account(const std::string& email, const std::string& password)
{
	// TODO: This currently always logs you in as the first account
	current_account_ = accounts[0];

	return true;
}

bool application::login_user(const std::string& username, const std::string& password)
{
	current_user_ = current_account_->users[0];
	log_in();
	return true;
}

void application::logout_user()

{
	current_user_ = nullptr;
	user_is_logged_in_ = false;
}

void application::log_out()
{
	user_is_logged_in_ = false;
}

void application::setup_data()
{
	store_ = new store();
	
	auto& store_games = store_->games;
	// Setup store with some games
	store_games.addInFront(new game("The Witness", "Explore a nice island and solve puzzles.", 2999, 5));
	store_games.addInFront(new game("Braid", "A time twisting puzzle game.", 499, 15));
	store_games.addInFront(new game("Factorio", "Build a complicated factory in space.", 1599, 12));
	store_games.addInFront(new game("LIMBO", "Watch out for that spider.", 299, 12));
	store_games.addInFront(new game("INSIDE", "What are those scientists even doing?!", 1299, 15));
	store_games.addInFront(new game("Portal 2", "Play around with physics. Shoot the moon.", 1999, 15));
	store_games.addInFront(new game("Half Life 3", "It's never coming out.", 5999, 18));
	store_games.addInFront(new game("NUVAVULT", "A game where 2D and 3D collide.", 299, 18));
	store_games.addInFront(new game("Path", "Draw nice shapes between 2 big dots.", 299, 15));

	// Create some users
	player* u1 = new admin("Alice", "password", "2018-06-16");
	auto* u2 = new player("Bob", "password", "2018-09-19");
	auto* u3 = new player("Charlie", "password", "2018-09-24");

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

	this->login_account("alice@shu.ac.uk", "password"); //TODO: remove this when more accounts are added.
}

void application::log_in()
{
	user_is_logged_in_ = true;
	current_account_ = accounts[0];
}
