#include "DiamondTrap.hpp"
#include "Debug.hpp"

// DiamondTrap::DiamondTrap() {
// 	if (MESSAGE == 1)
// 		std::cout << "default Contructed DiamondTrap"<< std::endl;
// }

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap("ScavTrap"), FragTrap("FragTrap") {
	// ClapTrap::setName(name + "_clap_name");
	this->_name = name;
	this->_hitpoints = FragTrap::getHitpoints();
    this->_energypoints = ScavTrap::getEnergypoints();
	this->_attackdamage = FragTrap::getAttackdamage();
	if (MESSAGE == 1)
		std::cout << "Contructed DiamondTrap named " << this->getName() << std::endl;
}

DiamondTrap::~DiamondTrap( void ){
	if (MESSAGE == 1)
		std::cout << "Decontructed DiamondTrap named " << this->_name << std::endl;
}

void DiamondTrap::whoAmI() {
    if (MESSAGE == 1) {
        std::cout << "whoAmI: DiamondTrap is named " << this->_name
                  << ", ClapTrap is named " << static_cast<ClapTrap*>(this)->getName()  << std::endl;
    }
}

void DiamondTrap::attack(std::string target)
{
    ScavTrap::attack(target);
}

