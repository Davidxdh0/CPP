#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(std::string name){
	this->_name 		= name;
	this->_hitpoints 	= 10;
	this->_energypoints = 10;
	this->_attackdamage = 0;
	std::cout << "Contructed " << name << std::endl;
}

ClapTrap::~ClapTrap(){
	if (MESSAGE)
		std::cout << "Decontructed " << this->_name << std::endl;
}

void	ClapTrap::attack(const std::string& target){
	if (MESSAGE)
		std::cout << "attacked" << std::endl;
	this->_energypoints = this->_energypoints - 1;
	
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (MESSAGE)
		std::cout << "take damage" << std::endl;
	this->_hitpoints = this->_hitpoints - amount;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (MESSAGE)
		std::cout << "repaired" << std::endl;
	this->_hitpoints = this->_hitpoints + amount;
}