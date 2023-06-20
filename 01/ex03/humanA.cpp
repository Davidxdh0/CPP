#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :  weapon(weapon), name(name)
{
	this->name = name;
	this->weapon = weapon;
}

HumanA::~HumanA(void)
{
	return ; 
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
void 	HumanA::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}
void 	HumanA::setName(std::string name)
{
	this->name = name;
}
Weapon HumanA::getWeapon(void)
{
	return this->weapon;
}
std::string HumanA::getName(void)
{
	return(this->name);
}