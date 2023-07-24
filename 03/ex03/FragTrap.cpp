#include "FragTrap.hpp"
#include "Debug.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	setName("FragTrap");
	setHitpoints(100);
    setEnergypoints(100);
    setAttackdamage(30);
	if (MESSAGE == 1)
		std::cout << "Default contructed FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_name 		= name;
	this->_hitpoints 	= 100;
	this->_energypoints = 100;
	this->_attackdamage = 30;
	if (MESSAGE == 1)
		std::cout << "Contructed FragTrap named " << name << std::endl;
	if (VALUES == 1){
		std::cout << "FragTrap name = " << FragTrap::getName() << std::endl;
		std::cout << "FragTrap hitpoints = " << FragTrap::getHitpoints() << std::endl;
		std::cout << "FragTrap energy points = " << FragTrap::getEnergypoints() << std::endl;
		std::cout << "FragTrap attack damage = " << FragTrap::getAttackdamage() << std::endl;
	}
}

FragTrap::~FragTrap( void ){
	if (MESSAGE == 1)
		std::cout << "Decontructed FragTrap named " << FragTrap::getName() << std::endl;
}

void FragTrap::highFivesGuys( void ){
	if (MESSAGE == 1)
		std::cout << "FragTrap " << getName() << " requests an high five"<< std::endl;
}
