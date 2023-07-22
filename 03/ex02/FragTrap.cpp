#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setName(name);
	setHitpoints(100);
    setEnergypoints(100);
    setAttackdamage(30);
	if (MESSAGE == 1)
		std::cout << "Contructed FragTrap named " << name << std::endl;
}

FragTrap::~FragTrap( void ){
	if (MESSAGE == 1)
		std::cout << "Decontructed FragTrap named " << getName() << std::endl;
}

void FragTrap::highFivesGuys( void ){
	if (MESSAGE == 1)
		std::cout << "FragTrap " << getName() << " requests an high five"<< std::endl;
}
