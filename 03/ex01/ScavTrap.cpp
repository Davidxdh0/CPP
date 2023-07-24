#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap() {
	setName("Default");
	setHitpoints(100);
    setEnergypoints(50);
    setAttackdamage(20);
	if (MESSAGE == 1)
		std::cout << "Default contructor ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	setName(name);
	ClapTrap::setHitpoints(100);
	setHitpoints(ClapTrap::getHitpoints());
    setEnergypoints(50);
    setAttackdamage(20);
	if (MESSAGE == 1)
		std::cout << "Contructed ScavTrap named " << this->getName() << std::endl;
	if (VALUES == 1){
		std::cout << "ScavTrap name = " << this->getName() << std::endl;
		std::cout << "ScavTrap hitpoints = " << this->getHitpoints() << std::endl;
		std::cout << "ScavTrap energy points = " << this->getEnergypoints() << std::endl;
		std::cout << "ScavTrap attack damage = " << this->getAttackdamage() << std::endl;
	}
}

ScavTrap::~ScavTrap( void ){
	if (MESSAGE == 1)
		std::cout << "Decontructed ScavTrap named " << this->getName() << std::endl;
}

void ScavTrap::guardGate( void ){
	if (MESSAGE == 1)
		std::cout << "ScavTrap " << this->getName() << " is now in Gatekeeper mode."<< std::endl;
}
