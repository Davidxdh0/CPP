#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB(void)
{
	return ; 
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void 	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
}
void 	HumanB::setName(std::string name)
{
	this->name = name;
}
Weapon HumanB::getWeapon(void)
{
	return(*this->weapon);
}
std::string HumanB::getName(void)
{
	return(this->name);
}