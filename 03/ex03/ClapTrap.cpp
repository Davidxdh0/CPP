#include "ClapTrap.hpp"

#include <iostream>

ClapTrap* ClapTrap::allClapTraps[] = { nullptr, nullptr, nullptr };

ClapTrap::ClapTrap(void ){
	this->_name 		= "Default";
	this->_hitpoints 	= 10;
	this->_energypoints = 10;
	this->_attackdamage = 0;
	if (MESSAGE == 1)
		std::cout << "Contructed ClapTrap named " << this->_name << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hitpoints, int energypoints, int attackdamage){	
	this->_name 		= name;
	this->_hitpoints 	= hitpoints;
	this->_energypoints = energypoints;
	this->_attackdamage = attackdamage;
	if (MESSAGE == 1)
		std::cout << "Contructed ClapTrap named " << this->_name << std::endl;
	if (VALUES == 1){
		std::cout << "ClapTrap name = " << this->_name << std::endl;
		std::cout << "ClapTrap hitpoints = " << this->_hitpoints << std::endl;
		std::cout << "ClapTrap energy points = " << this->_energypoints << std::endl;
		std::cout << "ClapTrap attack damage = " << this->_attackdamage << std::endl;
	}
}

ClapTrap::ClapTrap(const ClapTrap& old)
{
	if (MESSAGE == 1)
		std::cout << "Copy constructor ClapTrap called" << std::endl;
	*this = old;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &old){
	std::cout << "Copy assignment operator ClapTrap called" << std::endl;
	if (this != &old){
		this->_name = old._name;
		this->_hitpoints = old._hitpoints;
		this->_energypoints = old._energypoints;
		this->_attackdamage = old._attackdamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	if (MESSAGE == 1)
		std::cout << "Decontructed ClapTrap named " << this->_name << std::endl;
}

void	ClapTrap::attack(const std::string& target){
	ClapTrap* goal = findTarget(target);
	if (goal != NULL){
		if (this->_energypoints > 0 && this->_hitpoints > 0){
			if (MESSAGE == 1)
				std::cout << "Claptrap "<< this->_name << " attacks "<< target <<" causing " << this->_attackdamage << " of damage." << std::endl;
			goal->setHitpoints(goal->_hitpoints - _attackdamage);
		}	
	}
	else{
		if (this->_energypoints > 0 && this->_hitpoints > 0)
			std::cout << "ClapTrap "<< this->_name << " attacks "<< target <<" causing " << this->_attackdamage << " of damage." << std::endl;
		if (this->_energypoints <= 0 || this->_hitpoints <= 0)
			std::cout << "ClapTrap "<< this->_name << " can't attack "<< target <<" not enough energy or hitpoints" << std::endl;
	}
	if (this->_energypoints > 0 && this->_hitpoints > 0)
		this->_energypoints = this->_energypoints - 1;
	
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (MESSAGE == 1 && _hitpoints > 0)
		std::cout << "ClapTrap " << this->_name << " has taken " << amount << " damage" << std::endl;
	this->_hitpoints = this->_hitpoints - amount;
	if (this->_hitpoints <= 0){
		this->_hitpoints = 0;
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_hitpoints > 0 && this->_energypoints > 0){
		this->_hitpoints = this->_hitpoints + amount;
		this->_energypoints = this->_energypoints - 1;
		if (MESSAGE == 1)
			std::cout << "ClapTrap " << this->_name << " has been repaired for " << amount << std::endl;
	}	
}

void	ClapTrap::showHitpoint( void ){
	if (this->_hitpoints <= 0)
		this->_hitpoints = 0;
	std::cout << "ClapTrap " << this->_name << " has " << this->_hitpoints << " hitpoints" << std::endl; 
	if (this->_energypoints < 0)
		this->_energypoints = 0;
	std::cout << "ClapTrap " << this->_name << " has " << this->_energypoints << " energypoints" << std::endl; 
}

void ClapTrap::setHitpoints( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_hitpoints = raw;
}

void ClapTrap::setName(const std::string& name) {
    this->_name = name;
}

void ClapTrap::setEnergypoints( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_energypoints = raw;
}
void ClapTrap::setAttackdamage( int const raw )
{
	// std::cout << "setAttackdamage member function called" << std::endl;
	this->_attackdamage = raw;
}

int ClapTrap::getHitpoints() const {
	return this->_hitpoints;
}

int ClapTrap::getEnergypoints() const {
	return this->_energypoints;
}

std::string ClapTrap::getName() const {
	return this->_name;
}

int ClapTrap::getAttackdamage() const {
	return this->_attackdamage;
}

void ClapTrap::addClap(ClapTrap* claptrap, int i) {
    if (i < 3)
	{
		allClapTraps[i] = claptrap;
		return ;
	}
	std::cout << "The array is full" << std::endl;
}

ClapTrap* ClapTrap::findTarget(const std::string& target){
	for (int i = 0; i < 3; ++i) {
		if (allClapTraps[i] && allClapTraps[i]->_name == target)
			return allClapTraps[i];
	}
	return NULL;
}
