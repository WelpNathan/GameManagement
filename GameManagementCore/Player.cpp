#include "Player.h"

player::player(const std::string& username, const std::string& password, const std::string& created)
	: user(username, password, created)
{
}

player::~player()
{
	// TODO: implement deconstructor cleanup
	//for (auto& i : library)
	//{
	//	delete i;
	//}
}
