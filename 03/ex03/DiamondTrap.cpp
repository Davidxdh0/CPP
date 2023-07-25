#include "DiamondTrap.hpp"
#include "Debug.hpp"

DiamondTrap::DiamondTrap() {
	if (MESSAGE == 1)
		std::cout << "default Contructed DiamondTrap"<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
	this->_name = name;
	this->_hitpoints = FragTrap::getHitpoints();
    this->_energypoints = ScavTrap::getEnergypoints();
	this->_attackdamage = FragTrap::getAttackdamage();
	if (MESSAGE == 1)
		std::cout << "Contructed DiamondTrap named " << _name << std::endl;
		if (VALUES == 1){
		std::cout << "DiamondTrap hitpoints = " << this->_hitpoints << std::endl;
		std::cout << "DiamondTrap energy points = " << this->_energypoints << std::endl;
		std::cout << "DiamondTrap attack damage = " << this->_attackdamage << std::endl;
	}
}

DiamondTrap::~DiamondTrap( void ){
	if (MESSAGE == 1)
		std::cout << "Decontructed DiamondTrap named " << _name << std::endl;
}

void DiamondTrap::whoAmI() {
    if (MESSAGE == 1) {
        std::cout << "whoAmI: DiamondTrap is named " << _name << std::endl
                  << "whoAmI: ClapTrap    is named " << ClapTrap::_name  << std::endl;
    }
}
