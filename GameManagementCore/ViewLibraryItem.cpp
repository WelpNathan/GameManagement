#include "ViewLibraryItem.h"

view_library_item::view_library_item(const std::string& title, application* app) : menu(title, app)
{
	paint(); // required in constructor
}

void view_library_item::output_options()
{
	//const float balance = app_->get_current_user()->get_credit_balance();
	int id = app_->get_game()->get_id();
	library_item* lib = app_->match_lib_item_to_game(id);

	bool has_been_rated = lib->has_been_rated(lib->get_rating());
	char game_rating = lib->get_rating();
	std::string description = app_->get_game()->get_description();
	int age_rating = app_->get_game()->get_age_rating();
	int cost = app_->get_game()->get_cost();
	std::string rating = app_->get_game()->calculate_rating((app_->get_game()->get_likes()),
		(app_->get_game()->get_dislikes()));

	std::cout << "  " << description << "\n\n"
		<< "  Age Rating: " << age_rating << "\n"
		<< "  Cost: " << cost << "\n"
		<< "  Average Rating: " << rating << "\n\n";

	const int played_ = lib->get_played_time();
	utils::format_playing_time(played_);

	option('P', "Play this game");
	std::cout << "\n\n";
	

	if (has_been_rated == false)
	{
		option('R', "Rate this Game");
	}
	else
	{
		if (game_rating == 'L')
		{
			std::cout << "  You LIKED this game";
			option('C', "Change Rating for this game");
		}
		else if (game_rating == 'D')
		{
			std::cout << "  You DISLIKED this game";
			option('C', "Change Rating for this game");
		}
	}

}


bool view_library_item::handle_choice(char choice)
{
	int g = app_->get_game()->get_id();
	library_item* lib = app_->match_lib_item_to_game(g);
	char game_rating = lib->get_rating();

	switch (choice)
	{
		case 'P':
		{
			//play this game
			int play_time = lib->get_played_time();
			int random = utils::random_integer(0, 60);
			int new_play_time = random + play_time;

			int play_time_ = lib->set_played_time(play_time, new_play_time);
			utils::format_playing_time(play_time_);
		}
		break;
		case 'R':
		{
			//rate game
			bool has_been_rated = false;

			while (has_been_rated == false)
			{
				std::cout << "  Do you LIKE (L) or DISLIKE (D) this game? >> ";
				char reply;
				std::cin >> reply;

				if (reply == 'L')
				{
					app_->get_game()->set_likes((app_->get_game()->get_likes()) + 1, (app_->get_game()->get_likes()));
					app_->get_current_player()->library[app_->get_game()->get_id()]->set_rating(game_rating, reply);
				}
				else if (reply == 'D')
				{
					int dislikes = (app_->get_game()->get_dislikes()) + 1;
					app_->get_game()->set_dislikes((app_->get_game()->get_dislikes()) + 1,
						(app_->get_game()->get_dislikes()));
					app_->get_current_player()->library[app_->get_game()->get_id()]->set_rating(game_rating, reply);
				}
			}
		}
		break;
		case 'C':
		{
			std::cout << "  Do you LIKE (L) or DISLIKE (D) this game? >> ";
			char input;
			std::cin >> input;
			if (input == 'L' || input == 'D')
			{
				app_->get_current_player()->library[app_->get_game()->get_id()]->set_rating(game_rating, input);
			}
		}
		break;
	}
	return false;
}
