#include "ScavTrap.hpp"
#include "Debug.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_name 		= "default";
	this->_hitpoints 	= 100;
	this->_energypoints = 50;
	this->_attackdamage = 20;
	if (MESSAGE == 1)
		std::cout << "Contructed ScavTrap named " << this->_name << std::endl;
	if (VALUES == 1){
		std::cout << "ScavTrap name = " << this->_name << std::endl;
		std::cout << "ScavTrap hitpoints = " << this->_hitpoints << std::endl;
		std::cout << "ScavTrap energy points = " << this->_energypoints << std::endl;
		std::cout << "ScavTrap attack damage = " << this->_attackdamage << std::endl;
	}
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_name 		= name;
	this->_hitpoints 	= 100;
	this->_energypoints = 50;
	this->_attackdamage = 20;
	if (MESSAGE == 1)
		std::cout << "Contructed ScavTrap named " << this->_name << std::endl;
	if (VALUES == 1){
		std::cout << "ScavTrap name = " << this->_name << std::endl;
		std::cout << "ScavTrap hitpoints = " << this->_hitpoints << std::endl;
		std::cout << "ScavTrap energy points = " << this->_energypoints << std::endl;
		std::cout << "ScavTrap attack damage = " << this->_attackdamage << std::endl;
	}
}

ScavTrap::~ScavTrap( void ){
	if (MESSAGE == 1)
		std::cout << "Decontructed ScavTrap named " << this->_name << std::endl;
}

void ScavTrap::guardGate( void ){
	if (MESSAGE == 1)
		std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode."<< std::endl;
}
