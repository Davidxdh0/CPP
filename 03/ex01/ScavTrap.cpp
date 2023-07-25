#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	_name 		= "ScavTrap";
	_hitpoints 	= 100;
	_energypoints = 50;
	_attackdamage = 20;
	if (MESSAGE == 1)
		std::cout << "Contructed ScavTrap named " << _name << std::endl;
	if (VALUES == 1){
		std::cout << "ScavTrap name = " << _name << std::endl;
		std::cout << "ScavTrap hitpoints = " << _hitpoints << std::endl;
		std::cout << "ScavTrap energy points = " << _energypoints << std::endl;
		std::cout << "ScavTrap attack damage = " << _attackdamage << std::endl;
	}
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_name 		= name;
	_hitpoints 	= 100;
	_energypoints = 50;
	_attackdamage = 20;
	if (MESSAGE == 1)
		std::cout << "Contructed ScavTrap named " << _name << std::endl;
	if (VALUES == 1){
		std::cout << "ScavTrap name = " << _name << std::endl;
		std::cout << "ScavTrap hitpoints = " << _hitpoints << std::endl;
		std::cout << "ScavTrap energy points = " << _energypoints << std::endl;
		std::cout << "ScavTrap attack damage = " << _attackdamage << std::endl;
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
