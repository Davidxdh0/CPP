#include "DiamondTrap.hpp"
#include "Debug.hpp"

DiamondTrap::DiamondTrap() : ClapTrap() {
	ScavTrap st;
	FragTrap ft;
	_hitpoints = ft.getHitpoints();
    _energypoints = st.getEnergypoints();
	_attackdamage = ft.getAttackdamage();
	if (MESSAGE == 1)
		std::cout << "Contructed DiamondTrap Default"<< std::endl;
	if (VALUES == 1){
		std::cout << "DiamondTrap hitpoints = " 	<< this->_hitpoints << std::endl;
		std::cout << "DiamondTrap energy points = " << this->_energypoints << std::endl;
		std::cout << "DiamondTrap attack damage = " << this->_attackdamage << std::endl;
	}
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name") {
	ScavTrap st;
	FragTrap ft;
	_name = name;
	_hitpoints = ft.getHitpoints();
    _energypoints = st.getEnergypoints();
	_attackdamage = ft.getAttackdamage();
	if (MESSAGE == 1)
		std::cout << "Contructed DiamondTrap named " << _name << std::endl;
	if (VALUES == 1){
		std::cout << "DiamondTrap hitpoints = " 	<< this->_hitpoints << std::endl;
		std::cout << "DiamondTrap energy points = " << this->_energypoints << std::endl;
		std::cout << "DiamondTrap attack damage = " << this->_attackdamage << std::endl;
	}
}

DiamondTrap::DiamondTrap(const DiamondTrap& old) : ClapTrap(old), ScavTrap(old), FragTrap(old)
{
	if (MESSAGE == 1)
		std::cout << "Copy constructor DiamondTrap called" << std::endl;
	*this = old;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &old){
	if (MESSAGE == 1)
		std::cout << "Copy assignment operator DiamondTrap called" << std::endl;
	if (this != &old){
		this->_name = old._name;
		this->_hitpoints = old._hitpoints;
		this->_energypoints = old._energypoints;
		this->_attackdamage = old._attackdamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap( void ){
	if (MESSAGE == 1)
		std::cout << "Decontructed DiamondTrap named " << _name << std::endl;
}

void DiamondTrap::whoAmI() {
    if (MESSAGE == 1) {
        std::cout << "whoAmI: DiamondTrap is named " << _name << std::endl
                  << "whoAmI: ClapTrap    is named " << ClapTrap::_name  << std::endl;
    }
}

void	DiamondTrap::showHitpoint( void ){
	if (this->_hitpoints <= 0)
		this->_hitpoints = 0;
	std::cout << "DiamondTrap " << this->_name << " has " << this->_hitpoints << " hitpoints" << std::endl; 
	if (this->_energypoints < 0)
		this->_energypoints = 0;
	std::cout << "DiamondTrap " << this->_name << " has " << this->_energypoints << " energypoints" << std::endl; 
}

void	DiamondTrap::takeDamage(unsigned int amount){
	if (MESSAGE == 1 && _hitpoints > 0)
		std::cout << "DiamondTrap " << this->_name << " has taken " << amount << " damage" << std::endl;
	this->_hitpoints = this->_hitpoints - amount;
	if (this->_hitpoints <= 0){
		this->_hitpoints = 0;
		std::cout << "DiamondTrap " << this->_name << " is dead" << std::endl;
	}
}

void	DiamondTrap::beRepaired(unsigned int amount){
	if (this->_hitpoints > 0 && this->_energypoints > 0){
		this->_hitpoints = this->_hitpoints + amount;
		this->_energypoints = this->_energypoints - 1;
		if (MESSAGE == 1)
			std::cout << "DiamondTrap " << this->_name << " has been repaired for " << amount << std::endl;
	}	
}
