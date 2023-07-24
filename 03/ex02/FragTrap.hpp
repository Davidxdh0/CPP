#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

#include "Debug.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap( void );
		FragTrap(std::string name);
		~FragTrap( void );
		void 	highFivesGuys( void );
};

#endif
