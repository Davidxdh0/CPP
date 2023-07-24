#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_name;
	public:
		// DiamondTrap();
		DiamondTrap(std::string name);
		~DiamondTrap( void );
		void 	whoAmI();
		void	attack(std::string target);
};

#endif
