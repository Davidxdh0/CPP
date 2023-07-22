#include "DiamondTrap.hpp"

//initialize with
// Name, which is passed as parameter to a constructor
// • Hit points (FragTrap)
// • Energy points (ScavTrap)
// • Attack damage (FragTrap)
// • attack() (Scavtrap

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    _name = name;
	DiamondTrap::setHitpoints(FragTrap::getHitpoints());
    DiamondTrap::setEnergypoints(ScavTrap::getEnergypoints());
	DiamondTrap::setAttackdamage(FragTrap::getAttackdamage());
	if (MESSAGE == 1)
		std::cout << "Contructed DiamondTrap named " << name << std::endl;
}

DiamondTrap::~DiamondTrap( void ){
	if (MESSAGE == 1)
		std::cout << "Decontructed DiamondTrap named " << getName() << std::endl;
}

std::string DiamondTrap::getName() const {
	return this->_name;
}

void DiamondTrap::whoAmI( void ){
	if (MESSAGE == 1){
		// ClapTrap::setName(_name + "_clap_name");
		std::cout << "DiamondTrap is named " << getName() << std::endl << "ClapTrap is named " << ClapTrap::getName() << std::endl;
	}
}
