#include "ClapTrap.hpp"

#include <iostream>

ClapTrap* ClapTrap::allClapTraps[] = { nullptr, nullptr, nullptr };

ClapTrap::ClapTrap(std::string name){
	this->_name 		= name;
	this->_hitpoints 	= 10;
	this->_energypoints = 10;
	this->_attackdamage = 0;
	std::cout << "Contructed " << name << std::endl;
}

ClapTrap::~ClapTrap(){
	if (MESSAGE == 1)
		std::cout << "Decontructed " << this->_name << std::endl;
}

void	ClapTrap::attack(const std::string& target){
	ClapTrap* goal = findTarget(target);
	if (goal != NULL){
		if (this->_energypoints > 0 && this->_hitpoints > 0){
			if (MESSAGE == 1)
				std::cout << this->_name << " has attacked " << target <<std::endl;
			this->_energypoints = this->_energypoints - _attackdamage;
			goal->setHitpoints(goal->_hitpoints - _attackdamage);
		}	
	}
	else
		std::cout << "Target doesn't exist" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (MESSAGE == 1 && _hitpoints > 0)
		std::cout << this->_name << " has taken " << amount << " damage" << std::endl;
	this->_hitpoints = this->_hitpoints - amount;
	if (this->_hitpoints <= 0){
		this->_hitpoints = 0;
		std::cout << this->_name << " is dead" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitpoints > 0 && this->_energypoints > 0){
		this->_hitpoints = this->_hitpoints + amount;
		if (MESSAGE == 1)
			std::cout << this->_name << " has been repaired for " << amount << std::endl;
	}	
}

void	ClapTrap::showHitpoint( void ){
	std::cout << this->_name << " has " << this->_hitpoints << " hitpoints" << std::endl; 
}

void ClapTrap::setHitpoints( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_hitpoints = raw;
}

int ClapTrap::getHitpoints() const {
	return this->_hitpoints;
}

void ClapTrap::addClap(ClapTrap* claptrap, int i) {
    if (i < 3)
		allClapTraps[i] = claptrap;
}

ClapTrap* ClapTrap::findTarget(const std::string& target){
	for (int i = 0; i < 3; ++i) {
		if (allClapTraps[i] && allClapTraps[i]->_name == target)
			return allClapTraps[i];
	}
	return NULL;
}
