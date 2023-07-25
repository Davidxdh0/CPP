#include "FragTrap.hpp"
#include "Debug.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	_name 			= "FragTrap";
	_hitpoints 		= 100;
	_energypoints	= 100;
	_attackdamage	= 30;
	if (MESSAGE == 1)
		std::cout << "Default contructed FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_name 		= name;
	this->_hitpoints 	= 100;
	this->_energypoints	= 100;
	this->_attackdamage	= 30;
	if (MESSAGE == 1)
		std::cout << "Contructed FragTrap named " << this->_name << std::endl;
	if (VALUES == 1){
		std::cout << "FragTrap name = " 		 << this->_name << std::endl;
		std::cout << "FragTrap hitpoints = "	 << this->_hitpoints << std::endl;
		std::cout << "FragTrap energy points = " << this->_energypoints << std::endl;
		std::cout << "FragTrap attack damage = " << this->_attackdamage << std::endl;
	}
}

FragTrap::~FragTrap( void ){
	if (MESSAGE == 1)
		std::cout << "Decontructed FragTrap named " << this->_name << std::endl;
}

void FragTrap::highFivesGuys( void ){
	if (MESSAGE == 1)
		std::cout << "FragTrap " << this->_name << " requests an high five"<< std::endl;
}
