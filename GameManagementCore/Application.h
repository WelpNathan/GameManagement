#pragma once

#include "Account.h"
#include "Data.h"
#include "User.h"
#include "Store.h"
#include "Admin.h"

class application
{
public:
	application();
	~application();

	bool is_account_logged_in() const;
	bool is_user_logged_in() const;
	account* get_current_account() const;
	user* get_current_user() const;
	store* get_store() const;
	player* get_current_player() const;
	game* get_game() const;
	game* set_game(int i);
	static admin* create_admin(List<player*> saved_players);
	bool login_account(int i, const std::string& email, const std::string& password);
	bool login_user(int i, int j, const std::string& username, const std::string& password);
	void logout_user();
	void logout_account();
	bool is_user_admin() const;
	void log_out();
	List<account*> accounts;
	void save() const;
	int get_game_index(game* this_game);
	void exit(bool) const;
	library_item* match_lib_item_to_game(int);

private:
	store* store_{};
	account* current_account_;
	user* current_user_;
	data* data_;
	game* game_;
	player* current_player_;
	bool user_is_logged_in_ = false;
	bool account_is_logged_in_ = false;
	void setup_data();
	int index_;
};
