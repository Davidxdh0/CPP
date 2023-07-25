#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

#include "Debug.hpp"

class FragTrap : public virtual ClapTrap {
	public:
		FragTrap( void );
		FragTrap(std::string name);
		FragTrap(const FragTrap& old);
		FragTrap &operator=(const FragTrap &old);
		~FragTrap( void );
		void 	highFivesGuys( void );
		void showHitpoint( void );
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int getHitpoints(void) const;
		int getAttackdamage(void) const;
};

#endif
