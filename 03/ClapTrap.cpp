#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap(std::string name)
{
	this->_name 		= name;
	this->_hitpoints 	= 10;
	this->_energypoints = 10;
	this->_attackdamage = 0;
	std::cout << "Contructed " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Decontructed " << this->_name << std::endl;
}
