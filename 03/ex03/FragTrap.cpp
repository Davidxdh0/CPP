#include "FragTrap.hpp"
#include "Debug.hpp"

FragTrap::FragTrap( void ) : ClapTrap() {
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
	if (MESSAGE == 1)
		std::cout << "Contructed FragTrap named " << this->_name << std::endl;
	if (VALUES == 1){
		std::cout << "FragTrap hitpoints = " << this->_hitpoints << std::endl;
		std::cout << "FragTrap energy points = " << this->_energypoints << std::endl;
		std::cout << "FragTrap attack damage = " << this->_attackdamage << std::endl;
	}
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	_hitpoints = 100;
	_energypoints = 100;
	_attackdamage = 30;
	if (MESSAGE == 1)
		std::cout << "Contructed FragTrap named " << this->_name << std::endl;
	if (VALUES == 1){
		std::cout << "FragTrap name = " 		 << this->_name << std::endl;
		std::cout << "FragTrap hitpoints = "	 << this->_hitpoints << std::endl;
		std::cout << "FragTrap energy points = " << this->_energypoints << std::endl;
		std::cout << "FragTrap attack damage = " << this->_attackdamage << std::endl;
	}
}
	
FragTrap::FragTrap(const FragTrap& old) : ClapTrap(old)
{
	if (MESSAGE == 1)
		std::cout << "Copy constructor FragTrap called" << std::endl;
	*this = old;
}

FragTrap &FragTrap::operator=(const FragTrap &old){
	std::cout << "Copy assignment operator FragTrap called" << std::endl;
	if (this != &old){
		this->_name = old._name;
		this->_hitpoints = old._hitpoints;
		this->_energypoints = old._energypoints;
		this->_attackdamage = old._attackdamage;
	}
	return *this;
}

FragTrap::~FragTrap( void ){
	if (MESSAGE == 1)
		std::cout << "Decontructed FragTrap named " << this->_name << std::endl;
}

void FragTrap::highFivesGuys( void ){
	if (MESSAGE == 1)
		std::cout << "FragTrap " << this->_name << " requests an high five"<< std::endl;
}

void	FragTrap::showHitpoint( void ){
	if (this->_hitpoints <= 0)
		this->_hitpoints = 0;
	std::cout << "FragTrap " << this->_name << " has " << this->_hitpoints << " hitpoints" << std::endl; 
	if (this->_energypoints < 0)
		this->_energypoints = 0;
	std::cout << "FragTrap " << this->_name << " has " << this->_energypoints << " energypoints" << std::endl; 
}

void	FragTrap::takeDamage(unsigned int amount){
	if (MESSAGE == 1 && _hitpoints > 0)
		std::cout << "FragTrap " << this->_name << " has taken " << amount << " damage" << std::endl;
	this->_hitpoints = this->_hitpoints - amount;
	if (this->_hitpoints <= 0){
		this->_hitpoints = 0;
		std::cout << "FragTrap " << this->_name << " is dead" << std::endl;
	}
}

void	FragTrap::beRepaired(unsigned int amount){
	if (this->_hitpoints > 0 && this->_energypoints > 0){
		this->_hitpoints = this->_hitpoints + amount;
		this->_energypoints = this->_energypoints - 1;
		if (MESSAGE == 1)
			std::cout << "FragTrap " << this->_name << " has been repaired for " << amount << std::endl;
	}	
}

int FragTrap::getHitpoints(void) const{
	return _hitpoints;
}

int FragTrap::getAttackdamage(void) const{
	return _attackdamage;
}
