#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string &Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(const std::string &newtype)
{
	this->type = newtype;
}
