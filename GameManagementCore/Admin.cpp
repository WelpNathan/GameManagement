#include "Admin.h"

admin::admin(const std::string& username, const std::string& password, const std::string& created)
	: player(username, password, created)
{
}

admin::~admin()
{
}
