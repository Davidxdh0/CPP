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
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& old);
		DiamondTrap &operator=(const DiamondTrap &old);
		~DiamondTrap( void );
		void 	whoAmI();
		using 	ScavTrap::attack;
		void showHitpoint( void );
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
