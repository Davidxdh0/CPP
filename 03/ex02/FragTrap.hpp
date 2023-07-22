#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

#define MESSAGE 1

class FragTrap : public ClapTrap {
	public:
		FragTrap(std::string name);
		~FragTrap( void );
		void 	highFivesGuys( void );
};

#endif
