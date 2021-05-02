#include "Admin.h"

admin::admin(const std::string& username, const std::string& password, date* created, float credit_balance)
	: player(username, password, created, credit_balance)
{
}

admin::~admin()
= default;
