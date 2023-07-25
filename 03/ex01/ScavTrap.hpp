#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

#include "Debug.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap( void );
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& old);
		ScavTrap 	&operator=(const ScavTrap &old);
		~ScavTrap( void );
		void guardGate( void );
		void attack(const std::string& target);
		void showHitpoint( void );
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
