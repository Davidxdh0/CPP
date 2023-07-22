#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

#define MESSAGE 1

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string	_name;
	public:
		DiamondTrap(std::string name);
		~DiamondTrap( void );
		void 	whoAmI();
		std::string getName() const ;
		using ScavTrap::attack;
};

#endif
