#include "ScavTrap.hpp"
#include "Debug.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("Default", 100, 50, 20) {
	if (MESSAGE == 1)
		std::cout << "Contructed ScavTrap named " << this->_name << std::endl;
	if (VALUES == 1){
		std::cout << "ScavTrap hitpoints = " << this->_hitpoints << std::endl;
		std::cout << "ScavTrap energy points = " << this->_energypoints << std::endl;
		std::cout << "ScavTrap attack damage = " << this->_attackdamage << std::endl;
	}
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20) {
	if (MESSAGE == 1)
		std::cout << "Contructed ScavTrap named " << this->_name << std::endl;
	if (VALUES == 1){
		std::cout << "ScavTrap hitpoints = " << this->_hitpoints << std::endl;
		std::cout << "ScavTrap energy points = " << this->_energypoints << std::endl;
		std::cout << "ScavTrap attack damage = " << this->_attackdamage << std::endl;
	}
}

ScavTrap::ScavTrap(const ScavTrap& old)
{
	if (MESSAGE == 1)
		std::cout << "Copy constructor ScavTrap called" << std::endl;
	*this = old;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &old){
	std::cout << "Copy assignment operator ScavTrap called" << std::endl;
	if (this != &old){
		this->_name = old._name;
		this->_hitpoints = old._hitpoints;
		this->_energypoints = old._energypoints;
		this->_attackdamage = old._attackdamage;
	}
	return *this;
}

void	ScavTrap::attack(const std::string& target){
	if (this->_energypoints > 0 && this->_hitpoints > 0){
			std::cout << "ScavTrap "<< this->_name << " attacks "<< target <<" causing " << this->_attackdamage << " of damage." << std::endl;
		}
	if (this->_energypoints <= 0 || this->_hitpoints <= 0)
		std::cout << "ScavTrap "<< this->_name << " can't attack "<< target <<" not enough energy or hitpoints" << std::endl;
	if (this->_energypoints > 0 && this->_hitpoints > 0)
		this->_energypoints = this->_energypoints - 1;
}

ScavTrap::~ScavTrap( void ){
	if (MESSAGE == 1)
		std::cout << "Decontructed ScavTrap named " << this->_name << std::endl;
}

void ScavTrap::guardGate( void ){
	if (MESSAGE == 1)
		std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode."<< std::endl;
}

void	ScavTrap::showHitpoint( void ){
	if (this->_hitpoints <= 0)
		this->_hitpoints = 0;
	std::cout << "ScavTrap " << this->_name << " has " << this->_hitpoints << " hitpoints" << std::endl; 
	if (this->_energypoints < 0)
		this->_energypoints = 0;
	std::cout << "ScavTrap " << this->_name << " has " << this->_energypoints << " energypoints" << std::endl; 
}

void	ScavTrap::takeDamage(unsigned int amount){
	if (MESSAGE == 1 && _hitpoints > 0)
		std::cout << "ScavTrap " << this->_name << " has taken " << amount << " damage" << std::endl;
	this->_hitpoints = this->_hitpoints - amount;
	if (this->_hitpoints <= 0){
		this->_hitpoints = 0;
		std::cout << "ScavTrap " << this->_name << " is dead" << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount){
	if (this->_hitpoints > 0 && this->_energypoints > 0){
		this->_hitpoints = this->_hitpoints + amount;
		this->_energypoints = this->_energypoints - 1;
		if (MESSAGE == 1)
			std::cout << "ScavTrap " << this->_name << " has been repaired for " << amount << std::endl;
	}	
}
