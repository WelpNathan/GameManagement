#include "Player.h"

player::player(const std::string& username, const std::string& password, const std::string& created)
	: user(username, password, created)
{
}

player::~player()
{
	for (auto& i : library)
	{
		delete i;
	}
}
