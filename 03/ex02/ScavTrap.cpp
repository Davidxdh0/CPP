#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	setName(name);
	setHitpoints(100);
    setEnergypoints(50);
    setAttackdamage(20);
	if (MESSAGE == 1)
		std::cout << "Contructed ScavTrap named " << name << std::endl;
}

ScavTrap::~ScavTrap( void ){
	if (MESSAGE == 1)
		std::cout << "Decontructed ScavTrap named " << getName() << std::endl;
}

void ScavTrap::guardGate( void ){
	if (MESSAGE == 1)
		std::cout << "ScavTrap " << getName() << " is now in Gatekeeper mode."<< std::endl;
}
